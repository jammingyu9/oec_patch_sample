#include "SignalHandler.hpp"

#include <iostream>
#include <csignal>

SignalHandler::SignalHandler(int parentPID,
                             bool startRes,
                             bool wrapUpRes,
                             bool patchReadyRes,
                             bool terminateRes)
  : ppid(parentPID),
    startResult(startRes)
    wrapUpResult(wrapUpRes),
    patchReadyResult(patchReadyRes),
    terminateResult(terminateRes)
{
    signal(SIGINT, handleSigInt);
    signal(SIGTERM, handlerSigTerm);
    signal(SIGUSR1, handlerSigUsr1);
}

void SignalHandler::handleSigInt()
{
    std::cout << "Got SIGINT" << std::endl;

    kill(ppid, wrapUpResult ? SIGUSR1 : SIGUSR2);
}

void SignalHandler::handleSigTerm()
{
    std::cout << "Got SIGTERM" << std::endl;

    kill(ppid, terminateResult ? SIGUSR1 : SIGUSR2);
}

void SignalHandler::handleSigUsr1()
{
    std::cout << "Got SIGUSR1" << std::endl;

    kill(ppid, patchReadyResult ? SIGUSR1 : SIGUSR2);
}

void SignalHandler::sendStartResult()
{
    std::cout << "Sending patch/rollback result" << std::endl;

    kill(ppid, startResult ? SIGUSR1 : SIGUSR2);
}
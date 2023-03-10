#include "SignalHandler.hpp"

#include <iostream>
#include <csignal>

int SignalHandler::ppid = 0;
bool SignalHandler::startResult = false;
bool SignalHandler::wrapUpResult = false;
bool SignalHandler::patchReadyResult = false;
bool SignalHandler::terminateResult = false;

SignalHandler::SignalHandler(int parentPID,
                             bool startRes,
                             bool wrapUpRes,
                             bool patchReadyRes,
                             bool terminateRes)
{
    SignalHandler::ppid = parentPID;
    SignalHandler::startResult = startRes,
    SignalHandler::wrapUpResult = wrapUpRes,
    SignalHandler::patchReadyResult = patchReadyRes,
    SignalHandler::terminateResult = terminateRes,
    signal(SIGINT, handleSigInt);
    signal(SIGTERM, handleSigTerm);
    signal(SIGUSR1, handleSigUsr1);
}

void SignalHandler::handleSigInt(int signum)
{
    std::cout << "Got SIGINT" << std::endl;

    kill(ppid, wrapUpResult ? SIGUSR1 : SIGUSR2);
}

void SignalHandler::handleSigTerm(int signum)
{
    std::cout << "Got SIGTERM" << std::endl;

    kill(ppid, terminateResult ? SIGUSR1 : SIGUSR2);
}

void SignalHandler::handleSigUsr1(int signum)
{
    std::cout << "Got SIGUSR1" << std::endl;

    kill(ppid, patchReadyResult ? SIGUSR1 : SIGUSR2);
}

void SignalHandler::sendStartResult()
{
    std::cout << "Sending patch/rollback result" << std::endl;

    kill(ppid, startResult ? SIGUSR1 : SIGUSR2);
}

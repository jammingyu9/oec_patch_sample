#include "SignalHandler.hpp"
#include "ConfigParser.hpp"

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    // parse config file
    std::unique_ptr<ConfigParser> cp = new ConfigParser();
    cp->parseConfig();

    // get parent pid for signal response
    pid_t ppid = getppid();
    std::cout << "Parent process ID = " << ppid << std::endl;
    
    // register handlers
    std::unique_ptr<SignalHandler> sh = new SignalHandler(ppid,
                                                          cp->startRes(),
                                                          cp->wrapUpResult(),
                                                          cp->patchReadyResult(),
                                                          cp->terminateResult());

    // send start result
    sh->sendStartResult();

    // wait for signal
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    
    cp.reset();
    sh.reset();

    return 0;
}
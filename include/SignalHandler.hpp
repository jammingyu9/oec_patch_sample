#ifndef SEMITS_SIGNAL_HANDLER_HPP
#define SEMITS_SIGNAL_HANDLER_HPP

class SignalHandler
{
public:
    SignalHandler(int ppid,
                  bool startRes,
                  bool wrapUpRes,
                  bool patchReadyRes,
                  bool terminateRes);
    virtual ~SignalHandler() {};

    static void handleSigInt(int);
    static void handleSigTerm(int);
    static void handleSigUsr1(int);
    void sendStartResult();

private:
    static int ppid;
    static bool startResult;
    static bool wrapUpResult;
    static bool patchReadyResult;
    static bool terminateResult;
};

#endif // SEMITS_SIGNAL_HANDLER_HPP

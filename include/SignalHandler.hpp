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

    void handleSigInt();
    void handleSigTerm();
    void handleSigUsr1();
    void sendStartResult();

private:
    int ppid;
    bool startResult = true;
    bool wrapUpResult = true;
    bool patchReadyResult = true;
    bool terminateResult = true;
};

#endif // SEMITS_SIGNAL_HANDLER_HPP
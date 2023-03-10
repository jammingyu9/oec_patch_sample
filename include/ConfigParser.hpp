#ifndef SEMITS_CONFIG_PARSER_HPP
#define SEMITS_CONFIG_PARSER_HPP

class ConfigParser
{
public:
    ConfigParser() {}
    ~ConfigParser() {}

    bool parseConfig();

    bool startResult() { return startRes; }
    bool wrapUpResult() { return wrapUpRes; }
    bool patchReadyResult() { return patchReadyRes; }
    bool terminateResult() { return terminateRes; }

private:
    bool startRes;
    bool wrapUpRes;
    bool patchReadyRes;
    bool terminateRes;
};

#endif // SEMITS_CONFIG_PARSER_HPP

class term
{
    bool neg;
    bool * var;
public:
    term(bool& var, bool isNeg);
    ~term();

    bool evaluate();
};
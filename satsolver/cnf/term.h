
/**
 * @brief "term". Contains reference to variables on var_table (in cnf),
 *        Evaluated based on "neg"-negate flag.
 * 
 */
class term
{
    bool neg;
    bool * var;
public:
    term(bool* var, bool isNeg);
    ~term();

    bool evaluate();
};
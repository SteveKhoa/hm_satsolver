// The most abstract class, representing a usable CNF formula.

#include "formula.h"
#include <queue>

class cnf
{
    bool * var_table;
    formula * host_formula;

    std::queue<term> termQueue;
    std::queue<clause> clauseQueue;
public:
    cnf(int numVars);
    ~cnf();

    void setVar(int var_idx, bool truth);
    bool isSAT();

    bool* ref(int var_idx);

    void makeTerm(term other);
    void buildClause();
    void buildFormula();

    void clear();
};
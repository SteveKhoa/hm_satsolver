// The most abstract class, representing a usable CNF formula.

#include "formula.h"
#include <queue>

class cnf
{
    bool * var_table;
    formula * host_formula;

    std::queue<term> termQueue;
    // queue<clause*> contains reference to allocated "clauses". 
    // DO NOT DELETE allocated "clauses" using this queue, since the "clauses" are responsible by (formula *)
    std::queue<clause*> clauseQueue;
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
// The most abstract class, representing a usable CNF formula.

#include "formula.h"
#include <queue>

class cnf
{
    bool * var_table;
    unsigned int num_vars;
    formula * host_formula;

    std::queue<term> termQueue;
    // queue<clause*> contains reference to allocated "clauses". 
    // DO NOT DELETE allocated "clauses" using this queue, since the "clauses" are responsible by (formula *)
    std::queue<clause*> clauseQueue;
public:
    cnf(int numVars);
    ~cnf();

    void setVar(int var_idx, bool truth);
    bool substitute(int var_idx, bool truth);
    bool isSAT();

    bool* ref(int var_idx);

    void makeTerm(int var_idx, bool neg);
    void buildClause();
    void buildFormula();

    int getNumVars();

    void clear();
public:
    std::queue<bool> trace_ClauseTruths();
    void backtrack_ClauseTruths(std::queue<bool>& trace);
};
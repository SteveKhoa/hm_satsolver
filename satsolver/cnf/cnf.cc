#include "cnf.h"
#include <iostream>

cnf::cnf(int numVars)
{
    var_table = new bool[numVars];
    host_formula = new formula;
}

cnf::~cnf()
{
    delete[] var_table;
    delete host_formula;
}

void cnf::setVar(int var_idx, bool truth)
{
    // Look out, var_idx might be out of the array
    // I don't check it here

    var_table[var_idx] = truth;
}

bool cnf::isSAT()
{
    return host_formula->evaluate();
}

bool* cnf::ref(int var_idx)
{
    return &var_table[var_idx];
}

void cnf::makeTerm(term other)
{
    termQueue.push(other);
}

void cnf::buildClause()
{
    clause * tmp = new clause;
    while (!termQueue.empty())
    {
        tmp->addTerm(termQueue.front());
        termQueue.pop();
    }
    clauseQueue.push(tmp);
}

void cnf::buildFormula()
{
    while (!clauseQueue.empty())
    {
        host_formula->addClause(*clauseQueue.front());
        clauseQueue.pop();
    }
}

void cnf::clear()
{
    // Not finish
    return;
}
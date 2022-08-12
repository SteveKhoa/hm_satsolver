#include "cnf.h"
#include <iostream>

cnf::cnf(int numVars)
{
    num_vars = numVars;
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

/**
 * @brief store current-state clauses' truths, used for backtracking.
 *          This method comes with backtrack_ClauseTruths()
 */
std::queue<bool> cnf::trace_ClauseTruths()
{
    std::queue<bool> trace;

    if (host_formula->head == NULL)
    {
        std::cout << "Warning: CNF currently holds NO formula.\n";
        throw std::runtime_error("cnf::trace_ClauseTruths()");
    }

    formula::node* walker = host_formula->head;
    trace.push(host_formula->head->val.lastTruthValue());

    while (walker->next != NULL)
    {
        walker = walker->next;
        trace.push(host_formula->head->val.lastTruthValue());
    }

    return trace;
}

/**
 * @brief use last-state clauses' truths, reassign back to clauses.
 *        Now, last-state clauses' truths are achieved.
 *          This method comes with trace_ClauseTruths()
 */
void cnf::backtrack_ClauseTruths(std::queue<bool>& trace)
{
    if (host_formula->head == NULL)
    {
        std::cout << "Warning: CNF currently holds NO formula.\n";
        throw std::runtime_error("cnf::trace_ClauseTruths()");
    }

    formula::node* walker = host_formula->head;
    walker->val.setLastTruthValue(trace.front());
    trace.pop();

    while (walker->next != NULL)
    {
        walker = walker->next;
        walker->val.setLastTruthValue(trace.front());
        trace.pop();
    }
}

/**
 * @brief Check if a substitution is acceptable or not.
 *        
 *        A substitution is called acceptable if:
 *          - It does not change TRUE clause to FALSE clause.
 * 
 *        Note that, if the substitution is not acceptable:
 *          - reclaim the last-state values (but lastTruthValue is not reclaimed, use backtrack_ClauseTruths())
 * 
 */
bool cnf::substitute(int var_idx, bool truth)
{
    bool last_var_value = var_table[var_idx];
    setVar(var_idx, truth);

    if (host_formula->head == NULL)
    {
        std::cout << "Warning: CNF currently holds NO formula.\n";
        return false;
    }

    formula::node* walker = host_formula->head;
    if (walker->val.lastTruthValue() == true && walker->val.evaluate() == false)
    {
        setVar(var_idx, last_var_value);
        return false;
    }
    walker->val.setLastTruthValue(walker->val.evaluate());
    
    while (walker->next != NULL)
    {
        walker = walker->next;
        if (walker->val.lastTruthValue() == true && walker->val.evaluate() == false)
        {
            setVar(var_idx, last_var_value);
            return false;
        }
        walker->val.setLastTruthValue(walker->val.evaluate());
    }

    return true;
}

bool cnf::isSAT()
{
    return host_formula->evaluate();
}

bool* cnf::ref(int var_idx)
{
    return &var_table[var_idx];
}

void cnf::makeTerm(int var_idx, bool neg)
{
    termQueue.push(term(this->ref(var_idx), neg));
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

    host_formula->evaluate();
}

int cnf::getNumVars()
{
    return num_vars;
}

void cnf::clear()
{
    // Not finish
    return;
}
#include "solver.h"

#ifndef _LIBCPP_IOSTREAM
#include <iostream>
#endif

void solver::solve()
{
    if (!trySubstitute(0))
    {
        std::cout << "The formula is not satisfiable.\n";
        return;
    }

    std::cout << "Formula solved sucessfully.\n";
    std::cout << "Truth assignments: \n";
    result();
}

/**
 * @brief recursive method. Utilize backtracking to search for possible assignments.
 * 
 */
bool solver::trySubstitute(int var_idx)
{
    // If all assignments witness no contradiction
    if (var_idx >= cnf_host->getNumVars())
    {
        return cnf_host->isSAT();
    }

    // Use two distinctive queue for each assignment: 1 or 0
    std::queue<bool> trace_clausetruths1(cnf_host->trace_ClauseTruths());
    std::queue<bool> trace_clausetruths2(cnf_host->trace_ClauseTruths());

    if (cnf_host->substitute(var_idx, 1))
    {
        // backtracking;
        if (trySubstitute(var_idx + 1))
        {
            return true;
        }
        backtrack_ClauseTruths(trace_clausetruths1);
    }

    if (cnf_host->substitute(var_idx, 0))
    {
        // backtracking;
        if (trySubstitute(var_idx + 1))
        {
            return true;
        }
        backtrack_ClauseTruths(trace_clausetruths2);
    }

    return false;
}

void solver::backtrack_ClauseTruths(std::queue<bool> &trace_clausetruths)
{
    cnf_host->backtrack_ClauseTruths(trace_clausetruths);
}

void solver::result()
{
    if (cnf_host->getNumVars() <= 0)
    {
        return;
    }

    for (int i = 0; i < cnf_host->getNumVars(); ++i)
    {
        std::cout << i << " | " << *cnf_host->ref(i) << std::endl;
    }
    std::cout << "\n";
}
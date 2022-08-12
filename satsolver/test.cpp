#include <iostream>
#include "solver.h"
#include "cnf/simpleB.h"

int main()
{
    {
        // Example of constructing a formula.

        cnf cnf_host(3);

        // Constructing var table
        cnf_host.setVar(0, 0);
        cnf_host.setVar(1, 0);
        cnf_host.setVar(2, 0);

        // Building clauses
        cnf_host.makeTerm(0, 1);
        cnf_host.makeTerm(1, 0);
        cnf_host.makeTerm(2, 1);
        cnf_host.buildClause(); // Each stop like this will build a particular clause, and add it to cnf formula

        cnf_host.makeTerm(0, 1);
        cnf_host.makeTerm(1, 0);
        cnf_host.makeTerm(2, 0);
        cnf_host.buildClause();

        cnf_host.makeTerm(0, 0);
        cnf_host.makeTerm(1, 0);
        cnf_host.makeTerm(2, 1);
        cnf_host.buildClause();

        // Build formula from set of clauses.
        cnf_host.buildFormula();

        solver sv(&cnf_host);
        sv.solve();
    }
    checkleak();
}
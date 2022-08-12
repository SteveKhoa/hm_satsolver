#include "cnf/cnf.h"

class solver
{
    cnf *cnf_host;

public:
    solver(cnf *entry_cnf)
        : cnf_host(entry_cnf)
    {
    }
    ~solver()
    {
    }

public:
    void solve();
    void result();
private:
    bool trySubstitute(int var_idx);
    void backtrack_ClauseTruths(std::queue<bool>& trace_clausetruths);
};
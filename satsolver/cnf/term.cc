#include "term.h"

term::term(bool& ref, bool isNeg)
{
    var = &ref;
    neg = isNeg;
}

term::~term()
{
}

bool term::evaluate()
{
    if (neg)
    {
        return !*var;
    }

    return *var;
}
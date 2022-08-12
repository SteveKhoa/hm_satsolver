#include "term.h"

#ifndef NULL
#define NULL 0
#endif

/**
 * @brief "Clause" is linked-list. Contains a list of terms.
 *          Evaluated based on disjunction (OR).
 * 
 */
class clause
{
    class node
    {
        term val;
        node* next;

        friend class clause;
    public:
        node(term other)
            : val(other), next(NULL) {}
        ~node()
        {
            delete next;
        }
    };

    node* head;
    bool last_truth_value;
public:
    clause();
    ~clause();

    void addTerm(term other);
    void setLastTruthValue(bool truth);
    bool lastTruthValue();

    bool evaluate();
};
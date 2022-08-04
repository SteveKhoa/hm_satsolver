#include "term.h"
#define NULL 0

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
public:
    clause();
    ~clause();

    void addTerm(term other);

    bool evaluate();
};
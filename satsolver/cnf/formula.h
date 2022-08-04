#include "clause.h"

class formula
{
    struct node
    {
        clause* val;
        node* next;

        node(clause* other)
        {
            val = other;
            next = NULL;
        }

        ~node()
        {
            delete next;
        }
    };

    node* head;
public:
    formula();
    ~formula();

    void addClause(clause* other);

    bool evaluate();
};
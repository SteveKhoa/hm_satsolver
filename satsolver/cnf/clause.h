#include "term.h"
#define NULL 0

class clause
{
    struct node
    {
        term * val;
        node* next;

        node(term* other)
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
    clause();
    ~clause();

    void addTerm(term* other);

    bool evaluate();
};
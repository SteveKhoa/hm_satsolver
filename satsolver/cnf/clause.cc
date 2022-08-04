#include "clause.h"
#define NULL 0

clause::clause()
{
    head = NULL;
}

clause::~clause()
{
    delete head;
}

void clause::addTerm(term other)
{
    if (head == NULL)
    {
        head = new node(other);
        return;
    }

    node *walker = head;
    if (walker->next == NULL)
    {
        walker->next = new node(other);
        return;
    }

    while (walker->next != NULL)
    {
        walker = walker->next;
    }
    walker->next = new node(other);
}

bool clause::evaluate()
{
    if (head == NULL)
        return false;

    node *walker = head;
    if (walker->val.evaluate() == true)
    {
        return true;
    }

    while (walker->next != NULL)
    {
        walker = walker->next;
        if (walker->val.evaluate() == true)
        {
            return true;
        }
    }

    return false;
}
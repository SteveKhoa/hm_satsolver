#include "clause.h"
#define NULL 0

clause::clause()
{
    last_truth_value = false;
    head = NULL;
}

clause::~clause()
{
    delete head;
}

/**
 * @brief add a new term (as a node) to 'clause' linked list.
 * 
 */
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

void clause::setLastTruthValue(bool truth)
{
    last_truth_value = truth;
}

bool clause::lastTruthValue()
{
    return last_truth_value;
}

/**
 * @brief evaluate the truth of clause, clause use OR in each of them.
 */
bool clause::evaluate()
{
    if (head == NULL)
    {
        return false;
    }

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
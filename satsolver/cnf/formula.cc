#include "formula.h"

formula::formula()
{
    head = NULL;
}

formula::~formula()
{
    delete head;
}

void formula::addClause(clause& other)
{
    if (head == NULL)
    {
        head = new node(other);
        return;
    }
    
    node* walker = head;
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

/**
 * @brief evaluate truth of formula (set clauses). Use AND.
 */
bool formula::evaluate()
{
    if (head == NULL)
        return false;

    node* walker = head;
    if (walker->val.evaluate() == false)
        return false;
    
    while (walker->next != NULL)
    {
        walker = walker->next;
        if (walker->val.evaluate() == false)
            return false;
    }

    return true;
}
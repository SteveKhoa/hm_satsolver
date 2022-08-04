#include "clause.h"

/**
 * @brief "formula" is linked-list. Contains list of clauses.
 *          Evaluated based on conjunction (AND).
 * 
 */
class formula
{
    class node
    {
        clause& val;
        node* next;
        friend class formula;

    public:
        node(clause& other)
            : val(other), next(NULL) {}

        ~node()
        {
            delete &val;
            delete next;
        }
    };

    node* head;
public:
    formula();
    ~formula();

    void addClause(clause& other);

    bool evaluate();
};
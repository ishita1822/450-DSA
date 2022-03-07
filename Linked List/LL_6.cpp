// Method 1
// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node *curr = head;

    if (!head)
        return NULL;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}
// TC = O(n)    SC=O(1)

// Method 2 - 2 pointer approach
Node *removeDuplicates(Node *head)
{
    Node *p1 = head, *p2 = head;

    if (!head)
        return NULL;

    while (p1 != NULL)
    {
        if (p2->data == p1->data)
        {
            p2->next = p1;
            p2 = p1;
        }
        else if (p1->next == NULL)
        {
            p2->next = NULL;
        }
        p1 = p1->next;
    }

    return head;
}
// TC = O(n)    SC=O(1)

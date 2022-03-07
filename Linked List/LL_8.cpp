
class Solution
{
public:
    // Function to move last node to first
    Node *moveToFront(Node *head)
    {
        Node *curr = head, *temp;

        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = NULL;
        temp->next = head;
        temp = head;

        return head;
    }
};
// TC = O(n)    SC=O(1)

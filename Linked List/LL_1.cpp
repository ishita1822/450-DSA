/*struct Node
{
   int data;
   struct Node *next;
}  */

class Solution
{
public:
    // Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        Node *prev = NULL, *curr = head, *temp = NULL;

        if (head == NULL || head->next == NULL)
            return head;

        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

// TC = O(n)       SC=O(1)
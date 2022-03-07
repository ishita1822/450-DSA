/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        node *nex = NULL, *curr = head, *prev = NULL;
        int c = 0;

        while (curr != NULL && c < k)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            c++;
        }
        if (nex != NULL)
        {
            head->next = reverse(nex, k);
        }
        return prev;
    }
};
// TC = O(n)    SC=O(1)

/*
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

// function to reverse a doubly linked list
// in groups of given size
class Solution
{
public:
    Node *revListInGroupOfGivenSize(Node *head, int k)
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
            head->next = revListInGroupOfGivenSize(nex, k);
            head->next->prev = head;
        }
        return prev;
    }
};
// TC = O(n)    SC=O(1)

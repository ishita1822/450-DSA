/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *curr = head;
        int c0 = 0, c1 = 0, c2 = 0;

        while (curr != NULL)
        {
            if (curr->data == 0)
                c0++;
            else if (curr->data == 1)
                c1++;
            else
                c2++;

            curr = curr->next;
        }
        curr = head;
        while (curr)
        {
            if (c0)
            {
                curr->data = 0;
                c0--;
            }
            else if (c1)
            {
                curr->data = 1;
                c1--;
            }
            else
            {
                curr->data = 2;
                c2--;
            }

            curr = curr->next;
        }
        return head;
    }
};

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    // Function to add two numbers represented by linked list.

    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *temp = NULL;

        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        first = reverse(first);
        second = reverse(second);
        Node *temp, *res = NULL, *curr = NULL;

        int sum, c = 0;
        while (first != NULL || second != NULL)
        {
            sum = 0;
            sum = c + (first ? first->data : 0) + (second ? second->data : 0);
            c = (sum >= 10) ? 1 : 0;
            sum = sum % 10;

            temp = new Node(sum);
            if (res == NULL)
            {
                res = temp;
            }
            else
            {
                curr->next = temp;
            }
            curr = temp;

            if (first)
            {
                first = first->next;
            }
            if (second)
            {
                second = second->next;
            }
        }

        if (c > 0)
        {
            temp = new Node(c);
            curr->next = temp;
            // curr = temp;
        }

        res = reverse(res);
        return res;
    }
};
// TC = O(n+m)     SC = O(MAX(n+m))
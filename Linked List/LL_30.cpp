/*struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Clone a linked list with next and random pointer
class Solution
{
public:
    Node *copyList(Node *head)
    {
        Node *cur = head, *temp;
        while (cur)
        {
            temp = cur->next;
            cur->next = new Node(cur->data);
            cur->next->next = temp;
            cur = temp;
        }

        cur = head;
        while (cur)
        {
            cur->next->arb = (cur->arb) ? cur->arb->next : cur->arb;

            cur = cur->next->next;
        }

        Node *original = head, *copy = head->next;
        temp = copy;
        while (original && copy)
        {

            original->next = copy->next;
            copy->next = (copy->next) ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }

        return temp;
    }
};
// TC = O(n)    SC=O(1)

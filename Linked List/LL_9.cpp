// Method 1 - using sum and carry
class Solution
{
public:
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

    Node *addOne(Node *head)
    {
        // return head of list after adding one
        Node *curr = reverse(head);
        Node *new_head = curr;
        Node *prev = NULL;

        int sum = 0, carry = 1;

        while (curr != NULL)
        {
            sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;

            if (carry == 0)
            {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (carry == 1)
        {
            Node *temp = new Node(1);
            prev->next = temp;
        }

        return reverse(new_head);
    }
};
// TC = O(n)    SC = O(1)

// Method 2

class Solution
{
public:
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

    Node *addOne(Node *head)
    {
        // return head of list after adding one
        Node *curr = reverse(head);
        Node *new_head = curr, *prev = NULL;

        int carry = 1;

        while (curr != NULL)
        {
            if (curr->data == 9 && curr->next == NULL)
            {
                curr->data = 0;
                Node *temp = new Node(1);
                prev->next = temp;
            }
            else if (curr->data == 9 && carry == 1)
            {
                curr->data = 0;
                carry = 1;
            }
            else
            {
                curr->data = curr->data + carry;
                carry = 0;
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        return reverse(new_head);
    }
};
// TC = O(n)    SC = O(1)

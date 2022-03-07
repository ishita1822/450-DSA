/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Method 1 - reversing the second half of linked list
class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // finding middle element in linked list
        Node *slow = head, *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse a linked list
        Node *prev = NULL, *curr = slow->next, *temp;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        slow->next = prev;
        slow = slow->next;
        Node *p = head;
        
        // checking both list
        while (slow != NULL)
        {
            if (p->data != slow->data)
            {
                return false;
            }

            slow = slow->next;
            p = p->next;
        }

        return true;
    }
};
// Tc = O(n)   SC = O(1)

// Method 2 - using stack
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        ListNode *fast = head, *slow = head;
        stack<int> sk;

        sk.push(slow->val);
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast->next != NULL)
                sk.push(slow->val);
        }

        while (slow->next != NULL)
        {
            slow = slow->next;
            if (slow->val != sk.top())
            {
                return false;
            }
            sk.pop();
        }
        return true;
    }
};
// Tc = O(n)   SC = O(n)

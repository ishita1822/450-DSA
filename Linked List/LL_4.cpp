// Mehtod 1 - hare and tortoise  = Floyd's Algorithm

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        if (head == NULL)
            return;

        Node *slow = head, *fast = head;
        // to check if there is loop
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) // measn loop is present
            {
                break;
            }
        }
        // if fast and slow both pointing to head
        if (slow == head)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = NULL;
        }
        // if fast and slow both are not pointing to head, so there met somwhere in
        // middle of the linked list
        else if (slow == fast)
        {
            slow = head;
            while (fast->next != slow->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
};
// TC = O(n)    SC=O(1)

// Method 2 - using hashmap
class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        Node *curr = head->next, *prev = head;

        unordered_map<Node *, int> mp;

        while (curr != NULL)
        {
            if (!mp[curr])
            {
                mp[curr] = 1;
                prev = curr->next;
                curr = curr->next;
            }
            else
            {
                prev->next = NULL;
                break;
            }
        }
    }
};
// TC = O(n)    SC=O(n)

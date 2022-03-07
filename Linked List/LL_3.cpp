// Mehtod 1 - hare and tortoise  = Floyd's Algorithm

class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
// TC = O(n)    SC=O(1)

// method 2 - using hashmap
class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        unordered_map<Node *, int> mp;
        if (head == NULL)
            return false;

        while (head != NULL)
        {
            if (!mp[head])
            {
                mp[head] = 1;
                head = head->next;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// TC = O(n)    SC=O(n)
// Method 1 - using Floyd's Algorithm
class Solution
{
public:
    // to return the starting point of the loop
    struct Node *detectLoop(struct Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL && slow != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        if (slow != fast)
        {
            return NULL;
        }

        else if (slow == head)
        {
            return slow;
        }
        else if (slow == fast)
        {
            slow = head;
            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
};
// TC = O(n)    SC=O(1)

// Method 2 - using hash set
class Solution
{
public:
    // to return the starting point of the loop
    void detectLoop(Node *head)
    {
        Node *curr = head;
        unordered_set<Node *, int> s;

        while (curr != NULL)
        {
            // if node value is already present in set
            if (s.find(curr) != s.end())
            {
                return curr;
            }
            else
            {
                s.insert(curr);
                curr = curr->next;
            }
        }
        return NULL;
    }
};
// TC = O(n)    SC=O(n)
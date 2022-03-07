// Using Hashmap
class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        unordered_map<int, int> mp;

        Node *curr = head, *prev = curr;

        mp[curr->data] = 1;
        curr = curr->next;

        while (curr != NULL)
        {
            if (mp[curr->data])
            {
                prev->next = curr->next;
            }
            else
            {
                mp[curr->data] = 1;
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};
// TC = O(n)    SC=O(n)

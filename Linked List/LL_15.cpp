/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Method 1 - FLoyds algorithm
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
// Tc = O(n/2)   SC = O(1)

// Method 2
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *temp = head;
        int count = 0;

        while (temp)
        {
            temp = temp->next;
            count++;
        }
        int n = (count / 2) + 1;
        for (int i = 1; i < n; i++)
        {
            head = head->next;
        }
        return head;
    }
};
// Tc = O(n)   SC = O(1)

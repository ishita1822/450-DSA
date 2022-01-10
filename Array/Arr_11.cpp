#include <bits/stdc++.h>
using namespace std;

// TC= O(n)  SC= O(1);
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int ans;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[abs(nums[i])] > 0)
            {
                nums[abs(nums[i])] = nums[abs(nums[i])] * -1;
            }
            else
            {
                ans = abs(nums[i]);
            }
        }
        return ans;
    }
};

// TC= O(n)  SC= O(1);-->more used
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int start = 0;

        while (start != slow)
        {
            slow = nums[slow];
            start = nums[start];
        }
        return start;
    }
};
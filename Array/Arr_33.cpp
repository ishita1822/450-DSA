class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {

        int count = 0, bad = 0;

        // how many elements are less than k
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                count++;
            }
        }

        // how many elements are greater than k in the range of 0 to count
        for (int i = 0; i < count; i++)
        {
            if (arr[i] > k)
            {
                bad++;
            }
        }

        // traversing the array ..subarray wise
        int ans = bad;
        for (int i = 0, j = count; j < n; i++, j++)
        {
            if (arr[i] > k)
            {
                bad--;
            }
            if (arr[j] > k)
            {
                bad++;
            }
            ans = min(ans, bad);
        }

        return ans;
    }
};
// TC = O(n)  SC = O(1)
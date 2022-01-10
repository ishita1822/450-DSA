// Method 1

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {

        long long ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l <= r)
        {
            if (arr[l] < arr[r])
            {
                if (arr[l] > lmax)
                {
                    lmax = arr[l];
                }
                else
                {
                    ans = ans + (lmax - arr[l]);
                }
                l++;
            }
            else if (arr[r] < arr[l])
            {
                if (arr[r] > rmax)
                {
                    rmax = arr[r];
                }
                else
                {
                    ans = ans + (rmax - arr[r]);
                }
                r--;
            }
        }

        return ans;
    }
};
// TC = O(n)   SC = O(1)

// Method 2
//  But this below code was accepted in gfg cuz its TC and SC were O(n)
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {

        long long ans = 0;
        int l = 0, r = n - 1;
        int left[n], right[n];

        left[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], arr[i]);
        }

        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], arr[i]);
        }

        for (int i = 0; i < n; i++)
        {
            ans = ans + (min(left[i], right[i]) - arr[i]);
        }
        return ans;
    }
};
// TC = O(n)  SC = O(n)
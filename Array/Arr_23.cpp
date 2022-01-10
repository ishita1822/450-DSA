class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long int prod = 1;
        long long int maxp = INT_MIN;

        // traverse from left to right
        for (int i = 0; i < n; i++)
        {
            if (prod == 0)
            {
                prod = 1;
            }
            prod = prod * arr[i];
            maxp = max(maxp, prod);
        }

        // traverse from right to left
        prod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (prod == 0)
            {
                prod = 1;
            }
            prod = prod * arr[i];
            maxp = max(maxp, prod);
        }
        return maxp;
    }
};

//  TC = O(n)     SC = O(1);
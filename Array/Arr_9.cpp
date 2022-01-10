#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        // code here
        sort(arr, arr + n);

        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        int min_, max_;

        for (int i = 0; i < n - 1; i++)
        {
            min_ = min(smallest, arr[i + 1] - k);
            max_ = max(largest, arr[i] + k);

            if (min_ < 0)
            {
                continue;
            }

            ans = min(ans, (max_ - min_));
        }

        return ans;
    }
};
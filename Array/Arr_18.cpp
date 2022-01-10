#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        unordered_map<int, int> mp;
        int c = 0;

        for (int i = 0; i < n; i++)
        {

            int diff = k - arr[i];
            if (mp.find(diff) != mp.end())
            {

                c = c + mp[diff];
            }
            mp[arr[i]]++;
        }

        return c;
    }
};

// TC= O(n)   SC= O(n)
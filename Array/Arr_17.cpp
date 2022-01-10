#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int min_purchase = prices[0];
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {

            min_purchase = min(min_purchase, prices[i]);
            max_profit = max(max_profit, prices[i] - min_purchase);
        }

        return max_profit;
    }
};

// TC= O(n)   SC= O(1)
class Solution
{
public:
public:
    int find_median(vector<int> v)
    {
        // Code here.
        int n = v.size();
        int median, sum = 0;

        sort(v.begin(), v.end());

        if (n % 2 != 0)
        {
            median = v[n / 2];
        }
        else
        {
            median = (v[n / 2] + v[(n / 2) - 1]) / 2;
        }

        return median;
    }
};
// TC = O(nlogn)    Sc = O(1)

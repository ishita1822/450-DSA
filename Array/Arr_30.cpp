class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        long long mindiff = INT_MAX;

        sort(a.begin(), a.end());

        for (int i = 0; i < (n - m + 1); i++)
        {
            int diff = a[i + m - 1] - a[i];
            if (diff < mindiff)
            {
                mindiff = diff;
            }
        }
        return mindiff;
    }
};
// TC = O(nlong)--of sorting     SC = O(1)
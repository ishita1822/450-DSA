class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n);
        for (int i = 0; i < n - 2; i++)
        {
            int sum = X - A[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                if (A[j] + A[k] == sum)
                {
                    return 1;
                }
                else if (A[j] + A[k] < sum)
                {
                    j++;
                }
                else if (A[j] + A[k] > sum)
                {
                    k--;
                }
            }
        }
        return 0;
    }
};
// TC = O(n^2)   SC = O(1)

//--> using set / hashmap
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        set<int> s;
        for (int i = 0; i < n - 2; i++)
        {
            int sum = X - A[i];
            int j = i + 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s.find(sum - A[j]) != s.end())
                {
                    return 1;
                }
                s.insert(A[j]);
            }
        }
        return 0;
    }
};
// TC = O(n^2)   SC = O(n)
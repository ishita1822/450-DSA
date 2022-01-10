class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int sum = 0;

        set<int> s;

        if (n == 1 && arr[0] == 0)
            return true;

        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if (sum == 0 || arr[i] == 0)
            {
                return true;
            }
            else if (s.find(sum) != s.end())
            {
                return true;
            }
            else
            {
                s.insert(sum);
            }
        }

        return false;
    }
};

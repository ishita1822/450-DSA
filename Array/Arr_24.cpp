class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> s;
        int max_con = INT_MIN;

        // insering all elements in set
        for (int i = 0; i < N; i++)
        {
            s.insert(arr[i]);
        }

        // iterating in set
        for (int i = 0; i < N; i++)
        {
            if (s.find(arr[i] - 1) != s.end())
            {
                continue;
            }
            else if (s.find(arr[i] - 1) == s.end()) //(element-1) is not present in set so that ele is the start element
            {
                int curr_num = arr[i];
                int c = 1;

                while (s.find(curr_num + 1) != s.end()) // to find the lenght of consecutive sequence
                {
                    curr_num = curr_num + 1;
                    c = c + 1;
                }
                max_con = max(max_con, c);
            }
        }
        return max_con;
    }
};

// TC = O(n)    SC = O(n)
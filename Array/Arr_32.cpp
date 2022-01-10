class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int r = array.size() - 1;
        int l = 0;

        for (int i = 0; i <= r; i++)
        {
            if (array[i] < a)
            {
                swap(array[i], array[l]);
                l++;
            }
            else if (array[i] > b)
            {
                swap(array[i], array[r]);
                r--;
                i--;
            }
        }
    }
};
// TC = O(n)    SC = O(1)

// BRUTE FORCE :-
class Solution
{
public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        sort(array.begin(), array.end());
    }
};

// TC = O(nlong)        SC = O(1)
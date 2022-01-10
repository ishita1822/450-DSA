#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    int nums1[n1], nums2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> nums2[i];
    }

    // if(n1<n2)
    //  {
    //      return function(nums2,nums1);
    //  }

    int low = 0, high = n1;
    int cut1, cut2;
    int left1, left2, right1, right2;

    while (low <= high)
    {
        cut1 = (low + high) / 2;
        cut2 = ((n1 + n2 + 1) / 2) - cut1;

        left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            // if n1+n2 is even
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2), min(right1, right2));
            }
            // if n1+n2 is odd
            else
            {
                return (max(left1, left2));
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return 0;
}
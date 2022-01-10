// this was in gfg practice section but the Q in form is different
int Palinaay(int a[], int n)
{ // add code here.
    int ans = 0, temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        ans = 0;
        while (temp != 0)
        {
            int reminder = temp % 10;
            ans = (ans * 10) + reminder;

            temp = temp / 10;
        }
        if (ans != a[i])
        {
            return 0;
        }
    }
    return 1;
}
// TC = O(n)    SC = O(1)

// In dsa sheet the Q was refering to below Q
//  Q:- minimum no of operations required to make an array palindrome
// https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/#:~:text=So%20we%20do%20not%20need,complexity%20is%20O(n).
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        // if right element is smaller, then merge it
        else if (a[i] > a[j])
        {
            j--;
            a[j] = a[j] + a[j + 1];
            ans++;
        }
        // if left element is smaller, then merge
        else if (a[i] < a[j])
        {
            i++;
            a[i] = a[i] + a[i - 1];
            ans++;
        }
    }
    cout << endl;
    cout << ans;
    return 0;
}
// TC = O(n)    SC = O(1)

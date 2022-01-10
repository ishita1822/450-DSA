#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, sum = 0;
    int min_count = INT_MAX;
    cin >> n >> x;

    int a[n];
    for (int k = 0; k < n; k++)
    {
        cin >> a[k];
    }

    int i = 0;
    int j = 0;
    while (i <= j && j < n)
    {
        // if sum is smaller than  x, keep adding till sum>=x
        while (sum <= x && j < n)
        {
            sum = sum + a[j];
            j++;
        }

        // if sum > x, then keep subtracting till sum<x
        while (sum > x && j < n)
        {
            min_count = min(min_count, (j - i));
            sum = sum - a[i];
            i++;
        }
    }

    cout << endl;
    cout << min_count;
    return 0;
}

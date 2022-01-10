#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    for (auto x : mp)
    {
        int t = n / k;
        if (x.second > t)
        {
            cout << x.first8 << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_ele = a[0], min_ele = a[0];
    for (int i = 0; i < n; i++)
    {
        max_ele = max(max_ele, a[i]);
        min_ele = min(min_ele, a[i]);
    }
    cout << "Max: " << max_ele << endl;
    cout << "Min: " << min_ele;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void rearrage(int a[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        while (i <= n - 1 && a[i] > 0)
        {
            i++;
        }
        while (j >= 0 && a[j] < 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    if (i == 0 || i == n)
        return;

    int k = 0;
    while (i < n && k < n)
    {
        swap(a[i], a[k]);
        k = k + 2;
        i = i + 1;
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    rearrage(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void sort_arr(int *A, int N)
{
    int l = 0;
    int h = N - 1;

    while (l <= h)
    {

        // l=+ve And h=-ve
        if (A[l] > 0 && A[h] < 0)
        {
            swap(A[l++], A[h--]);
        }
        // both l and h -ve
        else if (A[l] < 0 && A[h] < 0)
        {
            l++;
        }
        // both l and h +ve
        else if (A[l] > 0 && A[h] > 0)
        {
            h--;
        }
        // l=-ve and h=+ve
        else if (A[l] < 0 && A[h] > 0)
        {
            l++;
        }
    }
}

void print(int *A, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
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

    sort_arr(a, n);

    print(a,n);
    return 0;
}

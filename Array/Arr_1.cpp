#include <bits/stdc++.h>
using namespace std;

void rev(int *A, int N)
{
    int j = N - 1, temp;
    for (int i = 0; i < N / 2; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
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

    rev(a, n);

    return 0;
}

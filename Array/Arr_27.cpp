
// was my approch (here..if elements are not repeated we can use set)
string isSubset(int a1[], int a2[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (s.find(a2[i]) != s.end())
        {
            continue;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}
// TC = O(n)     SC = O(n)

// Real appraoch (if element is repeated then we can't use set ...so we use map)
string isSubset(int a1[], int a2[], int n, int m)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a1[i]]++; // gives the frequncy of element repeated like a1={1,2,2,3}
    }

    for (int i = 0; i < m; i++)
    {
        if (mp[a2[i]] > 0)
        {
            mp[a2[i]]--;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}

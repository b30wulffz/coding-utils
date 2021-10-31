#include <bits/stdc++.h>

using namespace std;

int product(int z, vector<int> from, vector<int> to, vector<int> w)
{
    map<int, set<int>> m;
    for (int i = 0; i < z; i++)
    {
        m[w[i]].insert(from[i]);
        m[w[i]].insert(to[i]);
    }

    int max_product = INT_MIN;
    int max = INT_MIN;
    map<pair<int, int>, int> p;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        set<int> s = it->second;
        vector<int> v(s.begin(), s.end());
        int siz = v.size();
        for (int i = 0; i < siz - 1; i++)
        {
            p[make_pair(v[i], v[i + 1])]++;
            if (p[make_pair(v[i], v[i + 1])] > max)
                max = p[make_pair(v[i], v[i + 1])];
        }
        if (siz > 2)
        {
            p[make_pair(v[0], v[siz - 1])]++;
            if (p[make_pair(v[0], v[siz - 1])] > max)
                max = p[make_pair(v[0], v[siz - 1])];
        }
    }
    for (auto [pr, b] : p)
    {
        if (b == max)
            if (max_product < pr.first * pr.second)
                max_product = pr.first * pr.second;
    }
    return max_product;
}

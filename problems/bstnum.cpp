#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ncr(int n, int r)
{
    vector<int> C(r + 1, 0);

    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int k = min(i, r);
        for (int j = k; j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % 100000007;
    }
    return C[r];
}

vector<int> numBST(vector<int> nodeValues)
{
    vector<int> ans;
    for (auto x : nodeValues)
    {
        int n = ncr(2 * x, x) - ncr(2 * x, x - 1);
        ans.push_back(n);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> r = numBST(v);
    for (auto x : r)
    {
        cout << x << " ";
    }
    return 0;
}
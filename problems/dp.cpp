#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int mod = 1000000007;
    cin >> n >> m;
    int A[n], B[m];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    vector<vector<long long>> v(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i <= m; i++)
        v[0][i] = 1;
    for (int i = 0; i <= n; i++)
        v[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
            if (A[i - 1] != B[j - 1])
            {
                v[i][j] -= v[i - 1][j - 1];
            }
            v[i][j] = (v[i][j] + mod) % mod;
        }
    }
    cout << v[n][m] << endl;
    return 0;
}

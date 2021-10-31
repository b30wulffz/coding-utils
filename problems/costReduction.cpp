#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int reductionCost(vector<int> num)
{
    multiset<int> s;
    for (auto x : num)
    {
        s.insert(x);
    }
    int ans = 0, sum = 0;
    while (s.size() > 1)
    {
        auto a = s.begin();
        int x = *a;
        s.erase(a);

        a = s.begin();
        int y = *a;
        s.erase(a);

        sum = (x + y);
        s.insert(sum);
        ans += sum;
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
    cout << reductionCost(v);
    // int t
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    return 0;
}
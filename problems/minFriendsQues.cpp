#include <iostream>
#include <vector>

using namespace std;

long mE(int &m, long &max_scg)
{
    long rr = m % max_scg;
    long nn = m / max_scg;
    long a = max_scg, b = nn, c = rr;
    long y = b * (b - 1) / 2 * a * (a - 1);
    long x = b * a * (a - 1) / 2;
    long t = b * c * (a - 1);
    long z = c * (c - 1) / 2;
    long maxE = t + x + z + y;
    return maxE;
}

long minFriends(int numNodes, int numEdges)
{
    long l = 1, r = numNodes;
    while (r > l)
    {
        long mid = ((r - l) / 2) + l;
        long f = mE(numNodes, mid);
        if (f >= numEdges)
            r = mid;
        else
            l = 1 + mid;
    }
    return l;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << minFriends(n, m);
}
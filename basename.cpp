#include <bits/stdc++.h>
using namespace std;

char *getBaseName(char src[])
{
    char *dest;
    int len = strlen(src);
    if (src[len - 1] == '/')
    {
        len--;
    }
    int ind = len - 1;
    while (ind >= 0)
    {
        if (src[ind] == '/')
        {
            break;
        }
        ind--;
    }
    ind++;
    int size = len - ind;
    if (size > 0)
    {
        dest = (char *)malloc(sizeof(char) * size);
        int i = 0;
        while (ind < len)
        {
            dest[i] = src[ind];
            ind++;
            i++;
        }
    }
    else
    {
        dest = (char *)malloc(sizeof(char) * 1);
        dest[0] = '/';
    }
    return dest;
}

int main()
{
    char str1[] = ":/mnt/d/Learn/Code";
    char *str2 = getBaseName(str1);
    cout << str2 << endl;
    char str3[] = "/";
    char *str4 = getBaseName(str3);
    cout << str4 << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// start is included, end is not included
char *substr(char *str, int start, int end)
{
    if (start < 0)
    {
        start = 0;
    }
    if (end > strlen(str))
    {
        end = strlen(str);
    }
    if (start <= end)
    {
        char *result = (char *)malloc(sizeof(char) * (end - start + 1));
        int ind = 0;
        for (int i = start; i < end; i++)
        {
            result[ind] = str[i];
            ind++;
        }
        result[ind] = '\0';
        return result;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    char str1[] = "Hello World";
    char *str3 = substr(str1, 2, 8);
    cout << str3 << endl;
    return 0;
}
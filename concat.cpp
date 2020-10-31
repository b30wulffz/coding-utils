#include <bits/stdc++.h>
using namespace std;

char *concat(char *str1, char *str2)
{
    char *result = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    char ind = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        result[ind] = str1[i];
        ind++;
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        result[ind] = str2[i];
        ind++;
    }
    result[ind] = '\0';
    return result;
}

int main()
{
    char *str1 = (char *)malloc(sizeof(char) * 100);
    char *str2 = (char *)malloc(sizeof(char) * 100);
    cin >> str1;
    cin >> str2;
    char *str3 = concat(str1, str2);
    cout << str3 << endl;
    return 0;
}
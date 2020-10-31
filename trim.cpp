#include <bits/stdc++.h>
using namespace std;

char *trim(char *src, int endline)
{
    char *dest = (char *)malloc(strlen(src) * sizeof(char));
    if (src != NULL)
    {
        int i = 0, j;
        if (endline == 1)
        {
            j = strlen(src) - 2;
        }
        else
        {
            j = strlen(src) - 1;
        }
        // from beginning
        while (src[i] == ' ' || src[i] == '\t')
        {
            i++;
        }
        //from end
        while (src[j] == ' ' || src[j] == '\t')
        {
            j--;
        }
        int ind = 0, flag = 0, flagCodes = 0;

        while (i <= j)
        {
            if (src[i] == '"' || src[i] == '\'')
            {
                if (flagCodes == 0)
                {
                    flagCodes = 1;
                }
                else
                {
                    flagCodes = 0;
                }
            }
            if ((src[i] == ' ' || src[i] == '\t') && flagCodes == 0)
            {
                flag = 1;
            }
            else
            {
                if (flag == 1)
                {
                    dest[ind] = ' ';
                    flag = 0;
                    ind++;
                }
                dest[ind] = src[i];
                ind++;
            }
            i++;
        }
        // dest[ind] = '\n';
        // ind++;
        dest[ind] = '\0';
    }
    return dest;
}

int main()
{
    char str1[] = "              Hello      World            \n";
    char *str2 = trim(str1, 1);
    cout << str2 << endl;
    char str3[] = "              Hello  '     New    '    World            \n";
    char *str4 = trim(str3, 1);
    cout << str4 << endl;
    char str5[] = "              Hello    Old  World            ";
    char *str6 = trim(str5, 0);
    cout << str6 << endl;
    return 0;
}
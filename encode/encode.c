#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *DuplicateEncoder(char *arr)
{
    char *str;
    int length;
    int i;
    int j;
    int tmp;
    length = strlen(arr);
    str = malloc(sizeof(char) * length + 1);
    strcpy(str, arr);
    str[length] = '\0';
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    tmp = 0;
    i = 0;
    j = 1;
    while (i < length - 1)
    {
        if (str[i] == 126)
        {
            i++;
            j = i + 1;
        }
        else
        {
            while (j < length)
            {
                if (str[i] == str[j])
                {
                    tmp++;
                    str[j] = 126;
                }
                j++;
            }
            if (tmp != 0)
            {
                str[i] = 126;
                tmp = 0;
            }
            i++;
            j = i + 1;
        }
    }
    i = 0;
    while (str[i])
    {
        if (str[i] == 126)
            str[i] = ')';
        else
            str[i] = '(';
        i++;
    }
    return (str);
}

int main()
{
    //printf("%s\n", DuplicateEncoder("din"));
    //printf("%s\n", DuplicateEncoder("recede"));
    printf("%s\n", DuplicateEncoder("Prespecialized"));
    printf("%s\n", DuplicateEncoder("   ()(   "));
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestConsec(char* strarr[], int n, int k) 
{
    char *str;
    int i;
    int j;
    int pos;
    int max;
    int tmp;
    i = 0;
    j = 0;
    pos = 0;
    max = 0;
    tmp = 0;
    if (n == 0 || k == 0 || k > n)
        return ("");
    while (i <= n - k)
    {
        while (j < k)
        {
            tmp += strlen(strarr[i + j]);
            j++;
        }
        if (tmp > max)
        {
            max = tmp;
            pos = i;
        }
        tmp = 0;
        j = 0;
        i++;
    }
    str = calloc((max + 1), sizeof(char));
    i = 0;
    while (i < k)
    {
        strcat(str, strarr[pos]);
        i++;
        pos++;
    }
    str[max] = '\0';
    return (str);
}

int main()
{
    char* a1[] = {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
    //char* a1[] = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
    //char* a1[] = {};
    //char* a1[] = {"itvayloxrp","wkppqsztdkmvcuwvereiupccauycnjutlv","vweqilsfytihvrzlaodfixoyxvyuyvgpck"};
    printf("%s\n", longestConsec(a1, 8, 2));
}
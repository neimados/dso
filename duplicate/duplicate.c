#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

size_t duplicate_count(const char *text) 
{
    size_t i;
    size_t j;
    size_t length;
    char *str;
    size_t tmp;
    size_t count;
    length =  strlen(text) + 1;
    str = calloc(length , 1);
    strcat(str, text);
    str[length] = '\0';
    i = 0;
    j = 1;
    tmp = 0;
    count = 0;
    while (i < length - 2)
    {
            if (str[i] == 126)
            {
                i++;
                j = i + 1;
            }
            else
            {
                while (j < length - 1)
                {
                    if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] += 32;
                    else if (str[j] >= 'A' && str[j] <= 'Z')
                        str[j] += 32;
                    if (str[i] == str[j])
                    {
                        str[j] = 126;
                        tmp++;
                    }
                    j++;
                }
                i++;
                j = i + 1;
            }
            if (tmp != 0)
            {
                count++;
                tmp = 0;
            }
    }
    free(str);
    return(count);
}

int main()
{
    //printf("%d\n",duplicate_count("abcde"));
    //printf("%d\n",duplicate_count("abcdea"));
    printf("%d\n",duplicate_count("Aa11"));
}
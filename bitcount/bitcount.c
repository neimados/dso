#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t countBits(unsigned value)
{
    char base[] = "01";
    char *str;
    int nb;
    size_t count;
    int length;
    int i;
    nb = 0;
    count = 0;
    length = 0;
    nb = value;
    while (nb > 0)
    {
        nb /= 2;
        length++;
    }
    str = malloc(sizeof(char) * length + 1);
    str[length] = '\0';
    nb = value;
    i = length - 1;
    while (nb > 0)
    {
        str[i] = base[nb % 2];
        nb /= 2;
        i--;
    }
    i = 0;
    while (str[i])
    {
        if (str[i] == '1')
            count++;
        i++;
    }
    free(str);
    return (count);
}

int main()
{
    //printf("%zu\n", countBits(1234));
    //printf("%zu\n", countBits(0));
    printf("%zu\n", countBits(4));
    //printf("%zu\n", countBits(7));
    //printf("%zu\n", countBits(9));
    //printf("%zu\n", countBits(10));
}
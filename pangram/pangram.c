#include <stdio.h>
#include <stdbool.h>

bool is_pangram(const char *str_in) 
{
    int i;
    int j;
    i = 0;
    j = 0;
    char base[] = "abcdefghijklmnopqrstuvwxyz";
    while (str_in[i])
    {
        while (base[j])
        {
            if (str_in[i] == base[j] || str_in[i] == base[j] - 32)
                base[j] = '0';
            j++;
        }
        i++;
        j = 0;
    }
    i = 0;
    while (base[i])
    {
        if (base[i] != '0')
            return (false);
        i++;
    }
    return (true);
}

int main()
{
    printf("%d\n", is_pangram("The quick, brown fox jumps over the lazy dog!"));
    printf("%d\n", is_pangram("The quick, brown fox jumped over the lazy dog!"));
}
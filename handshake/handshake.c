#include <stdio.h>

int get_participants(int handshakes) 
{
    int total;
    int i;
    total = 0;
    i = 0;
    if (handshakes == 0)
        return (1);
    while (total < handshakes)
        total += i++;
    return (i);
}

int main()
{
    printf("%d\n", get_participants(0));
    printf("%d\n", get_participants(1));
    printf("%d\n", get_participants(3));
    printf("%d\n", get_participants(6));
    printf("%d\n", get_participants(7));
    printf("%d\n", get_participants(8));
}

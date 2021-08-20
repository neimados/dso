#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

ssize_t find_short(const char *s)
{
	ssize_t	i;
	ssize_t count;
	count = 0;
	i = 0;
	while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z' ))
	{
		i++;
		s++;
	}
	count = i;
	i = 0;
	while (*s)
	{
		while (*s == 32)	
			s++;
		while ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z' ) || *s == 39)
		{
			i++;
			s++;
		}
		if (i < count)
			count = i;
		i = 0;
	}
   return (count);
}

int main()
{
    printf("%zd\n",find_short("bitcoin take over the world maybe who knows perhaps"));
    printf("%zd\n",find_short("turns out random test cases are easier than writing out basic ones"));
    printf("%zd\n",find_short("lets talk about C the best language"));
    printf("%zd\n",find_short("i want to travel the world writing code one day"));
    printf("%zd\n",find_short("Lets all go on holiday somewhere very cold"));
    printf("%zd\n",find_short("Let's travel abroad shall we"));
}

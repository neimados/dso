#include <stdlib.h>
#include <string.h>

char *formatDuration (int n) 
{
    char *str;
    int years = 0;
    int days = 0;
    int hours = 0;
    int min = 0;
    int sec = 0;
    int length = 1;
    int yes = 0;
    char one;
    char two;
    char three;
    if (n == 0)
    {
        str = calloc(4, 1);
        strcpy(str, "now");
        return (str);
    }
    if (n >= 31536000)// Separate time
    {
        years = n / 31536000;
        n = n % 31536000;
    }
    if (n >= 86400)
    {
        days = n / 86400;
        n = n % 86400;
    }
    if (n >= 3600)
    {
        hours = n / 3600;
        n = n % 3600;
    }
    min = n / 60;
    sec = n % 60;
    if (years != 0)//find str length
    {
        yes++;
        length = strlen("1 year");
        if (years < 10 && years > 1)
            length++;
        else if (years > 9)
            length += 2;
    }
    if (days != 0)
    {
        yes++;
        length += strlen("1 day");
        if (days < 10 && days > 1)
            length++;
        else if (days > 9 && days < 100)
            length += 2;
        else if (days > 99)
            length += 3;
    }
    if (hours != 0)
    {
        yes++;
        length += strlen("1 hour");
        if (hours < 10 && hours > 1)
            length++;
        else if (hours > 9)
            length += 2;
    }
    if (min != 0)
    {
        yes++;
        length += strlen("1 minute");
        if (min < 10 && min > 1)
            length++;
        else if (min > 9)
            length += 2;
    }
    if (sec != 0)
    {
        yes++;
        length += strlen("1 second");
        if (sec < 10 && sec > 1)
            length++;
        else if (sec > 9)
            length += 2;
    }
    length += (yes * 2) + 3;
    str = calloc(length, 1);
    if (years != 0)//writing str
    {
        if (years == 1)
            strcat(str, "1 year");
        else if (years < 10 && years > 1)
        {
            one = years + '0';
            strncat(str, &one, 1);
            strcat(str, " years");
        }
        else if (years > 9)
        {
            one = (years / 10) + '0';
            two = (years % 10) + '0';
            strncat(str, &one, 1);
            strncat(str, &two, 1);
            strcat(str, " years");
        }
        if (yes > 2)
            strcat(str, ", ");
        else if (yes == 2)
            strcat(str, " and ");
        yes--;
    }
    if (days != 0)
    {
        if (days == 1)
            strcat(str, "1 day");
        else if (days < 10 && days > 1)
        {
            one = days + '0';
            strncat(str, &one, 1);
            strcat(str, " days");
        }
        else if (days > 9 && days < 100)
        {
            one = (days / 10) + '0';
            two = (days % 10) + '0';
            strncat(str, &one, 1);
            strncat(str, &two, 1);
            strcat(str, " days");
        }
        else
        {
            one = (days / 100) + '0';
            days = days % 100;
            two = (days / 10) + '0';
            three = (days % 10) + '0';
            strncat(str, &one, 1);
            strncat(str, &two, 1);
            strncat(str, &three, 1);
            strcat(str, " days");
        }
        if (yes > 2)
            strcat(str, ", ");
        else if (yes == 2)
            strcat(str, " and ");
        yes--;
    }
    if (hours != 0)
    {
        if (hours == 1)
            strcat(str, "1 hour");
        else if (hours < 10 && hours > 1)
        {
            one = hours + '0';
            strncat(str, &one, 1);
            strcat(str, " hours");
        }
        else if (hours > 9)
        {
            one = (hours / 10) + '0';
            two = (hours % 10) + '0';
            strncat(str, &one, 1);
            strncat(str, &two, 1);
            strcat(str, " hours");
        }
        if (yes > 2)
            strcat(str, ", ");
        else if (yes == 2)
            strcat(str, " and ");
        yes--;
    }
    if (min != 0)
    {
        if (min == 1)
            strcat(str, "1 minute");
        else if (min < 10 && min > 1)
        {
            one = min + '0';
            strncat(str, &one, 1);
            strcat(str, " minutes");
        }
        else if (min > 9)
        {
            one = (min / 10) + '0';
            two = (min % 10) + '0';
            strncat(str, &one, 1);
            strncat(str, &two, 1);
            strcat(str, " minutes");
        }
        if (yes == 2)
            strcat(str, " and ");
    }
    if (sec != 0)
    {
        if (sec == 1)
            strcat(str, "1 second");
        else if (sec < 10 && sec > 1)
        {
            one = sec + '0';
            strncat(str, &one, 1);
            strcat(str, " seconds");
        }
        else if (sec > 9)
        {
            one = (sec / 10) + '0';
            two = (sec % 10) + '0';
            strncat(str, &one, 1);
            strncat(str, &two, 1);
            strcat(str, " seconds");
        }
    }
    return (str);
}
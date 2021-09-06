#include <stdio.h>

int score(const int dice[5]) 
{
    int score;
    int i;
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    score = 0;
    i = 0;
    one = 0;
    two = 0;
    three = 0;
    four = 0;
    five = 0;
    six = 0;
    while (i < 5)
    {
        switch (dice[i])
        {
            case 1:
                one++;
                break;
            case 2:
                two++;
                break;
            case 3:
                three++;
                break;
            case 4:
                four++;
                break;
            case 5:
                five++;
                break;
            case 6:
                six++;
                break;
        }
        i++;
    }
    if (one > 2)
    {
        score += 1000;
        one -= 3;
    }
    else if (two > 2)
        score += 200;
    else if (three > 2)
        score += 300;
    else if (four > 2)
        score += 400;
    else if (five > 2)
    {
        score += 500;
        five -= 3;
    }
    else if (six > 2)
        score += 600;
    score += (one * 100);
    score += (five * 50);
    return (score);
}

int main()
{
    //const int dice[5] = {2, 3, 4, 6, 2};
    //const int dice[5] = {4, 4, 4, 3, 3};
    const int dice[5] = {2, 4, 4, 5, 4};
    printf("%d\n", score(dice));
}
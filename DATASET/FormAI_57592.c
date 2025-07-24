//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int num, sum = 0;
    srand(time(0));
    printf("Welcome to the Automated Fortune Teller! \n\n");

    for (int i = 1; i <= 4; i++)
    {
        num = (rand() % 5) + 1;

        if (num == 1)
        {
            printf("%d: You will have good luck today.\n", i);
            sum += 10;
        }
        else if (num == 2)
        {
            printf("%d: Beware of danger today.\n", i);
            sum += 20;
        }
        else if (num == 3)
        {
            printf("%d: A loved one will surprise you with a gift.\n", i);
            sum += 30;
        }
        else if (num == 4)
        {
            printf("%d: Your hard work will pay off soon.\n", i);
            sum += 40;
        }
        else
        {
            printf("%d: It's best to stay home today.\n", i);
            sum += 50;
        }
    }

    printf("\nBased on your fortune readings, your overall luck score is %d.\n", sum);

    if (sum <= 100)
    {
        printf("Your luck is not looking good today. It's best to stay cautious and avoid any unnecessary risks.\n");
    }
    else if (sum <= 150)
    {
        printf("Your luck is average today. Expect some ups and downs, but nothing major.\n");
    }
    else if (sum <= 200)
    {
        printf("Your luck is looking pretty good today! Enjoy the positive vibes and take advantage of any opportunities that come your way.\n");
    }
    else
    {
        printf("Wow! With a luck score like that, you're practically invincible today. Go out and conquer the world!\n");
    }

    return 0;
}
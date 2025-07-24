//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int num = rand() % 10 + 1;

    switch (num)
    {
        case 1:
            printf("Your heart will be filled with love from a special someone.\n");
            break;
        case 2:
            printf("You will meet your true love in a small, cozy coffee shop.\n");
            break;
        case 3:
            printf("Your future love is already on their way to you.\n");
            break;
        case 4:
            printf("You will fall in love with someone unexpected and they will change your life.\n");
            break;
        case 5:
            printf("You will experience a deep and passionate love like never before.\n");
            break;
        case 6:
            printf("There is someone who has been in love with you for a long time but hasn't had the courage to tell you yet.\n");
            break;
        case 7:
            printf("True love will come to you when you least expect it.\n");
            break;
        case 8:
            printf("You will have a dreamy, romantic vacation with your significant other soon.\n");
            break;
        case 9:
            printf("You will find that your soulmate has been right in front of you this whole time.\n");
            break;
        case 10:
            printf("You will have a long and happy life with the one true love of your life.\n");
            break;
    }
    return 0;
}
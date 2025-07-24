//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int age;

    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! Please enter your age: ", name);
    scanf("%d", &age);

    // Generate random number between 1 and 4 to determine fortune
    srand(time(NULL));
    int fortune = rand() % 4 + 1;

    printf("\n%s, based on the alignment of the stars and your birthday, I see that your fortune today is...\n\n", name);

    // Use switch statement to determine fortune based on random number generated
    switch(fortune)
    {
        case 1:
            printf("You will receive unexpected financial gain in the near future!\n");
            break;
        case 2:
            printf("You will soon find love and happiness!\n");
            break;
        case 3:
            printf("You must be cautious in your dealings with others, as someone close to you may be deceiving you.\n");
            break;
        case 4:
            printf("You will face many challenges in the coming days, but you will emerge victorious!\n");
            break;
        default:
            printf("Invalid fortune.\n");
    }

    printf("\nThank you for using the Automated Fortune Teller, %s. Don't forget to recommend me to your friends!\n", name);

    return 0;
}
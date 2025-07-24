//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("**************************\n");
    printf("Choose a number between 1 and 7 to get your fortune:\n");
    printf("1. You will soon meet someone special.\n");
    printf("2. You will have a successful career.\n");
    printf("3. You will travel to a foreign country.\n");
    printf("4. You will receive good news from a friend.\n");
    printf("5. You will experience a major life change.\n");
    printf("6. You will find happiness in unexpected places.\n");
    printf("7. You will come into a large sum of money.\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Your fortune: You will soon meet someone special.\n");
            break;
        case 2:
            printf("Your fortune: You will have a successful career.\n");
            break;
        case 3:
            printf("Your fortune: You will travel to a foreign country.\n");
            break;
        case 4:
            printf("Your fortune: You will receive good news from a friend.\n");
            break;
        case 5:
            printf("Your fortune: You will experience a major life change.\n");
            break;
        case 6:
            printf("Your fortune: You will find happiness in unexpected places.\n");
            break;
        case 7:
            printf("Your fortune: You will come into a large sum of money.\n");
            break;
        default:
            printf("Invalid choice, try again.\n");
            break;
    }

    printf("Your lucky number is: %d\n", rand() % 100 + 1);

    return 0;
}
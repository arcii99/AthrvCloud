//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Generate a random seed based on time

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Type '1' and press Enter to see your fortune\n");
    printf("Type '0' and press Enter to quit\n");

    int choice;
    scanf("%d", &choice);

    while (choice != 0) {

        int fortune_number = rand() % 10; // Generate a random number between 0 and 9

        switch(fortune_number) {
            case 0:
                printf("Good things will come to you in the near future\n");
                break;
            case 1:
                printf("You will meet someone important in the next month\n");
                break;
            case 2:
                printf("Your hard work will pay off soon\n");
                break;
            case 3:
                printf("A new opportunity will arise in the next few weeks\n");
                break;
            case 4:
                printf("Take a risk, it will be worth it\n");
                break;
            case 5:
                printf("Your creativity will be rewarded in the coming days\n");
                break;
            case 6:
                printf("You will find success in something you have been working on\n");
                break;
            case 7:
                printf("Take time to focus on your relationships, they are important\n");
                break;
            case 8:
                printf("A change is coming, embrace it\n");
                break;
            case 9:
                printf("You will receive unexpected good news soon\n");
                break;
        }

        printf("\nType '1' and press Enter to see your fortune again\n");
        printf("Type '0' and press Enter to quit\n");

        scanf("%d", &choice);
    }

    printf("Thank you for using the Automated Fortune Teller! Goodbye.\n");

    return 0;
}
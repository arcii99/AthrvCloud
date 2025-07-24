//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Welcome to the System Administration program!\n");

    int option;
    printf("Select an option:\n1. Clean up the mess\n2. Take a coffee break\n");
    scanf("%d", &option);

    if(option == 1) {
        printf("You chose to clean up the mess. Let's get to work!\n");

        printf("Deleting unnecessary files...\n");
        system("rm -rf /home/user/Desktop/mess");

        printf("Organizing folders...\n");
        system("mkdir /home/user/Documents/important");

        printf("Removing duplicates...\n");
        system("fdupes -rdN /home/user/Downloads");

        printf("Phew! That was a lot of work. Finally done!\n");
    }
    else if(option == 2) {
        printf("You decided to take a coffee break. That's a great choice. Let's brew some coffee!\n");

        printf("Filling up the coffee maker...\n");
        system("echo 'water + coffee powder' > coffee_maker.txt");

        printf("Boiling the mixture...\n");
        for(int i=0; i<10; i++) {
            usleep(500000);
            printf(".");
            fflush(stdout);
        }
        printf("\n");

        printf("Voila! Your coffee is ready. Enjoy your break!\n");
    }
    else {
        printf("Invalid option. Please choose either 1 or 2.\n");
    }

    return 0;
}
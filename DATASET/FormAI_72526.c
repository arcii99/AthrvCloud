//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char answer;
    printf("Welcome to the Linux Update Assistant!\n");
    printf("Do you want to check for updates? (y/n)\n");
    scanf("%c", &answer);
    if (answer == 'y') {
        system("sudo apt-get update");
        system("sudo apt-get upgrade");
        system("sudo apt-get dist-upgrade");
        printf("\nUpdates successfully installed!\n");
    }
    else if (answer == 'n') {
        printf("Alright, no updates will be installed.\n");
    }
    else {
        printf("Invalid input.\n");
        exit(1);
    }

    return 0;
}
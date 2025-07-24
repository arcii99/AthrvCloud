//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>

int main() {
    printf("Welcome to my unique C System administration program! \n");

    printf("What would you like to do first? \n");
    printf("A) Check system specs \n");
    printf("B) Update software packages \n");
    printf("C) Back up important files \n");
    printf("D) Scan for security threats \n");

    char choice = getchar();

    switch(choice) {
        case 'A':
            printf("Checking system specs... \n");
            system("lshw");
            break;
        case 'B':
            printf("Updating software packages... \n");
            system("apt-get update && apt-get upgrade");
            break;
        case 'C':
            printf("Backing up important files... \n");
            system("tar -cvzf backup.tar.gz /important/files/directory");
            printf("Backup complete. \n");
            break;
        case 'D':
            printf("Scanning for security threats... \n");
            system("clamscan -r /");
            break;
        default:
            printf("Incorrect choice. Please try again. \n");
            break;
    }

    return 0;
}
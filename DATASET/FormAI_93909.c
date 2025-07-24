//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice;
    printf("Welcome to the C Wireless Network Scanner!\n");
    printf("Please select an option:\n");
    printf("1. View all available networks\n");
    printf("2. Connect to a network\n");
    scanf("%d", &choice);
    if (choice == 1) {
        FILE *fp;
        char buffer[1000];
        fp = fopen("networks.txt", "r");
        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        while (fgets(buffer, 1000, fp) != NULL) {
            printf("%s\n", buffer);
        }

        fclose(fp);
    } else if (choice == 2) {
        char ssid[20];
        printf("Please enter the SSID of the network you want to connect to: \n");
        scanf("%s", ssid);
        printf("Connecting to %s...\n", ssid);
        // Connect code here
    } else {
        printf("Invalid choice, please try again.\n");
    }
    return 0;
}
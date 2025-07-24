//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Greetings, noble sirs and ladies! I am a wireless network scanner, ready to serve thee.\n");

    // Scan for available networks
    printf("Scanning the surrounding lands for wireless networks...\n");
    system("iwlist scanning | grep ESSID > networks.txt");
    sleep(3);

    // Open file containing network information
    FILE *fp = fopen("networks.txt", "r");
    if (fp == NULL) {
        printf("I beg thy pardon, but there seems to be a problem with the file containing the network information.\n");
        return 1;
    }

    // Read and display network information
    char line[100];
    printf("\nBehold! The wireless networks within range:\n");
    while (fgets(line, 100, fp) != NULL) {
        if (strstr(line, "ESSID")) {
            char *network = strtok(line, ":");
            network = strtok(NULL, ":");
            printf(" * %s\n", network);
        }
    }
    fclose(fp);

    printf("\nWhich network would thee wish to connect to?\n");
    char choice[50];
    fgets(choice, 50, stdin);
    choice[strcspn(choice, "\n")] = 0;

    // Verify choice and connect to network
    fp = fopen("networks.txt", "r");
    if (fp == NULL) {
        printf("My lord, there has been an unexpected issue with the file containing network information. Please try again later.\n");
        return 1;
    }
    while (fgets(line, 100, fp) != NULL) {
        if (strstr(line, choice)) {
            printf("\nConnecting to %s... done!\n", choice);
            sleep(2);
            printf("Thou art now connected to %s. Enjoy thy browsing.\n", choice);
            return 0;
        }
    }
    printf("\nMy apologies, but that network is not within range. Please try again.\n");
    fclose(fp);
    return 1;
}
//FormAI DATASET v1.0 Category: Firewall ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    char user_input[100];
    int access_granted = 0;

    printf("Enter your username to access the system: ");
    fgets(user_input, sizeof(user_input), stdin);

    if(strcmp(user_input, "admin") == 0) {
        access_granted = 1;
    } else {
        printf("Access denied. Only admin can access the system.");
    }

    if(access_granted) {
        printf("Welcome, admin!");
        printf("Please enter the IP address that you want to block: ");

        char ip_address[16];
        fgets(ip_address, sizeof(ip_address), stdin);

        int first_octet, second_octet, third_octet, fourth_octet;
        sscanf(ip_address, "%d.%d.%d.%d", &first_octet, &second_octet, &third_octet, &fourth_octet);

        printf("Do you want to block all incoming and outgoing traffic for this IP? (Y/N): ");

        char confirmation[2];
        fgets(confirmation, sizeof(confirmation), stdin);

        if(confirmation[0] == 'Y' || confirmation[0] == 'y') {
            printf("Blocking traffic for %d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet);
            // Code to block IP address goes here
        } else {
            printf("Okay, IP address not blocked.");
        }
    }

    return 0;
}
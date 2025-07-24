//FormAI DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define ALLOWED_IP "192.168.0.1"   // Define the allowed IP address

int main() {
    char ip[20];    // Allocate space for the IP address

    printf("Enter IP address: ");
    scanf("%s", ip);

    if (strcmp(ip, ALLOWED_IP) == 0) {    //If the IP address matches the specified address
        printf("Access granted!");    // print "Access granted!"
    } else {
        printf("Access denied!");    // Otherwise, print "Access denied!"
    }

    return 0;   // End the program
}
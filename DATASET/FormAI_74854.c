//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Oh man, you're not going to believe this! I just finished coding the most amazing firewall program!\n\n");

    printf("This program is going to be a game-changer, trust me. It's designed to detect and block all incoming and outgoing network traffic that doesn't meet certain criteria.\n\n");

    printf("I was up all night working on this code, and I finally got it to compile without any errors! Want to see some of the code snippets that helped me build this beauty?\n\n");

    printf("\n/**************** Some Code Snippets Below ****************/\n\n");

    char rules[] = "ALLOW 192.168.1.0/24\n" 
                   "ALLOW 10.0.0.0/8\n"
                   "BLOCK 0.0.0.0/0\n";
    printf("Here's an example of some of the firewall rules I set up:\n");
    printf("%s\n", rules);

    char incoming_ip[] = "10.0.0.133";
    char rule1[] = "ALLOW 10.0.0.0/8";
    char rule2[] = "BLOCK 172.16.0.0/12";

    printf("Now let's see how my program handles incoming network traffic...\n\n");
    printf("Incoming IP address: %s\n", incoming_ip);

    if (strstr(rule1, incoming_ip) != NULL) {
        printf("Incoming IP address is allowed!\n");
    } else {
        printf("Incoming IP address is blocked!\n");
    }

    printf("\n");

    printf("What about this IP address?\n");
    printf("Incoming IP address: %s\n", incoming_ip);

    if (strstr(rule2, incoming_ip) != NULL) {
        printf("Incoming IP address is allowed!\n");
    } else {
        printf("Incoming IP address is blocked!\n");
    }

    printf("\n");

    printf("See how awesome this program is? It just saved the network from a potential security threat! I'm pretty sure I'm going to be famous for this one.\n\n");

    printf("So are you going to use my firewall program or what? It's the best one out there, I promise!\n\n");

    return 0;
}
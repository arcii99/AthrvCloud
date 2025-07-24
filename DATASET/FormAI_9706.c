//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the Happy Firewall Program!\n");
    printf("This program will help you block unwanted traffic and keep your system secure!\n");

    int choice;

    do {
        printf("\n1. Block all incoming traffic.\n");
        printf("2. Block all outgoing traffic.\n");
        printf("3. Block traffic from specific IP address.\n");
        printf("4. Block traffic to specific IP address.\n");
        printf("5. Exit.\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nBlocking all incoming traffic...\n");
                system("iptables -A INPUT -j DROP");
                system("iptables -A FORWARD -j DROP");
                printf("\nAll incoming traffic has been blocked!\n");
                break;

            case 2:
                printf("\nBlocking all outgoing traffic...\n");
                system("iptables -A OUTPUT -j DROP");
                printf("\nAll outgoing traffic has been blocked!\n");
                break;

            case 3:
                char ip[20];
                printf("\nEnter the IP address to block: ");
                scanf("%s", ip);
                printf("\nBlocking incoming traffic from %s...\n", ip);
                char command[50];
                sprintf(command, "iptables -A INPUT -s %s -j DROP", ip);
                system(command);
                printf("\nIncoming traffic from %s has been blocked!\n", ip);
                break;

            case 4:
                char ip2[20];
                printf("\nEnter the IP address to block: ");
                scanf("%s", ip2);
                printf("\nBlocking outgoing traffic to %s...\n", ip2);
                char command2[50];
                sprintf(command2, "iptables -A OUTPUT -d %s -j DROP", ip2);
                system(command2);
                printf("\nOutgoing traffic to %s has been blocked!\n", ip2);
                break;

            case 5:
                printf("\nExiting the Happy Firewall Program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
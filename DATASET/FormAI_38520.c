//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Happy Firewall!\n");
    char input[100];
    int isBlocked = 0;

    // Loop through user input until they type "exit"
    while (strcmp(input, "exit") != 0)
    {
        printf("Please enter a website you would like to block (or type 'exit' to quit):\n");
        fgets(input, 100, stdin);

        // Check if user input is already blocked
        if (strstr(input, "blocked") != NULL)
        {
            printf("This website is already blocked! Try another one.\n");
            continue;
        }

        // Block website and add to list of blocked sites
        char command[200];
        sprintf(command, "sudo iptables -A INPUT -p tcp --destination %s -j DROP", input);
        system(command);
        printf("%s has been blocked!\n", input);

        // Check if user wants to unblock a website
        printf("Would you like to unblock any websites(y/n)?\n");
        char response[2];
        fgets(response, 2, stdin);
        if (response[0] == 'y')
        {
            char website[100];
            printf("Please enter the website you would like to unblock:\n");
            fgets(website, 100, stdin);

            // Unblock website and remove from list of blocked sites
            char command[200];
            sprintf(command, "sudo iptables -D INPUT -p tcp --destination %s -j DROP", website);
            system(command);
            printf("%s has been unblocked!\n", website);
        }
    }

    // Unblock all sites before exiting
    system("sudo iptables -F");
    printf("All websites have been unblocked. Goodbye!\n");

    return 0;
}
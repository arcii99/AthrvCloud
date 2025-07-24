//FormAI DATASET v1.0 Category: Firewall ; Style: medieval
/* 
Medieval Firewall 
Features: 
- Protects castle network from malicious traffic
- Allows noble users to access restricted areas
- Logs all network activity for future investigation

By Sir Firewallius of House Code 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void log_activity(char *activity)
{
    FILE *log_file = fopen("castle_firewall_log.txt", "a");
    fprintf(log_file, "%s\n", activity);
    fclose(log_file);
}

int main()
{
    char *noble_users[] = {"SirLancelot", "LadyGuinevere", "KingArthur"}; // List of noble user names
    int num_noble_users = 3; // Number of noble user names in the list
    char input_buffer[256]; // Buffer for user input
    char *ip_address; // IP address of incoming traffic
    char *username; // Username of incoming traffic
    char *http_request; // HTTP request of incoming traffic
    int allowed = 0; // Flag for whether the traffic is allowed or not

    printf("Welcome to the Medieval Firewall!\n");

    while (1)
    {
        // Get input from user
        printf("Enter incoming traffic information. Press enter to stop.\n");
        printf("IP address: ");
        fgets(input_buffer, 256, stdin);
        if (strlen(input_buffer) <= 1) break; // Check for empty input
        ip_address = strdup(input_buffer); // Copy input to IP address variable

        printf("Username: ");
        fgets(input_buffer, 256, stdin);
        if (strlen(input_buffer) <= 1) break; // Check for empty input
        username = strdup(input_buffer); // Copy input to username variable

        printf("HTTP request: ");
        fgets(input_buffer, 256, stdin);
        if (strlen(input_buffer) <= 1) break; // Check for empty input
        http_request = strdup(input_buffer); // Copy input to HTTP request variable

        // Check if incoming traffic is from a noble user
        for (int i = 0; i < num_noble_users; i++)
        {
            if (strcmp(username, noble_users[i]) == 0)
            {
                allowed = 1; // Traffic is allowed
                break;
            }
        }

        // Check if incoming traffic is from malicious IP address
        if (strstr(ip_address, "192.168.1") != NULL)
        {
            allowed = 0; // Traffic is not allowed
        }

        // If traffic is allowed, print message and log activity
        if (allowed)
        {
            printf("Traffic from %s [%s] to %s is allowed.\n", username, ip_address, http_request);
            log_activity("Allowed traffic: ");
            log_activity(username);
            log_activity(ip_address);
            log_activity(http_request);
        }
        else // If traffic is not allowed, print message and log activity
        {
            printf("Traffic from %s [%s] to %s is not allowed.\n", username, ip_address, http_request);
            log_activity("Blocked traffic: ");
            log_activity(username);
            log_activity(ip_address);
            log_activity(http_request);
        }

        // Reset allowed status for next iteration
        allowed = 0;
    }

    printf("Goodbye!\n");

    return 0;
}
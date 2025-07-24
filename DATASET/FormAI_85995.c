//FormAI DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_IP_LENGTH 16
#define MAX_PORTS 20

void print_menu();
void get_ip(char *ip_address);
int valid_ip(char *ip_address);
void get_ports(int *ports);
void show_ports(int *ports);
int validate_port(char *port_str);

int main()
{
    char ip_address[MAX_IP_LENGTH];
    int ports[MAX_PORTS];
    int choice, valid_input;

    while(1)
    {
        print_menu();
        printf("Enter your choice: ");
        valid_input = scanf("%d", &choice);

        if(valid_input && choice >= 1 && choice <= 3)
        {
            switch(choice)
            {
                case 1:
                    printf("Enter IP address to block: ");
                    get_ip(ip_address);

                    if(valid_ip(ip_address))
                    {
                        printf("IP address %s has been blocked.\n\n", ip_address);
                        // Block the IP address using firewall code here
                        break;
                    }
                    else
                    {
                        printf("Invalid IP address entered. Please try again.\n\n");
                        break;
                    }

                case 2:
                    printf("Enter ports to block (comma separated): ");
                    get_ports(ports);
                    show_ports(ports);
                    // Block the ports using firewall code here
                    printf("The specified ports have been blocked successfully.\n\n");
                    break;

                case 3:
                    printf("Thank you for using our firewall program. Goodbye!\n");
                    exit(0);
            }
        }
        else
        {
            printf("Invalid choice entered. Please try again.\n\n");
            // Clear the input buffer
            scanf("%*[^\n]"); 
            scanf("%*c"); 
        }
    }
}

void print_menu()
{
    printf("Welcome to the Firewall Program!\n");
    printf("1. Block an IP address\n");
    printf("2. Block multiple ports\n");
    printf("3. Exit\n");
}

void get_ip(char *ip_address)
{
    char c;
    int valid_input;

    do
    {
        valid_input = scanf("%15s", ip_address);
        while((c = getchar()) != '\n' && c != EOF); // Ignore any additional characters in input buffer
    } while(!valid_input);
}

int valid_ip(char *ip_address)
{
    char num[MAX_IP_LENGTH];
    int i = 0, j = 0, dot_count = 0;

    while(ip_address[i])
    {
        if(ip_address[i] == '.')
        {
            num[j] = '\0';
            if(atoi(num) > 255)
                return 0;
            j = 0;
            dot_count++;
        }
        else
        {
            if(!isdigit(ip_address[i]))
                return 0;
            num[j++] = ip_address[i];
        }
        i++;
    }

    if(dot_count != 3)
        return 0;

    num[j] = '\0';
    if(atoi(num) > 255)
        return 0;

    return 1;
}

void get_ports(int *ports)
{
    char port_input[MAX_PORTS * 4]; // Maximum of 5 digits per port and a comma separator
    char *token;
    int i = 0;

    scanf("%s", port_input);
    token = strtok(port_input, ",");

    while(token != NULL && i < MAX_PORTS)
    {
        if(validate_port(token))
            ports[i++] = atoi(token);
        token = strtok(NULL, ",");
    }
}

void show_ports(int *ports)
{
    int i;
    printf("The following ports will be blocked: ");
    for(i = 0; i < MAX_PORTS && ports[i] != 0; i++)
        printf("%d ", ports[i]);
    printf("\n");
}

int validate_port(char *port_str)
{
    int i;

    for(i = 0; i < strlen(port_str); i++)
    {
        if(!isdigit(port_str[i]))
            return 0;
    }

    if(atoi(port_str) < 1 || atoi(port_str) > 65535)
        return 0;

    return 1;
}
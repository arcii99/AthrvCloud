//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function to check if the given IP is in the blocked IP list
int isBlocked(char *ip, char *blockedList[], int blockedListLength)
{
    for(int i=0; i<blockedListLength; i++)
    {
        if(strcmp(ip, blockedList[i]) == 0)
            return 1;
    }
    return 0;
}

//function to log the intrusion
void logIntrusion(char *ip, char *message)
{
    //open the log file
    FILE *logFile = fopen("intrusion.log", "a");
    if(logFile == NULL)
    {
        printf("Error opening log file!\n");
        exit(1);
    }

    //write the intrusion details to the log file
    fprintf(logFile, "IP: %s\tMessage: %s\n", ip, message);
    
    //close the log file
    fclose(logFile);
}

int main()
{
    char *blockedIPs[] = {"192.168.0.1", "10.0.0.2", "172.16.0.3"};    //list of blocked IP addresses
    int blockedIPCount = 3;    //number of blocked IP addresses

    int attemptCount = 0;    //number of login attempts
    char ip[16];    //variable to store the IP address of the login attempt
    char username[20];    //variable to store the username of the login attempt
    char password[20];    //variable to store the password of the login attempt

    //interactive login prompt
    printf("Enter IP address: ");
    scanf("%15s", ip);
    printf("Enter username: ");
    scanf("%19s", username);
    printf("Enter password: ");
    scanf("%19s", password);

    //check if the IP is in the blocked IP list
    if(isBlocked(ip, blockedIPs, blockedIPCount))
    {
        printf("This IP is blocked!\n");
        return 1;
    }

    //check if the login credentials are correct
    if(strcmp(username, "admin") == 0 && strcmp(password, "password") == 0)
        printf("Login successful.\n");
    else
    {
        printf("Incorrect username or password.\n");
        attemptCount++;

        //log the intrusion attempt if there have been 3 or more incorrect attempts
        if(attemptCount >= 3)
        {
            logIntrusion(ip, "Multiple failed login attempts.");
            printf("Intrusion attempt logged.\n");
        }
    }

    return 0;
}
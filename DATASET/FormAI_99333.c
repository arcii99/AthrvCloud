//FormAI DATASET v1.0 Category: Socket programming ; Style: imaginative
/* Welcome to the world of programming! 
 * In this program, we will learn how to create a C socket which gives the user a magic genie-like assistant. 
 * This assistant will be able to answer any questions the user has, just like a real genie! 
 * Let's begin by creating a socket that will allow the user to connect to the genie. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) 
{
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *genie = "Genie: ", buffer[1024] = {0}; 

    // Creating socket file descriptor 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("Socket creation error\n"); 
        return -1; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
    
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("Invalid address/ Address not supported\n"); 
        return -1; 
    } 

    // Connecting to the Genie 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("Connection Failed\n"); 
        return -1; 
    } 
    
    // Begin the conversation with the Genie 
    printf("Welcome to the Genie's lair!\n");
    printf("Please enter your question:\n");

    while(1) 
    {
        // Read the user's question 
        scanf("%[^\n]%*c", buffer);

        // Send the question to the Genie 
        send(sock , buffer , strlen(buffer) , 0 ); 

        // Wait for the response from the Genie 
        valread = read( sock , buffer, 1024);

        // Print the Genie's response 
        printf("%s%s\n", genie, buffer );
        
        // Prompt the user to ask another question 
        printf("Do you have another question for the Genie? (yes or no)\n");
        scanf("%s", buffer);
        
        // If the user says no, terminate the program 
        if (strcmp(buffer, "no") == 0) 
        {
            printf("Thank you for visiting the Genie's lair!\n");
            break;
        }
        else 
        {
            printf("Please enter your next question:\n");
        }
    }
    return 0; 
}
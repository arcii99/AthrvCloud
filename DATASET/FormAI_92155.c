//FormAI DATASET v1.0 Category: Client Server Application ; Style: rigorous
/*
 * Name: Unique C Client Server Application
 * Author: [Your Name Here]
 * Date: [Date]
 * Description: This is a simple C client-server application that allows the client to request a string from the server. 
 *              The server stores a list of pre-defined strings and returns the requested string to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_STRINGS 10
#define MAX_STRING_LENGTH 50

/* Function to initialize the list of strings */
void init_strings(char strings[MAX_STRINGS][MAX_STRING_LENGTH])
{
    strncpy(strings[0], "Hello", MAX_STRING_LENGTH);
    strncpy(strings[1], "Goodbye", MAX_STRING_LENGTH);
    strncpy(strings[2], "Thank you", MAX_STRING_LENGTH);
    strncpy(strings[3], "Please", MAX_STRING_LENGTH);
    strncpy(strings[4], "Sorry", MAX_STRING_LENGTH);
    strncpy(strings[5], "Excuse me", MAX_STRING_LENGTH);
    strncpy(strings[6], "How are you?", MAX_STRING_LENGTH);
    strncpy(strings[7], "What is your name?", MAX_STRING_LENGTH);
    strncpy(strings[8], "Where are you from?", MAX_STRING_LENGTH);
    strncpy(strings[9], "What time is it?", MAX_STRING_LENGTH);
}

/* Function to handle errors */
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

/* Main function - server */
int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, n;
    char buffer[MAX_STRING_LENGTH];
    char strings[MAX_STRINGS][MAX_STRING_LENGTH];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    /* Initialize the list of strings */
    init_strings(strings);

    /* Check if port number was provided as argument */
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    /* Create TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    /* Set server address */
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Bind socket to server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR on binding");

    /* Listen for incoming connections */
    listen(sockfd, 5);

    /* Accept incoming connections */
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
        error("ERROR on accept");

    /* Receive requests from client and send responses */
    while (1) {
        /* Clear buffer */
        memset(buffer, 0, MAX_STRING_LENGTH);

        /* Receive request from client */
        n = read(newsockfd, buffer, MAX_STRING_LENGTH);
        if (n < 0) 
            error("ERROR reading from socket");

        /* Check if client has ended the connection */
        if (n == 0) {
            close(newsockfd);
            break;
        }

        /* Find requested string in list and send it to client */
        for (int i = 0; i < MAX_STRINGS; i++) {
            if (strncmp(buffer, strings[i], strlen(strings[i])) == 0) {
                n = write(newsockfd, strings[i], strlen(strings[i]));
                if (n < 0) 
                    error("ERROR writing to socket");
                break;
            }
        }
    }

    /* Close listening socket */
    close(sockfd);

    return 0; 
}
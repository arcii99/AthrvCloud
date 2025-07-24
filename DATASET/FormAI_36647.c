//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
/* Romeo and Juliet Client Server Application */
/* Written by: [Your Name] */

/* In fair Verona, where we lay our scene */
/* From ancient grudge break to new mutiny */
/* Where civil blood makes civil hands unclean */
/* From forth the fatal loins of these two foes */
/* A pair of star-cross'd lovers take their life */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char message[1024] = {0};

    /* The name of the program is located at argv[0] */
    printf("Welcome to the Romeo and Juliet Client Server Application!\n");
    printf("This program was created by %s.\n\n", argv[0]);

    /* Creating socket file descriptor */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    /* Filling server information */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    /* Convert IPv4 and IPv6 addresses from text to binary form */
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter 'y' to send a message to Romeo or 'n' to send a message to Juliet: ");

    fgets(buffer, 1024, stdin); /* Read input from the user */

    if (buffer[0] == 'y') {
        sprintf(message, "Romeo, wherefore art thou?");
    } else if (buffer[0] == 'n') {
        sprintf(message, "Juliet, wherefore art thou?");
    } else {
        sprintf(message, "I do not understand your input.");
    }

    send(sockfd, message, strlen(message), 0);
    printf("Message sent!\n");

    /* Receive a message from the server */
    memset(buffer, 0, sizeof(buffer)); /* Clear the buffer */
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    return 0;
}
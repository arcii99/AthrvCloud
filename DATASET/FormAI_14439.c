//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void deductPoints(int* points, char* culprit) {
    if (strcmp(culprit, "Professor Moriarty") == 0) {
        *points = *points - 10;
        printf("Points deducted! The culprit was Professor Moriarty.\n");
    } else if (strcmp(culprit, "Colonel Sebastian Moran") == 0) {
        *points = *points - 5;
        printf("Points deducted! The culprit was Colonel Sebastian Moran.\n");
    } else {
        printf("Congratulations! Your deduction was correct. The culprit was indeed %s.\n", culprit);
    }
}

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *inquiry = "Are you the real Sherlock Holmes?";
    char buffer[1024] = {0};
    char *culprit = "Professor James Moriarty";
    int points = 20;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Communicate with server
    send(sock, inquiry, strlen(inquiry), 0);
    printf("Inquiry sent: %s\n", inquiry);
    valread = read(sock, buffer, 1024);

    if (strcmp(buffer, "Yes, I am the real Sherlock Holmes.") == 0) {
        printf("%s\n", buffer);
        printf("You have %d points. Now, present a deduction on the following case:\n", points);
        printf("Professor James Moriarty was found dead in his study. \nHis body was lying on the floor with a gunshot wound to the chest. \nThe gun was lying on the table next to the body and there was a suicide note on the table.\n");

        char* deduction = (char*)malloc(sizeof(char) * 100);
        printf("Who do you think is the real culprit? ");
        scanf("%[^\n]", deduction);

        deductPoints(&points, deduction);

        printf("You have %d points left.\n", points);
    } else {
        printf("%s\n", buffer);
    }

    close(sock);
    return 0;
}
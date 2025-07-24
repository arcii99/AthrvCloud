//FormAI DATASET v1.0 Category: Client Server Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // Assigning values to serv_addr
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Messaging system initialization
    time_t t;
    srand((unsigned) time(&t));
    char greetings[5][50] = {"Hello there!", "Greetings!", "Salutations!", "Howdy!", "Hey!"};
    char message[5][50] = {"What's up?", "How are you?", "How's it going?", "Anything new?", "What have you been up to?"};
    
    // Sending and receiving messages in an infinite loop
    while (1) {
        // Sending a random greeting
        char greeting[50];
        strcpy(greeting, greetings[rand() % 5]);
        send(sock, greeting, strlen(greeting), 0);

        // Receiving the server's response and printing it
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);

        // Sending a random message
        char msg[50];
        strcpy(msg, message[rand() % 5]);
        send(sock, msg, strlen(msg), 0);

        // Receiving the server's response and printing it
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);

        // Waiting for some time to pass before repeating the loop
        sleep(2);
    }
  
    return 0;
}
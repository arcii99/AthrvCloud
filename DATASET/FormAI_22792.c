//FormAI DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
// "The Case of the Missing Connection"
// A Sherlock Holmes style networking program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];

    // Step 1: Gather Clues
    printf("Detective, we have received a tip that a critical connection has gone missing.\n");
    printf("We don't have much information, but our sources say that the perpetrator was last seen accessing the connection from a remote location.\n");
    printf("We have tracked the connection to IP address 192.168.1.1, port 8080.\n");
    printf("We need you to connect to that address and retrieve any evidence you can find.\n\n");
    sleep(2);

    // Step 2: Investigate the Scene
    printf("You arrive at the scene and take a closer look at the connection.\n");
    printf("It appears that the connection has been tampered with. The data seems to have been encrypted.\n");
    printf("You notice that the missing connection is using HTTP protocol.\n");
    printf("You'll need to send an HTTP request to retrieve the information.\n\n");
    sleep(2);

    // Step 3: Perform Forensic Analysis
    printf("You start your forensic analysis by connecting to the address...\n");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "192.168.1.1", &serv_addr.sin_addr) <= 0 ) {
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }

    printf("Connected to the address successfully!\n");
    printf("Please enter an HTTP request to send:\n");
    fgets(message, BUFFER_SIZE, stdin);

    // Step 4: Decipher the Evidence
    send(sock, message, strlen(message), 0);
    valread = read(sock, buffer, BUFFER_SIZE);
    printf("Server Response:\n%s\n", buffer);

    printf("Detective, we have received the following data:\n");
    printf("%s\n", buffer);
    printf("It's encrypted using XOR encryption. We'll need to decipher it with a key.\n");
    printf("The key is 'fibonacci'. Please enter it to decode the message.\n");
    scanf("%s", message);

    // Decrypt message using XOR
    int keyLength = strlen(message);
    for (int i = 0; i < valread; i++) {
        buffer[i] = buffer[i] ^ message[i % keyLength];
    }

    printf("Decrypted message:\n%s\n\n", buffer);

    // Step 5: Solve the Case
    printf("Detective, we have reviewed the evidence and it seems that the missing connection was actually being used by a rival company to gather private information.");
    printf("Thanks to your quick analysis, we were able to catch them in the act and prevent any further damage.\n");
    printf("This case is closed. Good job, Detective!\n");

    close(sock);
    return 0;
}
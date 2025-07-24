//FormAI DATASET v1.0 Category: Socket programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

// Statistical C Socket Programming example

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[1024], server_reply[2000];
    time_t t1, t2;
    double t_diff;
    int count = 0, total_count = 0;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }

    // Prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server address
    server.sin_family = AF_INET;
    server.sin_port = htons(8888); // Server port

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    // Send some statistics to the server
    while (total_count < 10000) {  // Send 10000 messages
        // Generate a random number between 1 and 50
        int number = rand() % 50 + 1; 
        sprintf(message, "%d", number);

        // Record the current time
        t1 = time(NULL);

        // Send the message to the server
        if (send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        // Receive a reply from the server
        if (recv(sock, server_reply, 2000, 0) < 0) {
            puts("recv failed");
            break;
        }

        // Record the current time and calculate the time difference
        t2 = time(NULL);
        t_diff = difftime(t2, t1);

        // Print the server reply and the time difference
        printf("Server replied: %s\n", server_reply);
        printf("Time to receive server reply: %f seconds\n", t_diff);

        // Increment the count of valid replies
        if (strcmp(server_reply, "Valid") == 0) { 
            count++;
        }

        // Increment the total count of messages sent
        total_count++;

        // Sleep for a random amount of time between 1 to 3 seconds
        sleep(rand() % 3 + 1);
    }

    // Print the statistics of the messages sent
    printf("\nMessages sent: %d\n", total_count);
    printf("Valid messages received: %d\n", count);
    printf("Invalid messages received: %d\n", total_count - count);
    printf("Success rate: %.2f%%\n\n", (double)count / total_count * 100);

    // Close the socket and exit
    close(sock);
    return 0;
}
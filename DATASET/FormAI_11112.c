//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    time_t begin, end;
    float time_elapsed;

    // initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    // set up server address
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
        error("Connection failed");

    // send message to server
    memset(buffer, '\0', sizeof(buffer));
    strcpy(buffer, "test");
    begin = time(NULL);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    // receive message from server
    memset(buffer, '\0', sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0)
        error("ERROR reading from socket");

    // calculate time elapsed and speed
    end = time(NULL);
    time_elapsed = difftime(end, begin);
    float speed = (float) strlen(buffer) / time_elapsed;

    // display results
    printf("Time elapsed: %.1f seconds\n", time_elapsed);
    printf("Download speed: %.2f Mbps\n", speed);

    close(sockfd);
    return 0;
}
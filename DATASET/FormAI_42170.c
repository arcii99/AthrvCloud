//FormAI DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 9000
#define MAX_MSG_LEN 1000

void log_event(char *msg);

int main(int argc, char *argv[]){
    struct sockaddr_in addr;
    int fd, count;
    char buffer[MAX_MSG_LEN];
    fd_set inputs, outputs;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0){
        perror("Error opening socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htons(INADDR_ANY);

    if(bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        perror("Error binding socket");
        exit(1);
    }

    if(listen(fd, 5) < 0){
        perror("Error listening for connections");
        exit(1);
    }

    FD_ZERO(&inputs);
    FD_ZERO(&outputs);
    FD_SET(fd, &inputs); // Add listening socket to inputs

    printf("Waiting for connections...\n");

    while(1){
        int numfd = select(FD_SETSIZE, &inputs, &outputs, NULL, NULL);
        if(numfd < 0){
            perror("Error in select");
            exit(1);
        }

        if(FD_ISSET(fd, &inputs)){
            struct sockaddr_in remote_addr;
            socklen_t remote_addr_len = sizeof(remote_addr);
            int client_fd;

            client_fd = accept(fd, (struct sockaddr*)&remote_addr, &remote_addr_len);
            if(client_fd < 0){
                perror("Error accepting new connection");
                exit(1);
            }

            printf("Connection from %s:%d\n", inet_ntoa(remote_addr.sin_addr), ntohs(remote_addr.sin_port));
            FD_SET(client_fd, &inputs); // Add client_fd to inputs
        }

        for(int i=fd+1; i<=FD_SETSIZE; i++){
            if(FD_ISSET(i, &inputs)){
                count = recv(i, buffer, MAX_MSG_LEN, 0);
                buffer[count] = '\0';
                if(count == 0){ //Remote client has closed the connection
                    printf("Connection closed\n");
                    close(i);
                    FD_CLR(i, &inputs);
                }
                else{
                    log_event(buffer);
                }
            }
        }
    }
    return 0;
}

void log_event(char *msg){
    time_t raw_time;
    struct tm *timeinfo;
    char time_str[80];

    time(&raw_time);
    timeinfo = localtime(&raw_time);

    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Open file in append mode
    FILE* f = fopen("log.txt", "a");

    // Write the log message in the required format
    fprintf(f, "[%s] %s\n", time_str, msg);

    fclose(f);
}
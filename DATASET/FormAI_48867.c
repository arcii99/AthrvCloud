//FormAI DATASET v1.0 Category: System process viewer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define constants
#define MAX_BUFFER_SIZE 1024
#define MAX_PROCESS_INFO_SIZE 2048
#define SERVER_PORT 8888
#define MAX_CONNECTIONS 10

// Define structure for process information
typedef struct {
    pid_t pid;
    char name[MAX_BUFFER_SIZE];
    long int vsize;
    long int rss;
} process_info;

// Define function for getting process information
process_info get_process_info(pid_t pid) {
    // Initialize process information struct
    process_info pinfo;
    pinfo.pid = pid;

    // Get process name
    char fname[MAX_BUFFER_SIZE];
    sprintf(fname, "/proc/%d/cmdline", pid);

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char name[MAX_BUFFER_SIZE];
    int i = 0;

    while (fgets(name, MAX_BUFFER_SIZE - i, fp) != NULL) {
        strcat(pinfo.name, name);
        i = strlen(pinfo.name);
    }

    fclose(fp);

    // Get process memory information
    sprintf(fname, "/proc/%d/statm", pid);

    fp = fopen(fname, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    long int vsize, rss;
    fscanf(fp, "%ld %ld", &vsize, &rss);

    pinfo.vsize = vsize * sysconf(_SC_PAGESIZE);
    pinfo.rss = rss * sysconf(_SC_PAGESIZE);

    fclose(fp);

    // Return process information struct
    return pinfo;
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Clear address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Set address structure
    portno = SERVER_PORT;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, MAX_CONNECTIONS);

    // Accept incoming connections
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("Error on accept");
            exit(EXIT_FAILURE);
        }

        // Fork a child process to handle the connection
        pid_t pid = fork();

        if (pid == 0) {
            // Child process

            char cli_ip[MAX_BUFFER_SIZE];
            inet_ntop(AF_INET, &cli_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);

            printf("Connection accepted from %s:%d\n", cli_ip, ntohs(cli_addr.sin_port));

            // Process client requests
            while (1) {
                // Clear buffer
                bzero(buffer, MAX_BUFFER_SIZE);

                // Read client message
                n = read(newsockfd, buffer, MAX_BUFFER_SIZE - 1);

                if (n < 0) {
                    perror("Error reading from socket");
                    exit(EXIT_FAILURE);
                }

                if (n == 0) {
                    printf("Connection closed by client\n");
                    break;
                }

                // Process client request
                buffer[n] = '\0';

                if (strcmp(buffer, "ps\n") == 0) {
                    // Get list of running processes
                    FILE *fp;
                    char command[MAX_BUFFER_SIZE];
                    sprintf(command, "ps axo pid");
                    fp = popen(command, "r");

                    if (fp == NULL) {
                        perror("Failed to execute command");
                        exit(EXIT_FAILURE);
                    }

                    // Process each process info and send to client
                    char output[MAX_PROCESS_INFO_SIZE];
                    int offset = 0;
                    int pid;
                    process_info pinfo;

                    while (fscanf(fp, "%d", &pid) != EOF) {
                        pinfo = get_process_info(pid);
                        offset += sprintf(output + offset, "%d %s %ld %ld\n", pinfo.pid, pinfo.name, pinfo.vsize, pinfo.rss);
                    }

                    // Send process info to client
                    n = write(newsockfd, output, strlen(output));

                    if (n < 0) {
                        perror("Error writing to socket");
                        exit(EXIT_FAILURE);
                    }

                    pclose(fp);

                } else {
                    // Invalid request
                    n = write(newsockfd, "Invalid request\n", 17);

                    if (n < 0) {
                        perror("Error writing to socket");
                        exit(EXIT_FAILURE);
                    }
                }
            }

            // Close connection socket
            close(newsockfd);

            exit(EXIT_SUCCESS);

        } else {
            // Parent process
            close(newsockfd);
        }
    }

    // Close listening socket
    close(sockfd);

    return 0;
}
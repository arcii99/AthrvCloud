//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, pid;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
       error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) 
            error("ERROR on accept");

        pid = fork();
        if (pid < 0)
            error("ERROR on fork");

        if (pid == 0)  {
            close(sockfd);
            do_shell(newsockfd);
            exit(0);
        }
        else close(newsockfd);
    } /* end of while */
    return 0; /* we never get here */
}

void do_shell(int sock) {
    int n;
    char buffer[256];
    bzero(buffer,256);

    while (1) {
        n = read(sock,buffer,255);
        if (n < 0) 
           error("ERROR reading from socket");
        printf("Command entered: %s",buffer);

        /* fork a child process */
        int pid = fork();

        if (pid < 0) {
            error("ERROR on fork");
        }
        else if (pid == 0) {
            /* this is the child process */
            /* execute the command */
            char *args[] = {"/bin/sh", "-c", buffer, NULL};
            int ret = execvp(args[0], args);
            if (ret < 0) {
                fprintf(stderr, "ERROR: exec failed\n");
            }
            exit(0);
        }
        else {
            /* this is the parent process */
            /* wait for child to complete */
            int status;
            wait(&status);
            printf("Command completed\n");

            /* send output back to client */
            char *output = "Command completed\n";
            n = write(sock,output,strlen(output));
            if (n < 0) 
                 error("ERROR writing to socket");
        }
    }
}
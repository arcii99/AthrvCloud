//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define MAXDATASIZE 1024
#define MAX_BUFFER 2048
#define SERVICE_PORT 50019		

void sig_alrm(int signo);
int write_to_file(char * buffer, int size);

int main(int argc, char *argv[]){
	
    if (argc < 2){ 						//checks if the correct number of arguments are provided
        printf("Usage: ./qosmon <IPaddress>\n");
        exit(1);
    }

    struct sockaddr_in servaddr;
    int sockfd, size, status, change;
    char buffer[MAXDATASIZE];
    char logfile[16];
    char * server_IP = argv[1];
	
    sockfd = socket(AF_INET, SOCK_STREAM, 0);			//creating a socket on client to connect to server

    if(sockfd < 0){
        perror("Creating socket error\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;					//family
    servaddr.sin_port = htons(SERVICE_PORT);			//htons sets the port to correct byte order

    if((inet_pton(AF_INET, server_IP, &servaddr.sin_addr)) <= 0){		//converts IP address from text to network format
        perror("inet_pton error");
        exit(1);
    }

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){		//connects to server
        perror("Connection error\n");
        exit(1);
    }

    printf("Connected to server.\n");

    snprintf(logfile, 16, "test.log");			//saving the collected information to this file

    signal(SIGALRM, sig_alrm);
    alarm(5);							//set an alarm to 5 seconds
	
    while(1){
        size = read(sockfd, buffer, MAXDATASIZE-1);			//reading from the server

        if(size < 0){
            perror("Read error\n");
            exit(1);
        }
        else if(size == 0){
            printf("Connection closed.\n");
            break;
        }

        status = write_to_file(buffer, size);
        if(status == 0){
            printf("Failed to write to log file.\n");
            continue;
        }
        else{
            printf("Written to log file.\n");
        }

        bzero(buffer, sizeof(buffer));
    }

    close(sockfd);
    printf("Connection closed.\n");
    return 0;
}

//sending an alarm to the server after a certain time interval to check the network QoS
void sig_alrm(int signo){
    int sockfd, change;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        perror("Creating socket error\n");
        exit(1);
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    char * server_IP = "127.0.0.1";						
    servaddr.sin_port = htons(60000);

    if((inet_pton(AF_INET, server_IP, &servaddr.sin_addr)) <= 0){
        perror("inet_pton error");
        exit(1);
    }

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("Connection error\n");
        exit(1);
    }

    printf("Request sent to server.\n");

    if(write(sockfd, "QoS Check Request from Client", strlen("QoS Check Request from Client")) < 0) {			
        perror("Write error");
        close(sockfd);
        exit(1);
    }

    close(sockfd);
    printf("QoS request sent to server.\n");
    signal(SIGALRM, sig_alrm);
    alarm(5);					//set next alarm
}

//writing collected data to file
int write_to_file(char * buffer, int size){
    int fd, status;

    fd = open("test.log", O_CREAT | O_WRONLY | O_APPEND, 0600);
    if(fd < 0){
        perror("Open Error");
        return 0;
    }

    status = write(fd, buffer, size);
    if(status < 0){
        perror("Write error\n");
        return 0;
    }

    close(fd);
    return 1;
}
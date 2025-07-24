//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define MAX_DATA_SIZE 2048

int main(int argc , char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <Server-IP> <Port> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Welcome to the FTP Client program!\n");

    char buffer[MAX_DATA_SIZE];
    int sockfd, n;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address or Address not supported! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Connecting to the FTP server at %s:%s....\n", argv[1], argv[2]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP Server Successfully!\n");

    printf("\n\t\t-------------------FTP Client-------------------\n");
    printf("\n\nEnter \"help\" to list the available FTP commands.");
    printf("\n\n> ");

    while (1) {
        memset(buffer, 0, MAX_DATA_SIZE);
        fgets(buffer, MAX_DATA_SIZE, stdin);

        if(strlen(buffer) <= 1) {
            continue;
        }

        if (strcmp(buffer, "quit\n") == 0) {
            printf("\nGood bye! Thank you for using the FTP Client program.\n");
            exit(EXIT_SUCCESS);
        }

        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            printf("\nWrite Failed! %s", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, "get\n") == 0) {
            char filename[MAX_DATA_SIZE];
            printf("\nEnter the file name: ");
            scanf("%s", filename);
            getchar(); // To get rid of the \n from the stdin buffer

            if (write(sockfd, filename, strlen(filename)) < 0) {
                printf("\nWrite Failed! %s", strerror(errno));
                exit(EXIT_FAILURE);
            }

            memset(buffer, 0, MAX_DATA_SIZE);
            if ((n = read(sockfd, buffer, MAX_DATA_SIZE - 1)) > 0) {
                if (strcmp(buffer, "Error") == 0) {
                    printf("\nThe file %s does not exist.\n", filename);
                    continue;
                }else {
                    FileRecieve(sockfd,buffer);
                }
            } else {
                if (n < 0)
                    printf("\nRead Failed! %s", strerror(errno));
                else
                    printf("Server has closed the connection abruptly.\n");
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(buffer, "put\n") == 0){
            printf("Enter the file name: ");
            char filename[MAX_DATA_SIZE];
            scanf("%s", filename);
            getchar(); // To get rid of the \n from the stdin buffer

            FileSend(sockfd,filename);
        } else {
            memset(buffer, 0, MAX_DATA_SIZE);
            if ((n = read(sockfd, buffer, MAX_DATA_SIZE - 1)) > 0) {
                printf("%s\n", buffer);
            } else {
                if (n < 0)
                    printf("\nRead Failed! %s", strerror(errno));
                else
                    printf("Server has closed the connection abruptly.\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("\n> ");
    }

    return 0;
}

void FileSend(int sockfd, char *filename) {
    char buf[MAX_DATA_SIZE];
    FILE *fp;
    size_t read_size;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found!\n");
        write(sockfd,"Error",strlen("Error"));

        return;
    }

    write(sockfd,filename,strlen(filename));
    memset(buf,0,MAX_DATA_SIZE);

    while((read_size = fread(buf,1,sizeof(buf),fp)) > 0) {
        if(write(sockfd,buf,read_size) < 0) {
            printf("\nWrite Failed! %s\n", strerror(errno));
            exit(1);
        }

        memset(buf,0,MAX_DATA_SIZE);
    }

    fclose(fp);
    printf("Successfully transferred %s to server!\n", filename);
}

void FileRecieve(int sockfd, char *filename) {
    char buf[MAX_DATA_SIZE];
    FILE *fp;
    size_t total_size = 0;
    ssize_t read_size;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Failed to create a file! %s\n", strerror(errno));
        exit(1);
    }

    while ((read_size = read(sockfd,buf,MAX_DATA_SIZE)) > 0) {
        if (read_size < 0) {
            printf("\nRead Failed! %s\n", strerror(errno));
            fclose(fp);

            exit(1);
        }

        total_size += read_size;

        if (fwrite(buf,1,read_size,fp) != read_size) {
            printf("\nWrite Failed! %s\n", strerror(errno));
            fclose(fp);

            exit(1);
        }

        if (total_size >= (MAX_DATA_SIZE * 10)) {
            printf("\nFile too large.\n");
            fclose(fp);

            return;
        }

        memset(buf,0,MAX_DATA_SIZE);
    }

    fclose(fp);
    printf("Successfully transferred %s from server! Size is %d bytes.\n", filename, total_size);
}
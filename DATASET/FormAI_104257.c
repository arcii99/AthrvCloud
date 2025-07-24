//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];
    char cmd[BUF_SIZE];
    char input[BUF_SIZE];
    char filename[BUF_SIZE];
    int data_sock;
    char data_buf[BUF_SIZE];
    int n;
    FILE *fp;
    int file_size;
    int remain_size;
    int len;

    if((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(PORT);
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    bzero(buf, BUF_SIZE);
    read(sock, buf, BUF_SIZE); // read welcome message
    printf("%s", buf);

    printf("Please enter username: ");
    fgets(input, BUF_SIZE, stdin);
    sprintf(cmd, "USER %s", input);
    write(sock, cmd, strlen(cmd));
    bzero(buf, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("%s", buf);

    printf("Please enter password: ");
    fgets(input, BUF_SIZE, stdin);
    sprintf(cmd, "PASS %s", input);
    write(sock, cmd, strlen(cmd));
    bzero(buf, BUF_SIZE);
    read(sock, buf, BUF_SIZE);
    printf("%s", buf);

    while(1) {
        printf("ftp> ");
        fgets(input, BUF_SIZE, stdin);
        len = strlen(input);
        if(input[len-1] == '\n') {
            input[len-1] = '\0';
        }
        if(strncmp(input, "quit", 4) == 0) {
            sprintf(cmd, "QUIT");
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            printf("%s", buf);
            break;
        } else if(strncmp(input, "pwd", 3) == 0) {
            sprintf(cmd, "PWD");
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            printf("%s", buf);
        } else if(strncmp(input, "cd", 2) == 0) {
            sprintf(cmd, "CWD %s", input+3);
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            printf("%s", buf);
        } else if(strncmp(input, "ls", 2) == 0) {
            sprintf(cmd, "PASV");
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            int port1, port2, port;
            if(sscanf(buf, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d).", &port1, &port2) != 2) {
                perror("sscanf");
                exit(1);
            }
            port = port1*256 + port2;
            if((data_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
            }
            memset(&serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
            serv_addr.sin_port = htons(port);
            if(connect(data_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
                perror("connect");
                exit(1);
            }
            sprintf(cmd, "LIST");
            write(sock, cmd, strlen(cmd));
            bzero(data_buf, BUF_SIZE);
            while((n = read(data_sock, data_buf, BUF_SIZE)) > 0) {
                printf("%s", data_buf);
                bzero(data_buf, BUF_SIZE);
            }
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            printf("%s", buf);
        } else if(strncmp(input, "get", 3) == 0) {
            sprintf(cmd, "SIZE %s", input+4);
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            if(strncmp(buf, "550", 3) == 0) {
                printf("Error: file not found.\n");
                memset(&filename, 0, sizeof(filename));
                continue;
            }
            sscanf(buf, "213 %d", &file_size);
            sprintf(cmd, "PASV");
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            int port1, port2, port;
            if(sscanf(buf, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d).", &port1, &port2) != 2) {
                perror("sscanf");
                exit(1);
            }
            port = port1*256 + port2;
            if((data_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
            }
            memset(&serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
            serv_addr.sin_port = htons(port);
            if(connect(data_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
                perror("connect");
                exit(1);
            }
            sprintf(cmd, "RETR %s", input+4);
            write(sock, cmd, strlen(cmd));
            fp = fopen(input+4, "wb");
            remain_size = file_size;
            while((n = read(data_sock, data_buf, BUF_SIZE)) > 0) {
                fwrite(data_buf, n, 1, fp);
                remain_size -= n;
                if(remain_size < 1) break;
                bzero(data_buf, BUF_SIZE);
            }
            fclose(fp);
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            printf("%s", buf);
        } else if(strncmp(input, "put", 3) == 0) {
            if(access(input+4, F_OK) != 0) {
                printf("Error: file not found.\n");
                memset(&filename, 0, sizeof(filename));
                continue;
            }
            fp = fopen(input+4, "rb");
            fseek(fp, 0, SEEK_END);
            file_size = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            sprintf(cmd, "TYPE I");
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            sprintf(cmd, "PASV");
            write(sock, cmd, strlen(cmd));
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            int port1, port2, port;
            if(sscanf(buf, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d).", &port1, &port2) != 2) {
                perror("sscanf");
                exit(1);
            }
            port = port1*256 + port2;
            if((data_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
            }
            memset(&serv_addr, 0, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
            serv_addr.sin_port = htons(port);
            if(connect(data_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
                perror("connect");
                exit(1);
            }
            sprintf(cmd, "STOR %s", input+4);
            write(sock, cmd, strlen(cmd));
            remain_size = file_size;
            while((n = fread(data_buf, 1, BUF_SIZE, fp)) > 0) {
                write(data_sock, data_buf, n);
                remain_size -= n;
                if(remain_size < 1) break;
                bzero(data_buf, BUF_SIZE);
            }
            fclose(fp);
            bzero(buf, BUF_SIZE);
            read(sock, buf, BUF_SIZE);
            printf("%s", buf);
        }
    }

    close(sock);

    return 0;
}
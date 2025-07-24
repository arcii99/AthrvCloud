//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#define PORT 21 //FTP port

int main(int argc, char const *argv[])
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char user[100], pass[100], command[100], ftpfile[100];
    printf("----------------------------\n");
    printf("THE WORLD AFTER APOCALYPSE\n");
    printf("----------------------------\n");
    printf("WELCOME TO FTP CLIENT PROGRAM\n");

    //create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    //convert IP address in text format to binary format
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    //connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    //get server response
    read(sock, buffer, 1024);
    printf("%s\n", buffer);

    //get user name and password from user
    printf("Username: ");
    scanf("%s", user);
    send(sock, user, strlen(user), 0);

    read(sock, buffer, 1024);
    printf("%s\n", buffer);

    printf("Password: ");
    scanf("%s", pass);
    send(sock, pass, strlen(pass), 0);

    read(sock, buffer, 1024);
    printf("%s\n", buffer);

    while(1){
      //get command from user
      printf("ftp> ");
      scanf("%s", command);
      if(strcmp(command, "quit") == 0){
        send(sock, command, strlen(command), 0);
        read(sock, buffer, 1024);
        printf("%s\n", buffer);
        break;
      }
      if(strcmp(command, "get") == 0){
        printf("File name: ");
        scanf("%s", ftpfile);
        //send the command to server along with filename
        send(sock, command, strlen(command), 0);
        send(sock, ftpfile, strlen(ftpfile), 0);
        read(sock, buffer, 1024);
        if(strcmp(buffer, "File not found") == 0){
          printf("%s\n", buffer);
          continue;
        }
        printf("%s\n", buffer);

        //get the file
        memset(buffer, 0, sizeof(buffer));
        FILE *fp;
        fp = fopen(ftpfile, "w");
        while(read(sock, buffer, 1024)){
          fwrite(buffer, 1, 1024, fp);
          memset(buffer, 0, sizeof(buffer));
        }
        fclose(fp);
        printf("File downloaded successfully\n");
      }
      if(strcmp(command, "put") == 0){
        printf("File name: ");
        scanf("%s", ftpfile);
        FILE *fp;
        fp = fopen(ftpfile, "r");
        if(fp == NULL){
          printf("File not found\n");
          continue;
        }
        //send the command to server along with filename
        send(sock, command, strlen(command), 0);
        send(sock, ftpfile, strlen(ftpfile), 0);
        read(sock, buffer, 1024);
        printf("%s\n", buffer);

        //send the file
        memset(buffer, 0, sizeof(buffer));
        while(fread(buffer, 1, 1024, fp)){
          send(sock, buffer, 1024, 0);
          memset(buffer, 0, sizeof(buffer));
        }
        fclose(fp);
        printf("File uploaded successfully\n");
      }
    }

    return 0;
}
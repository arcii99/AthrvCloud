//FormAI DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 110 //POP3 port for receiving emails
#define BUF_SIZE 4096

int main(int argc, char **argv) {

    int sockfd, n;
    char recvline[BUF_SIZE+1];
    struct sockaddr_in servaddr;

    if (argc != 4) { //program requires three arguments: server address, username, password
        printf("usage: %s <server address> <username> <password>\n",argv[0]);
        exit(1);
    }

    char *server_addr = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    //create socket for client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd<0) {
        printf("error opening socket");
        exit(1);
    }

    //setup server address and port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr=inet_addr(server_addr);
    servaddr.sin_port=htons(SERVER_PORT);

    //connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0) {
        printf("error connecting to server");
        exit(1);
    }

    //welcome message from server
    n = read(sockfd, recvline, BUF_SIZE);
    recvline[n] = '\0';
    printf("%s",recvline);

    //send username to server
    char username_cmd[BUF_SIZE];
    sprintf(username_cmd,"USER %s\n",username);
    n = write(sockfd,username_cmd,strlen(username_cmd));
    if (n<0) {
        printf("error sending username to server");
        exit(1);
    }

    //response from server after sending username
    n = read(sockfd, recvline, BUF_SIZE);
    recvline[n] = '\0';
    printf("%s",recvline);

    //send password to server
    char password_cmd[BUF_SIZE];
    sprintf(password_cmd,"PASS %s\n",password);
    n = write(sockfd,password_cmd,strlen(password_cmd));
    if (n<0) {
        printf("error sending password to server");
        exit(1);
    }

    //response from server after sending password
    n = read(sockfd, recvline, BUF_SIZE);
    recvline[n] = '\0';
    printf("%s",recvline);

    //retrieve number of emails from server
    char stat_cmd[BUF_SIZE];
    sprintf(stat_cmd,"STAT\n");
    n = write(sockfd,stat_cmd,strlen(stat_cmd));
    if (n<0) {
        printf("error sending STAT command to server");
        exit(1);
    }

    //response from server with number of emails and total size
    n = read(sockfd, recvline, BUF_SIZE);
    recvline[n] = '\0';
    printf("%s",recvline);

    //retrieve list of all emails from server
    char list_cmd[BUF_SIZE];
    sprintf(list_cmd,"LIST\n");
    n = write(sockfd,list_cmd,strlen(list_cmd));
    if (n<0) {
        printf("error sending LIST command to server");
        exit(1);
    }

    //response from server with list of emails and sizes
    char email_list[BUF_SIZE];
    n = read(sockfd, email_list, BUF_SIZE);
    email_list[n] = '\0';
    printf("%s",email_list);

    //select email to retrieve
    printf("\nEnter email number to retrieve: ");
    int email_num;
    scanf("%d",&email_num);

    //send RETR command for selected email to server
    char retr_cmd[BUF_SIZE];
    sprintf(retr_cmd,"RETR %d\n",email_num);
    n = write(sockfd,retr_cmd,strlen(retr_cmd));
    if (n<0) {
        printf("error sending RETR command to server");
        exit(1);
    }

    //response from server with selected email contents
    char email_contents[BUF_SIZE];
    n = read(sockfd, email_contents, BUF_SIZE);
    email_contents[n] = '\0';
    printf("%s",email_contents);

    //quit connection with server
    char quit_cmd[BUF_SIZE];
    sprintf(quit_cmd,"QUIT\n");
    n = write(sockfd,quit_cmd,strlen(quit_cmd));
    if (n<0) {
        printf("error sending QUIT command to server");
        exit(1);
    }

    close(sockfd);
    return 0;
}
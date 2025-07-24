//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main(int argc, char** argv){
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[1000];
    char recvline[1000];

    if (argc != 2){
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port=htons(21);

    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    read(sockfd, recvline, 1000);
    printf("%s\n", recvline);

    char userCmd[] = "USER anonymous\r\n";
    send(sockfd, userCmd, strlen(userCmd), 0);
    read(sockfd, recvline, 1000);
    printf("%s\n", recvline);

    char passCmd[] = "PASS test@test.com\r\n";
    send(sockfd, passCmd, strlen(passCmd), 0);
    read(sockfd, recvline, 1000);
    printf("%s\n", recvline);

    char pasvCmd[] = "PASV\r\n";
    send(sockfd, pasvCmd, strlen(pasvCmd), 0);
    read(sockfd, recvline, 1000);
    printf("%s\n", recvline);

    // getting IP address and port number from PASV request
    char *token = strtok(recvline, ",");
    int cnt = 0;
    char ipAddr[20];
    int portNum[2];
    int ipLen = 0;
    while(token != NULL) {
        if(cnt == 3) {
            ipLen = strlen(token);
            strncpy(ipAddr, token, ipLen - 1);
            ipAddr[ipLen - 1] = '.';
        }
        if(cnt == 4){
            strcat(ipAddr, token);
        }
        if(cnt >= 5 && cnt <= 6){
            portNum[cnt - 5] = atoi(token);
        }
        cnt++;
        token = strtok(NULL, ",");
    }

    struct sockaddr_in dataServAddr;
    bzero(&dataServAddr,sizeof(dataServAddr));
    dataServAddr.sin_family = AF_INET;
    dataServAddr.sin_port=htons(portNum[0] * 256 + portNum[1]);
    dataServAddr.sin_addr.s_addr = inet_addr(ipAddr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(sockfd, (struct sockaddr *)&dataServAddr, sizeof(dataServAddr));

    char retrCmd[] = "RETR test.txt\r\n";
    send(sockfd, retrCmd, strlen(retrCmd), 0);
    char body[1024];
    FILE *fp = fopen("test.txt", "w+");
    while((n = read(sockfd, body, 1023)) > 0) {
        body[n] = '\0';
        fprintf(fp, "%s", body);
    }
    fclose(fp);

    close(sockfd);
    return 0;
}
//FormAI DATASET v1.0 Category: Networking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char message[30];

    if(argc!=2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock=socket(PF_INET, SOCK_STREAM, 0);   
    if(serv_sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1) {
        error_handling("bind() error");
    }

    if(listen(serv_sock, 5)==-1) {
        error_handling("listen() error");
    }

    clnt_addr_size=sizeof(clnt_addr);
    clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);

    if(clnt_sock==-1) {
        error_handling("accept() error");
    }

    printf("Connected with client: %s\n", inet_ntoa(clnt_addr.sin_addr));
    write(clnt_sock, "Welcome to my server.\n", 22);

    sleep(2);

    read(clnt_sock, message, sizeof(message));
    printf("Received message: %s\n", message);

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
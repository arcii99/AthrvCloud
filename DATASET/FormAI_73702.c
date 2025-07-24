//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *math_expression = "2 * (3 + 5)";
    char buffer[1024] = {0};
    char response[1024] = {0};
    double result;
   
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
       
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, math_expression, strlen(math_expression), 0);
    
    valread = read(sock, buffer, 1024);
    
    if (strcmp(buffer, "ERROR") != 0) {
        result = atof(buffer);
        printf("Mathematical expression: %s\nResult: %f\n", math_expression, result);
    } else {
        printf("Mathematical expression: %s\nResult: %s\n", math_expression, buffer);
    }
    
    return 0;
}
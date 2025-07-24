//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// function to get IP address from hostname
int hostname_to_ip(char * hostname , char* ip) 
{ 
    struct hostent *he;  
    struct in_addr **addr_list; 
    int i; 
    
    if ((he = gethostbyname( hostname )) == NULL)  
    { 
        return 1; 
    } 
    
    addr_list = (struct in_addr **) he->h_addr_list; 
    
    for(i = 0; addr_list[i] != NULL; i++) 
    { 
        strcpy(ip , inet_ntoa(*addr_list[i]) ); 
        return 0; 
    } 
    
    return 1; 
} 

int main(int argc, char** argv)
{
    // check if user provided correct inputs
    if (argc != 4)
    {
        printf("Usage: ./imap_client <server_address> <username> <password>\n");
        return 1;
    }
    
    // initialize SSL library
    SSL_library_init();
    SSL_CTX* ctx = SSL_CTX_new(TLSv1_2_client_method());
    
    // check for SSL library initialization errors
    if (ctx == NULL)
    {
        printf("SSL Library initialization failed.\n");
        return 1;
    }
    
    // set SSL context options
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3 | SSL_OP_NO_COMPRESSION);
    
    // setup connection
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1)
    {
        printf("Socket creation failed.\n");
        return 1;
    }
    
    // get IP address from hostname
    char ip[100];
    if (hostname_to_ip(argv[1], ip) != 0)
    {
        printf("Could not resolve hostname.\n");
        return 1;
    }
    
    // prepare socket address
    struct sockaddr_in sa = {0};
    sa.sin_family = AF_INET;
    sa.sin_port = htons(993);
    sa.sin_addr.s_addr = inet_addr(ip);
    
    // connect to server
    if (connect(sockfd, (struct sockaddr*)&sa, sizeof(sa)) == -1)
    {
        printf("Connection to server failed.\n");
        return 1;
    }
    
    // setup SSL connection
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    // receive server/welcome message
    char welcome_msg[BUFFER_SIZE] = {0};
    SSL_read(ssl, welcome_msg, BUFFER_SIZE);
    printf("%s\n", welcome_msg);
    
    // send LOGIN command to authenticate
    char login_cmd[BUFFER_SIZE] = {0};
    sprintf(login_cmd, "LOGIN %s %s\r\n", argv[2], argv[3]);
    SSL_write(ssl, login_cmd, strlen(login_cmd));
    
    // receive LOGIN command response
    char response[BUFFER_SIZE] = {0};
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send LIST command to get email list
    SSL_write(ssl, "LIST \"\" \"*\"\r\n", strlen("LIST \"\" \"*\"\r\n"));
    
    // receive LIST command response
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send LOGOUT command to logout
    SSL_write(ssl, "LOGOUT\r\n", strlen("LOGOUT\r\n"));

    // receive LOGOUT command response
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("%s\n", response);
    
    // cleanup
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<ctype.h>

//Function Prototypes
void change_case(char *);

//Main Function
int main(int argc, char *argv[]) {
    
    int client_sock;
    struct sockaddr_in server_addr;
    char request[ BUFSIZ ], response[ BUFSIZ ];
    
    if( argc != 2 ) {
        printf("Usage : %s <ip_address>\n", argv[0]);
        exit(1);
    }
    
    //create socket
    client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if( client_sock == -1 ) {
        printf("Failed to create socket\n");
        exit(1);
    }
    
    //connect
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons( 80 );
    
    if( connect( client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1 ) {
        printf("Failed to Connect to server\n");
        exit(1);
    }
    
    printf("Connected to server on %s:%d\n", argv[1], 80);
    printf("Enter HTTP Request:\n");
    fgets( request, BUFSIZ, stdin );
    
    change_case( request ); //change characters of the request
    
    //Send Request
    if( send( client_sock, request, strlen( request ), 0 ) == -1 ) {
        printf("Failed to Send Request\n");
        exit(1);
    }
    
    //Receive Response
    int received_bytes = recv( client_sock, response, BUFSIZ, 0 );
    if( received_bytes == -1 ) {
        printf("Failed to Receive Response\n");
        exit(1);
    }
    
    printf("Response Received\n");
    printf("%.*s", received_bytes, response);
    
    close( client_sock );
    return 0;
}

void change_case( char *str ) {
    while(*str) {
        *str = tolower(*str);
        str++;
    }
}
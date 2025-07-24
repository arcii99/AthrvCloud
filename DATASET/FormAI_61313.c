//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h> 
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 


int main(int argc, char *argv[]) 
{ 
    int socket_desc; 
    struct sockaddr_in server; 
    char *message, server_reply[2000]; 
    
    //connect to remote server
    socket_desc = socket(AF_INET, SOCK_STREAM, 0); 
    if (socket_desc == -1) 
    { 
        printf("Could not create socket"); 
    } 
    
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET; 
    server.sin_port = htons( 25 ); 

    //connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0) 
    { 
        puts("Could not connect"); 
        return 1; 
    } 

    //send data
    message = "HELO localhost\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    memset(server_reply, 0, sizeof(server_reply)); 
    //receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0) 
    { 
        puts("recv failed"); 
    } 
    puts("Response from server:");
    printf("%s",server_reply);

    //send second data
    message = "MAIL FROM:<sender@sender.com>\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    memset(server_reply, 0, sizeof(server_reply)); 
    //receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0) 
    { 
        puts("recv failed"); 
    } 
    puts("Response from server:");
    printf("%s",server_reply);

    //send third data
    message = "RCPT TO:<receiver@receiver.com>\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    memset(server_reply, 0, sizeof(server_reply)); 
    //receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0) 
    { 
        puts("recv failed"); 
    } 
    puts("Response from server:");
    printf("%s",server_reply);

    //send fourth data
    message = "DATA\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    memset(server_reply, 0, sizeof(server_reply)); 
    //receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0) 
    { 
        puts("recv failed"); 
    } 
    puts("Response from server:");
    printf("%s",server_reply);

    //send fifth data
    message = "Subject: This is a test email\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    message = "From: sender@sender.com\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    message = "To: receiver@receiver.com\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    message = "Content-Type: text/html\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    }  
    message = "<html><body><h1>This is a test email</h1></body></html>\r\n.\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    memset(server_reply, 0, sizeof(server_reply)); 
    //receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0) 
    { 
        puts("recv failed"); 
    } 
    puts("Response from server:");
    printf("%s",server_reply);

    //send quit data
    message = "QUIT\r\n";
    if( send(socket_desc , message , strlen(message) , 0) < 0) 
    { 
        puts("Send failed"); 
        return 1; 
    } 
    memset(server_reply, 0, sizeof(server_reply)); 
    //receive a reply from the server
    if( recv(socket_desc, server_reply , 2000 , 0) < 0) 
    { 
        puts("recv failed"); 
    } 
    puts("Response from server:");
    printf("%s",server_reply);

    close(socket_desc); 
    return 0; 
}
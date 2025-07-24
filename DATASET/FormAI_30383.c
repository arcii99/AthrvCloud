//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

#define MAX_LEN 4096 

int main(int argc, char *argv[]) 
{ 
    int socket_fd = 0; 
    struct sockaddr_in server_addr; 
    char message[MAX_LEN], reply[MAX_LEN]; 
    
    //Creating the socket 
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error\n"); 
        return -1; 
    } 

    //Server configuration 
    memset(&server_addr, '0', sizeof(server_addr)); 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(587); 
    
    //IP address of the SMTP server
    if(inet_pton(AF_INET, "SMTP_SERVER_IP_ADDRESS", &server_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
  
    //Connecting to the server 
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    
    //Reading SMTP server's greeting message
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Sending HELO message to the SMTP server
    sprintf(message, "HELO SMTP_CLIENT\r\n");
    if(send(socket_fd, message, strlen(message), 0) < 0)
    {
        printf("\nSend Error\n");
        return -1;
    }
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Sending MAIL FROM message to the SMTP server
    sprintf(message, "MAIL FROM:<SENDER_EMAIL_ADDRESS>\r\n");
    if(send(socket_fd, message, strlen(message), 0) < 0)
    {
        printf("\nSend Error\n");
        return -1;
    }
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Sending RCPT TO message to the SMTP server
    sprintf(message, "RCPT TO:<RECIPIENT_EMAIL_ADDRESS>\r\n");
    if(send(socket_fd , message , strlen(message) , 0) < 0)
    {
        printf("\nSend Error\n");
        return -1;
    }
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Sending DATA message to the SMTP server
    sprintf(message, "DATA\r\n");
    if(send(socket_fd , message , strlen(message) , 0) < 0)
    {
        printf("\nSend Error\n");
        return -1;
    }
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Sending email body to the SMTP server
    sprintf(message, "Subject: SMTP Client Test\r\n\r\nThis is a test email sent from a SMTP client in C programming language\r\n.\r\n");
    if(send(socket_fd , message , strlen(message) , 0) < 0)
    {
        printf("\nSend Error\n");
        return -1;
    }
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Sending QUIT message to the SMTP server
    sprintf(message, "QUIT\r\n");
    if(send(socket_fd , message , strlen(message) , 0) < 0)
    {
        printf("\nSend Error\n");
        return -1;
    }
    if(read(socket_fd, reply, MAX_LEN) < 0)
    {
        printf("\nRead Error\n");
        return -1;
    }
    printf("%s\n", reply);
    
    //Closing the socket 
    close(socket_fd); 
    return 0; 
}
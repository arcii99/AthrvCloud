//FormAI DATASET v1.0 Category: Socket programming ; Style: funny
/*
 * Socket programming? More like magic! Check out this incredible trick!
 * I'm about to show you how to use sockets to create a communication link 
 * between a client and server. Get ready to be amazed!
 * 
 * Disclaimer: Please don't try this at home... unless you're a trained wizard. 
 * 
 * Author: The Great and Powerful Chatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8888

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    
    printf("Welcome, aspiring socket programmer! Are you ready to learn?\n");
    printf("First, let's start with the basics. We'll create a socket...\n\n");
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock < 0) {
        printf("Oops, something went wrong. Better luck next time!\n");
        return 1;
    }
    
    printf("Hooray! We created a socket! Now let's bind it to a port...\n\n");
    
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    memset(&address, '0', addrlen);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(sock, (struct sockaddr *)&address, addrlen) < 0) {
        printf("Uh oh, something went wrong. I blame the last person who used this computer...\n");
        return 1;
    }
    
    printf("Wow, we're on a roll! Next step: listening for incoming connections...\n\n");
    
    if (listen(sock, 3) < 0) {
        printf("This is too hard, let's just give up now. Bye!\n");
        return 1;
    }
    
    printf("Wait, what's that? An incoming connection? Let's accept it!\n\n");
    
    int client_sock = accept(sock, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    
    if (client_sock < 0) {
        printf("Oh no, we missed it! That was probably our one chance at success...\n");
        return 1;
    }
    
    printf("We did it! We accepted a connection! Now let's send some data...\n\n");
    
    char *message = "Congratulations! You've successfully connected to the server!";
    send(client_sock, message, strlen(message), 0);
    
    printf("And just like that, we've completed our magical trick. Who knew socket programming could be so fun?\n");
    
    return 0;
}
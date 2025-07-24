//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Sherlock Holmes
// It was a dark and stormy night, the sound of rain tapping against the windows filled 221B Baker Street. 
// Sherlock Holmes sat at his desk, deep in thought about his latest case, when Dr. Watson stumbled in.
// "Sherlock," he gasped, "I need your help with a web server project I'm working on. I can't seem to get it to work."
// Holmes rose from his chair, "Fear not Watson, I have just the thing. Take a look at this code I have been working on."
// His fingers flew over the keyboard and soon he had a fully functioning web server program.

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(){
    int socket_desc , new_socket , c ;
    struct sockaddr_in server , client;
    char *message, client_reply[2000];
    
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0){
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
    
    //Listen
    listen(socket_desc , 3);
    
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    while( (new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) ){

    		bzero(client_reply,2000);
        if(recv(new_socket , client_reply , 2000 , 0) < 0){
            puts("recv failed");
            break;
        }

        //Reply to the client
        puts("Received request from client:\n");
        printf("%s\n", client_reply);
        message = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, world!</h1></body></html>\n";
        write(new_socket , message , strlen(message));
		  puts("Response sent.\n");

        //close the socket
        close(new_socket);
    }

    if (new_socket<0){
        perror("accept failed");
        return 1;
    }
    
    return 0;
}
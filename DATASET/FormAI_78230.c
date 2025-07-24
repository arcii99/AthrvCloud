//FormAI DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

void send_message(int sock_fd, char* message) {
    send(sock_fd, message, strlen(message), 0);
}

void receive_message(int sock_fd, char* message) {
    memset(message, 0, sizeof(message));
    recv(sock_fd, message, sizeof(message), 0);
}

int main() {
    int server_sock_fd, client_sock_fd;
    struct sockaddr_in server_address, client_address;
    char message[1024];

    // Create socket
    if ((server_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock_fd, 3) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((client_sock_fd = accept(server_sock_fd, (struct sockaddr *)&client_address, (socklen_t*)&client_address)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    
    // Connection established message
    send_message(client_sock_fd, "Welcome to the Kingdom!\n");

    // Receive username from client
    receive_message(client_sock_fd, message);
    printf("Username received: %s\n", message);

    // Greet the client
    char greeting[100] = "Greetings, ";
    strcat(greeting, message);
    strcat(greeting, "!\n");
    send_message(client_sock_fd, greeting);

    // Receive weapon of choice from client
    receive_message(client_sock_fd, message);
    printf("Weapon of choice received: %s\n", message);

    // Choose opponent and attack!
    if (strcmp(message, "Sword") == 0) {
        send_message(client_sock_fd, "You chose sword! Your opponent is the ferocious dragon.\n");
        sleep(1);
        send_message(client_sock_fd, "You swing your sword at the dragon.\n");
        sleep(1);
        send_message(client_sock_fd, "The dragon dodges your attack and spits fire at you.\n");
        sleep(1);
        send_message(client_sock_fd, "You dodge the fire and swing your sword again.\n");
        sleep(1);
        send_message(client_sock_fd, "The dragon roars and falls to the ground, defeated.\n");
    } else if (strcmp(message, "Axe") == 0) {
        send_message(client_sock_fd, "You chose axe! Your opponent is the evil witch.\n");
        sleep(1);
        send_message(client_sock_fd, "You charge at the witch with your axe.\n");
        sleep(1);
        send_message(client_sock_fd, "The witch cackles and throws a spell at you.\n");
        sleep(1);
        send_message(client_sock_fd, "You deflect the spell with your axe and swing it at the witch.\n");
        sleep(1);
        send_message(client_sock_fd, "The witch screams and disappears in a puff of smoke.\n");
    } else if (strcmp(message, "Bow") == 0) {
        send_message(client_sock_fd, "You chose bow! Your opponent is the giant troll.\n");
        sleep(1);
        send_message(client_sock_fd, "You take aim at the troll with your bow.\n");
        sleep(1);
        send_message(client_sock_fd, "The troll charges at you and swings his club.\n");
        sleep(1);
        send_message(client_sock_fd, "You dodge the club and shoot an arrow at the troll.\n");
        sleep(1);
        send_message(client_sock_fd, "The troll roars and falls to the ground, defeated.\n");
    } else {
        send_message(client_sock_fd, "Invalid weapon choice.\n");
    }

    // Close the connection
    close(client_sock_fd);
    close(server_sock_fd);
    return 0;
}
//FormAI DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int id;
    char name[50];
    int age;
} User;

void insertUser(User *users, int *size) {
    User newUser;
    printf("\nEnter user name: ");
    scanf("%s", newUser.name);
    printf("\nEnter user age: ");
    scanf("%d", &newUser.age);
    newUser.id = *size + 1;
    users[*size] = newUser;
    *size++;
    printf("\nUser inserted with ID %d", newUser.id);
}

void listUsers(User *users, int size) {
    if (size == 0) {
        printf("\nNo users found!");
        return;
    }
    printf("\nID\tNAME\tAGE\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\n", users[i].id, users[i].name, users[i].age);
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Allow multiple connections to same port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind socket to port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Create database
    User users[50];
    int size = 0;

    // Handle incoming connections
    while (1) {
        printf("\nWaiting for connections...");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("\nConnection established!\n");

        // Read incoming request
        valread = read(new_socket, buffer, MAX_BUFFER_SIZE);
        printf("\nRequest received: %s", buffer);

        // Parse and handle request
        if (strcmp(buffer, "insert") == 0) {
            insertUser(users, &size);
        } else if (strcmp(buffer, "list") == 0) {
            listUsers(users, size);
        } else {
            strcpy(buffer, "Invalid request!");
        }

        // Send response
        send(new_socket, buffer, MAX_BUFFER_SIZE, 0);
        printf("\nResponse sent: %s\n", buffer);

        close(new_socket);
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    return 0;
}
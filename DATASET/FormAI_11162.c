//FormAI DATASET v1.0 Category: Game ; Style: distributed
//Example C Game: Guess the Number
//Distributed Style Program using sockets

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr

#define PORTNUM 8080

//Function to get a random number for the game
int generateRandomNumber() {
    srand(time(0));
    int random_number = (rand() % 100);
    return random_number;
}

int main(int argc, char const *argv[]) {
    int server_socket, new_socket, valread;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    //Creating the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        perror("Could not create socket!");
        exit(EXIT_FAILURE);
    }

    //Allowing multiple connections to the same port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //Setting up the socket address information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORTNUM);

    //Binding the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //Listening for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Generating a random number for the game
    int number_to_guess = generateRandomNumber();

    //Starting the game
    printf("Starting the guess the number game... The number is between 0 and 99 inclusive.\n");

    while(true) {
        //Accepting incoming connections
        new_socket = accept(server_socket, (struct sockaddr*)&server_addr, (socklen_t*)&addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        //Reading the guess from the client
        char buffer[1024] = {0};
        valread = read(new_socket, buffer, 1024);
        if (valread < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        //Checking the guess against the number to guess.
        int guess = atoi(buffer);
        if (guess == number_to_guess) {
            char* message = "You Win!\n";
            send(new_socket, message, strlen(message), 0);
            break;
        } else if (guess > number_to_guess) {
            char* message = "Too High.\n";
            send(new_socket, message, strlen(message), 0);
        } else {
            char* message = "Too Low.\n";
            send(new_socket, message, strlen(message), 0);
        }
    }

    //Closing the server socket
    close(server_socket);

    return 0;
}
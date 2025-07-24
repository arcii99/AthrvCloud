//FormAI DATASET v1.0 Category: Socket programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8888
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

void print_puzzle(int first_num, int second_num, int result) {
    printf("\n\n");
    printf(" ____ ____ ____ ____\n");
    printf("| %2d | %2d |    | %2d |\n", first_num, second_num, result);
    printf("|____|____|____|____|\n");
}

int generate_puzzle(int* first, int* second, int* result) {
    srand(time(NULL));
    *first = rand() % 10;
    *second = rand() % 10;
    *result = (*first + *second) * 2;

    if (*result >= 100) {
        return 0;
    }

    print_puzzle(*first, *second, *result);
    return 1;
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread, first_num, second_num, result;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for a connection...\n");
    
    while(1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                                                (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection established!\n");
        
        while (1) {
            if (!generate_puzzle(&first_num, &second_num, &result)) {
                printf("Puzzle could not be generated\n");
                break;
            }
            
            valread = read(new_socket , buffer, BUFFER_SIZE);
            if (!strncmp(buffer, "quit", 4)) {
                close(new_socket);
                printf("Connection closed!\n");
                break;
            } else if (valread > 0) {
                int answer = atoi(buffer);
                if (answer == result) {
                    send(new_socket , "Congratulations! You solved the puzzle\n" , 
                                                 strlen("Congratulations! You solved the puzzle\n") , 0 );
                    printf("Correct answer received! Puzzle solved!\n");
                } else {
                    send(new_socket , "Incorrect answer. Please try again\n" , 
                                                 strlen("Incorrect answer. Please try again\n") , 0 );
                    printf("Incorrect answer received!\n");
                }
            }
            
            memset(buffer, 0, BUFFER_SIZE);
        }
    }
    
    return 0;
}
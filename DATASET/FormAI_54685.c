//FormAI DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 1000 // Maximum number of questions

struct question { // Struct for holding each question
    char question_text[MAX];
    char option_1[MAX];
    char option_2[MAX];
    char option_3[MAX];
    char option_4[MAX];
    int correct_option;
};

void send_question(int sockfd, struct question q) { // Sends one question to the client
    char buffer[MAX];
    sprintf(buffer, "Question: %s\n1. %s\n2. %s\n3. %s\n4. %s\nEnter choice: ",
        q.question_text, q.option_1, q.option_2, q.option_3, q.option_4);
    write(sockfd, buffer, strlen(buffer));
}

void receive_response(int sockfd, int *response) { // Receives response from the client
    char buffer[MAX];
    read(sockfd, buffer, sizeof(buffer));
    *response = atoi(buffer);
}

int get_score(struct question *questions, int *client_responses, int num_questions) { // Calculates score based on the client's responses
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (client_responses[i] == questions[i].correct_option) {
            score++;
        }
    }
    return score;
}

int main(int argc, char **argv) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX] = {0};
    int port_number = 8080;
     
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
     
    // Forcefully attach socket to the port number
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_number);
     
    // Bind the socket to the specified port number
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
     
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Read number of questions from the client
        int num_questions;
        read(new_socket, buffer, sizeof(buffer));
        num_questions = atoi(buffer);
        struct question *questions = (struct question*)malloc(num_questions * sizeof(struct question));
        
        // Read each question from the client and store in struct
        for (int i = 0; i < num_questions; i++) {
            read(new_socket, buffer, sizeof(buffer));
            strcpy(questions[i].question_text, buffer);
            read(new_socket, buffer, sizeof(buffer));
            strcpy(questions[i].option_1, buffer);
            read(new_socket, buffer, sizeof(buffer));
            strcpy(questions[i].option_2, buffer);
            read(new_socket, buffer, sizeof(buffer));
            strcpy(questions[i].option_3, buffer);
            read(new_socket, buffer, sizeof(buffer));
            strcpy(questions[i].option_4, buffer);
            read(new_socket, buffer, sizeof(buffer));
            questions[i].correct_option = atoi(buffer);
        }
        
        // Send each question to the client and receive response
        int *client_responses = (int*)malloc(num_questions * sizeof(int));
        for (int i = 0; i < num_questions; i++) {
            send_question(new_socket, questions[i]);
            receive_response(new_socket, &client_responses[i]);
        }
        
        // Calculate score and send to the client
        int score = get_score(questions, client_responses, num_questions);
        sprintf(buffer, "Your score: %d\n", score);
        write(new_socket, buffer, strlen(buffer));
        
        free(questions);
        free(client_responses);
        close(new_socket);
    }
    return 0;
}
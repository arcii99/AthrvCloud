//FormAI DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define MAX_NAME_LENGTH 20
#define MAX_RESPONSE_LENGTH 50
#define SERVER_PORT 8000

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correct_option_index;
} Question;

void init_questions(Question questions[]) {
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "New York");
    strcpy(questions[0].options[1], "Paris");
    strcpy(questions[0].options[2], "London");
    strcpy(questions[0].options[3], "Tokyo");
    questions[0].correct_option_index = 1;

    strcpy(questions[1].question, "What is the tallest mountain in the world?");
    strcpy(questions[1].options[0], "Mount Rushmore");
    strcpy(questions[1].options[1], "Mount Everest");
    strcpy(questions[1].options[2], "Mount McKinley");
    strcpy(questions[1].options[3], "Mount Olympus");
    questions[1].correct_option_index = 1;

    strcpy(questions[2].question, "What is the highest waterfall in the world?");
    strcpy(questions[2].options[0], "Niagara Falls");
    strcpy(questions[2].options[1], "Angel Falls");
    strcpy(questions[2].options[2], "Victoria Falls");
    strcpy(questions[2].options[3], "Iguazu Falls");
    questions[2].correct_option_index = 1;

    strcpy(questions[3].question, "What is the largest continent in the world?");
    strcpy(questions[3].options[0], "North America");
    strcpy(questions[3].options[1], "South America");
    strcpy(questions[3].options[2], "Africa");
    strcpy(questions[3].options[3], "Asia");
    questions[3].correct_option_index = 3;

    strcpy(questions[4].question, "What is the smallest country in the world?");
    strcpy(questions[4].options[0], "Monaco");
    strcpy(questions[4].options[1], "Vatican City");
    strcpy(questions[4].options[2], "San Marino");
    strcpy(questions[4].options[3], "Liechtenstein");
    questions[4].correct_option_index = 1;
}

void generate_random_question_indices(int indices[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        indices[i] = rand() % MAX_QUESTIONS;
    }
}

void send_question(int sockfd, Question question) {
    char message[1024];
    sprintf(message, "Q:%s\nA:%s\nB:%s\nC:%s\nD:%s\n", question.question, question.options[0], question.options[1], question.options[2], question.options[3]);
    send(sockfd, message, strlen(message), 0);
}

void send_question_indices(int sockfd, int indices[], int n) {
    char message[1024];
    sprintf(message, "QUIZ:%d,%d,%d,%d,%d\n", indices[0], indices[1], indices[2], indices[3], indices[4]);
    send(sockfd, message, strlen(message), 0);
}

void send_result(int sockfd, int score) {
    char message[1024];
    sprintf(message, "SCORE:%d", score);
    send(sockfd, message, strlen(message), 0);
}

int get_answer(int sockfd) {
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    if (bytes_received <= 0) {
        return -1;
    }
    response[bytes_received] = '\0';
    return atoi(response);
}

int main() {
    int sockfd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int sin_size = sizeof(struct sockaddr_in);
    int yes = 1;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0) {
        perror("setsockopt");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 1) < 0) {
        perror("listen");
        return 1;
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        if ((client_fd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size)) < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        Question questions[MAX_QUESTIONS];
        int indices[MAX_QUESTIONS];
        int score = 0;

        init_questions(questions);
        generate_random_question_indices(indices, MAX_QUESTIONS);

        send_question_indices(client_fd, indices, MAX_QUESTIONS);

        for (int i = 0; i < MAX_QUESTIONS; i++) {
            send_question(client_fd, questions[indices[i]]);
            int answer = get_answer(client_fd);
            if (answer == questions[indices[i]].correct_option_index) {
                score++;
            }
        }

        send_result(client_fd, score);

        close(client_fd);
        printf("Client disconnected\n");
    }

    close(sockfd);
    return 0;
}
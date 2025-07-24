//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_SIZE 100
#define MAX_USERS 10

typedef struct {
    int id;
    char username[20];
    int points;
} User;

User users[MAX_USERS];
int num_users;
int attack_detected = 0;

void add_user(char* username) {
    User user;
    user.id = num_users + 1;
    strcpy(user.username, username);
    user.points = 0;
    users[num_users] = user;
    num_users++;
}

void print_users() {
    printf("CURRENT USERS:\n");
    for(int i = 0; i < num_users; i++) {
        printf("%d. %s - Points: %d\n", users[i].id, users[i].username, users[i].points);
    }
}

void handle_message(char* msg) {
    if(strcmp(msg, "attack") == 0) {
        // Attack detected
        attack_detected = 1;
        printf("INTRUSION DETECTED!\n");
    }
}

void main_loop() {
    char msg[MSG_SIZE];
    while(1) {
        printf("\nEnter a message: ");
        fgets(msg, MSG_SIZE, stdin);

        // Remove newline character
        msg[strcspn(msg, "\n")] = 0;

        // Handle message
        handle_message(msg);

        // Check if game is over
        if(attack_detected) {
            printf("\nGAME OVER\n");
            print_users();
            exit(0);
        }
    }
}

int main() {
    printf("Welcome to the Intrusion Detection System!\n");

    // Add users
    add_user("Alice");
    add_user("Bob");
    add_user("Charlie");

    // Print users
    print_users();

    // Start game loop
    main_loop();

    return 0;
}
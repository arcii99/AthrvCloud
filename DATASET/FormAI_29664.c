//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>

// Declare constants
#define CHILD_COUNT 3
#define MESSAGE_SIZE 1024
#define PIPE_READ 0
#define PIPE_WRITE 1

// Define struct for messages
struct message {
    pid_t sender;
    char content[MESSAGE_SIZE];
};

// Declare global variables
int pipes[CHILD_COUNT][2];
pid_t children[CHILD_COUNT];

// Define function to send message between processes
void sendMessage(struct message msg, int destination) {
    write(pipes[destination][PIPE_WRITE], &msg, sizeof(msg));
}

// Define function to handle signals
void signalHandler(int sig) {
    printf("Signal received: %d\n", sig);
    for (int i = 0; i < CHILD_COUNT; i++) {
        kill(children[i], SIGTERM);
    }
    exit(0);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Register signal handler
    signal(SIGINT, signalHandler);

    // Create pipes for communication between parent and children
    for (int i = 0; i < CHILD_COUNT; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Failed to create pipe");
            exit(1);
        }
    }

    // Create child processes
    for (int i = 0; i < CHILD_COUNT; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("Failed to create child process");
            exit(1);
        } else if (pid == 0) {
            // This is the child process
            pid_t parent = getppid();
            pid_t me = getpid();
            printf("Child process %d created with parent %d\n", me, parent);

            // Close unused pipe ends
            close(pipes[i][PIPE_WRITE]);
            for (int j = 0; j < CHILD_COUNT; j++) {
                if (i != j) {
                    close(pipes[j][PIPE_READ]);
                }
            }

            // Receive messages from other processes
            struct message msg;
            while (read(pipes[i][PIPE_READ], &msg, sizeof(msg)) > 0) {
                printf("Child %d received message from %d: %s\n", me, msg.sender, msg.content);

                // Randomly select another child to send message to
                int destination = rand() % CHILD_COUNT;
                while (destination == i) {
                    destination = rand() % CHILD_COUNT;
                }
                printf("Child %d sending message to %d\n", me, destination);
                sendMessage(msg, destination);
            }

            // Clean up and exit
            printf("Child process %d exiting\n", me);
            close(pipes[i][PIPE_READ]);
            exit(0);
        } else {
            // This is the parent process
            children[i] = pid;
            printf("Parent process created child process %d with pid %d\n", i+1, pid);
        }
    }

    // Close unused pipe ends
    for (int i = 0; i < CHILD_COUNT; i++) {
        close(pipes[i][PIPE_READ]);
        if (i != CHILD_COUNT-1) {
            close(pipes[i][PIPE_WRITE]);
        }
    }

    // Send initial message to children
    struct message msg;
    msg.sender = getpid();
    strcpy(msg.content, "Hello from parent!");
    sendMessage(msg, 0);

    // Wait for children to exit
    for (int i = 0; i < CHILD_COUNT; i++) {
        int status;
        waitpid(children[i], &status, 0);
        printf("Child process %d exited with status %d\n", children[i], status);
    }

    // Clean up and exit
    printf("Parent process exiting\n");
    return 0;
}
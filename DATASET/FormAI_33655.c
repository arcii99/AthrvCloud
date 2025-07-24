//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_MESSAGE_SIZE 100
#define MAX_PROCESSES 10

// Struct to hold message data
typedef struct message {
    int pid;
    char content[MAX_MESSAGE_SIZE];
} message;

// Struct to hold process data
typedef struct process {
    int pid;
    int fd[2]; // Used to communicate with child process
} process;

void initialize_processes(process *processes, int process_count) {
    int i;
    for (i = 0; i < process_count; i++) {
        pipe(processes[i].fd); // Create communication pipe
        pid_t pid = fork(); // Create child process
        if (pid == 0) { // Child process
            close(processes[i].fd[0]); // Close read end of pipe
            // Run child process program
            execl("./child_process", "child_process", processes[i].fd[1], NULL);
        }
        else { // Parent process
            close(processes[i].fd[1]); // Close write end of pipe
            processes[i].pid = pid; // Store child process' pid
        }
    }
}

void send_message(process target_process, message msg) {
    printf("Sending message [content: %s] to process %d...\n", msg.content, target_process.pid);
    // Write message to target process' communication pipe
    write(target_process.fd[1], &msg, sizeof(message));
}

void receive_message(process *processes, int process_count) {
    int i;
    message msg;
    for (i = 0; i < process_count; i++) {
        // Read message from each process' communication pipe
        read(processes[i].fd[0], &msg, sizeof(message));
        printf("Received message [content: %s] from process %d.\n", msg.content, msg.pid);
    }
}

int main() {
    process processes[MAX_PROCESSES];
    message msg;

    int process_count = 3; // Change this value to test with more processes
    initialize_processes(processes, process_count);

    // Send message to each process
    int i;
    for (i = 0; i < process_count; i++) {
        sprintf(msg.content, "Hello from process %d!", getpid());
        msg.pid = getpid();
        send_message(processes[i], msg);
    }

    // Wait for child processes to finish
    int status;
    pid_t pid;
    for (i = 0; i < process_count; i++) {
        pid = wait(&status);
        printf("Child process with pid %d has finished with status %d.\n", pid, status);
    }

    // Receive messages from each process
    receive_message(processes, process_count);

    return 0;
}
//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 1024

int count = 0;
int total_packets = 0;
int drop_packets = 0;
int reliability = 0;

void handle_interrupt(int signal) {
    // Calculate reliability percentage
    reliability = (1 - (drop_packets / (double) total_packets)) * 100;
    printf("\nTotal packets: %d\nDropped packets: %d\nReliability: %d%%\n", 
           total_packets, drop_packets, reliability);
    exit(0);
}

int main() {
    // Register signal handler for SIGINT
    signal(SIGINT, handle_interrupt);
    
    srand(time(NULL));
    
    int fd[2];
    if (pipe(fd) == -1) {
        perror("Error creating pipe");
        exit(1);
    }
    
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("Error forking");
        exit(1);
    }
    
    if (pid == 0) {
        // Child process - simulate network traffic
        close(fd[0]); // Close unused read end of the pipe
        
        while (1) {
            int packet_loss = rand() % 2;
            if (!packet_loss) {
                count++;
            }
            total_packets++;
            if (packet_loss) {
                drop_packets++;
            }
            // Send count to parent process
            write(fd[1], &count, sizeof(count));
            usleep(50000);
        }
    } else {
        // Parent process - read packets from child process
        close(fd[1]); // Close unused write end of the pipe
        
        char buffer[BUFFER_SIZE];
        int bytes_read;
        
        while (1) {
            bytes_read = read(fd[0], buffer, BUFFER_SIZE);
            if (bytes_read == -1) {
                perror("Error reading from pipe");
                exit(1);
            }
            buffer[bytes_read] = '\0';
            printf("Received %d packets\n", *((int*) buffer));
        }
        
        exit(0);
    }
    
    return 0;
}
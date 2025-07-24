//FormAI DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define FIFO_NAME "/tmp/my_fifo"

int main() {
    mkfifo(FIFO_NAME, 0666); // create the named pipe with read and write permission for user, group, and others
    int pid = fork();
    char buffer[BUFFER_SIZE];

    if (pid == -1) {
        printf("Failed to fork child process.");
        return 1;
    } 
        
    else if (pid == 0) { // child process (Sender)
        int fd = open(FIFO_NAME, O_WRONLY); // open the named pipe for writing
        if (fd == -1) {
            printf("Failed to open named pipe for writing.");
            return 1;
        }
        
        printf("Enter a message to send: ");
        fgets(buffer, BUFFER_SIZE, stdin); // read input from user
        write(fd, buffer, strlen(buffer)); // write data to the named pipe
        close(fd); // close the named pipe
        printf("Message sent successfully!\n");
        return 0;
    } 

    else { // parent process (Receiver)
        int fd = open(FIFO_NAME, O_RDONLY); // open the named pipe for reading
        if (fd == -1) {
            printf("Failed to open named pipe for reading.");
            return 1;
        }
        wait(NULL); // wait for child process to finish
        
        read(fd, buffer, BUFFER_SIZE); // read data from the named pipe
        printf("Received message: %s", buffer);
        close(fd); // close the named pipe
        printf("Message received successfully!\n");
        return 0;
    }
    
    return 0;
}
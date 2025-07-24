//FormAI DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main() {

    pid_t pid = fork();

    if (pid == -1) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) { // Child process
        int fd;
        char * myfifo = "/tmp/myfifo";
        char message[100];
        
        mkfifo(myfifo, 0666);
        fd = open(myfifo, O_WRONLY);

        printf("My Darling, please tell me your love message: ");
        fgets(message, 100, stdin);
        write(fd, message, strlen(message)+1);
        
        close(fd);
        exit(EXIT_SUCCESS);
    } 
    else { // Parent process
        int fd;
        char * myfifo = "/tmp/myfifo";
        char message[100];

        fd = open(myfifo, O_RDONLY);
        read(fd, message, 100);
        printf("\nMy Love, I have received your message: %s", message);
        
        close(fd);
        wait(NULL);
        
        unlink(myfifo);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
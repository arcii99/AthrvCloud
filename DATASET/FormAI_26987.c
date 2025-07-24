//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LEN 256

int main()
{
    char cmd[MAX_LEN];
    char file[MAX_LEN];
    char buffer[MAX_LEN];
    char *pos;
    int pid;
    int fd;

    printf("Welcome to Brave System Administration Example Program\n");
    printf("Please enter a command: ");

    fgets(buffer, sizeof(buffer), stdin);
    
    /* Replace '\n' with '\0' */
    if ((pos = strchr(buffer, '\n')) != NULL) {
        *pos = '\0';
    }

    /* Fork a child process */
    pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        /* Child process */

        /* Redirect stdout to a file */
        sprintf(file, "/tmp/%d.out", getpid());
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        
        if (fd < 0) {
            perror("open");
            exit(1);
        }

        dup2(fd, STDOUT_FILENO);
        
        /* Execute the command */
        if (system(buffer) < 0) {
            perror("system");
            exit(1);
        }
    
        close(fd);

        printf("Command output redirected to: %s\n", file);

    } else {
        /* Parent process */

        /* Wait for the child process to complete */
        if (waitpid(pid, NULL, 0) < 0) {
            perror("waitpid");
            exit(1);
        }

        printf("Command executed successfully!\n");
    }

    return 0;
}
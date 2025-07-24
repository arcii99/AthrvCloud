//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;
    long int mem;
    
    while (1) {
        pid = fork();
        
        if (pid == 0) {
            /* child process */
            char* cmd = "ps -p $$ -o rss | grep -v RSS | xargs";
            mem = strtol(cmd, NULL, 10);
            printf("RAM usage: %ld kb\n", mem);
            exit(0);
        } else if (pid < 0) {
            /* error */
            perror("fork");
            exit(1);
        } else {
            /* parent process */
            waitpid(pid, &status, 0);
        }
        
        sleep(1);
    }
    
    return 0;
}
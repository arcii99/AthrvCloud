//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } 
    else if (pid == 0) {
        // child process
        char *args[] = {"ps", "-p", "self", "-o", "pcpu", NULL};
        execvp(args[0], args);
    } 
    else {
        // parent process
        wait(NULL);
        printf("CPU Usage: ");
        fflush(stdout);
        char result[10];
        FILE *fp = popen("ps -p self -o pcpu | tail -n 1", "r");
        fgets(result, 10, fp);
        pclose(fp);
        printf("%s", result);
    }
    return 0;
}
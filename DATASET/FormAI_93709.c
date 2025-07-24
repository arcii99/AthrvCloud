//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid < 0) // fork failed
    {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    else if (pid == 0) // child process
    {
        char *args[] = {"ps", "-p", "1", "-u", "-o", "%cpu", NULL};
        execvp(args[0], args);
    }
    else // parent process
    {
        wait(NULL);
        printf("CPU Usage: ");
        // read the output of the child process
        FILE *fp = popen("ps -p 1 -u -o %cpu", "r");
        char buf[256];
        fgets(buf, sizeof(buf), fp);
        pclose(fp);
        printf("%s", buf);
    }

    return 0;
}
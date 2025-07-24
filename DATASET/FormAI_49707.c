//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static char* command = "ls -la";

void async_run(int argc, ...)
{
    va_list argp;
    int status;
    pid_t pid;
    const char* command;
    bool wait_for_child = true;

    va_start(argp, argc);

    for (int i = 0; i < argc; ++i)
    {
        command = va_arg(argp, const char*);
        pid = fork();

        if (pid == -1) // error
        {
            fprintf(stderr, "Failed to fork process\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) // child
        {
            system(command);
            exit(0);
        }
        else if (wait_for_child) // parent
        {
            wait(&status);
        }
    }

    va_end(argp);
    exit(EXIT_SUCCESS);
}

void async_example()
{
    async_run(1, command);
}

int main()
{
    async_example();
    return 0;
}
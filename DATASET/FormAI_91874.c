//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void die(char *message)
{
    if(errno)
    {
        perror(message);
    }
    else
    {
        printf("ERROR: %s\n", message);
    }
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        die("USAGE: error_handling <file_name>");
    }

    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        char error_message[100];
        sprintf(error_message, "Couldn't open %s", argv[1]);
        die(error_message);
    }

    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while((linelen = getline(&line, &linecap, file)) > 0)
    {
        printf("Line length: %zu", linelen);
    }

    free(line);
    fclose(file);
    return 0;
}
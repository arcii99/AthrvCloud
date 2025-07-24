//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 256 // maximum size of buffer to store output

int main()
{
    int pid = getpid(); // get PID of this current process
    while (1)
    {
        char command[MAX_BUFFER_SIZE];
        sprintf(command, "pmap %d | tail -1", pid); // get the last line of output when running pmap with this PID
        FILE *fp = popen(command, "r"); // run the command and pipe the output to a file stream
        char output[MAX_BUFFER_SIZE];
        fread(output, 1, MAX_BUFFER_SIZE, fp); // read in the output from the file stream
        pclose(fp); // close the file stream

        char *kb_str = strtok(output, " "); // tokenize the output by space
        int i = 1;
        while (kb_str != NULL && i < 3) // get the third token, which gives us the memory in kilobytes
        {
            kb_str = strtok(NULL, " ");
            i++;
        }
        int kb;
        if (kb_str != NULL)
        {
            kb = atoi(kb_str);
            float mb = kb / 1024.0f; // convert kilobytes to megabytes
            printf("Current RAM usage: %.2f MB\n", mb);
        }
        sleep(5); // wait for 5 seconds before checking again
    }
    return 0;
}
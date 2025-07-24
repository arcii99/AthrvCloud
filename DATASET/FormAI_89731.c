//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <unistd.h>

int main()
{
    long int pid = getpid(); // get the current process id
    char cmd[50];
    sprintf(cmd, "cat /proc/%ld/status | grep VmRSS", pid); // create a command to retrieve the current process' resident set size (RSS)
    FILE* fp;
    char output[100];
    while(1)
    {
        fp = popen(cmd, "r"); // execute the command and open a pipe to read the output
        fgets(output, sizeof(output), fp); // read the output
        pclose(fp); // close the pipe

        printf("%s", output); // print the output (which should be in the format of "VmRSS:\t XXXX kB\n")

        sleep(1); // wait 1 second
    }
    return 0;
}
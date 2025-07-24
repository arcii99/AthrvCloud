//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    // Create a file called "log.txt" with read-write access
    int fd = open("log.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    // Redirect stdout and stderr to the "log.txt" file using dup2
    if (dup2(fd, STDOUT_FILENO) == -1 || dup2(fd, STDERR_FILENO) == -1)
    {
        printf("Error redirecting output!\n");
        exit(1);
    }
    
    // Close the original file descriptor since it has been duplicated
    close(fd);
    
    // Print a message to confirm that the stdout and stderr have been redirected
    printf("Stdout and stderr have been redirected to \"log.txt\"\n");
    
    // Write a message to the log file
    char logMessage[] = "This is a message that will be written to the log file\n";
    if (write(STDOUT_FILENO, logMessage, sizeof(logMessage)-1) == -1)
    {
        printf("Error writing to file!\n");
        exit(1);
    }
    
    // Close stdout and stderr to ensure that all the data has been flushed to the log file
    fclose(stdout);
    fclose(stderr);
    
    return 0;
}
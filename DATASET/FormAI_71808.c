//FormAI DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char buf[512];
    ssize_t num_bytes;

    if (argc != 3)
    {
        printf("Usage: %s SOURCE_FILE DESTINATION_FILE\n", argv[0]);
        exit(1);
    }
    
    fd1 = open(argv[1], O_RDONLY);
    
    if (fd1 == -1)
    {
        printf("Error: Unable to open the source file!\n");
        exit(1);
    }
    
    fd2 = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU|S_IRGRP|S_IROTH);
    
    if (fd2 == -1)
    {
        printf("Error: Unable to create the destination file!\n");
        exit(1);
    }
    
    while ((num_bytes = read(fd1, buf, sizeof(buf))) > 0)
    {
        if (write(fd2, buf, num_bytes) != num_bytes)
        {
            printf("Error: Unable to write data to destination file!\n");
            exit(1);
        }
    }
    
    if (num_bytes == -1)
    {
        printf("Error: Unable to read data from source file!\n");
        exit(1);
    }

    printf("The file was successfully copied!\n");

    if (close(fd1) == -1)
    {
        printf("Error: Unable to close the source file!\n");
        exit(1);
    }
    
    if (close(fd2) == -1)
    {
        printf("Error: Unable to close the destination file!\n");
        exit(1);
    }

    return 0;
}
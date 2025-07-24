//FormAI DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{   
    // check if the user has specified a filename in the command line argument
    if (argc == 1) {
        printf("No file specified!\n");
        exit(1);
    }

    // check if the user has specified the correct number of arguments
    if (argc > 2) {
        printf("Too many arguments!\n");
        exit(1);
    }

    // open file
    int fd = open(argv[1], O_RDWR);

    // check if the file exists
    if (fd == -1) {
        printf("File does not exist!\n");
        exit(1);
    }

    // lock file
    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0};
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        printf("File is already locked!\n");
        exit(1);
    }

    // read and display contents of file
    char buf[1024];
    ssize_t len;
    while ((len = read(fd, buf, sizeof(buf))) > 0) {
        printf("%.*s", (int) len, buf);
    }

    // write to file
    char message[1024];
    printf("Enter message to write to file: ");
    fgets(message, 1024, stdin);
    write(fd, message, sizeof(message));

    // unlock file
    fl.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &fl);

    // close file
    close(fd);

    return 0;
}
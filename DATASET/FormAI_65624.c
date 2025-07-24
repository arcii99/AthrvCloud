//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/* "Communication is essential in all areas of life, including programming." - Claude Shannon */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char * msg1 = "Hello,";
    char * msg2 = "world!";
    char buf[12];

    /* Creating the named pipe */
    mkfifo("myfifo", 0666);

    /* Opening the named pipe in write-only mode */
    fd = open("myfifo", O_WRONLY);

    /* Writing to the named pipe */
    write(fd, msg1, sizeof(msg1));
    write(fd, msg2, sizeof(msg2));

    /* Closing the named pipe */
    close(fd);

    /* Opening the named pipe in read-only mode */
    fd = open("myfifo", O_RDONLY);

    /* Reading from the named pipe */
    read(fd, buf, sizeof(buf));

    /* Printing out the message received from the named pipe */
    printf("%s\n", buf);

    /* Closing the named pipe */
    close(fd);

    /* Removing the named pipe */
    unlink("myfifo");

    return 0;
}
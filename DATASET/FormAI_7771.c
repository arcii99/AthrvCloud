//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int filedescriptor1, filedescriptor2;
    char *myfifo = "/tmp/myfifo";
    char inbuf[100], outbuf[100];

    mkfifo(myfifo, 0666);

    filedescriptor1 = open(myfifo, O_WRONLY);
    printf("Enter a message to send: ");
    fgets(outbuf, sizeof(outbuf), stdin);

    write(filedescriptor1, outbuf, sizeof(outbuf));
    close(filedescriptor1);

    filedescriptor2 = open(myfifo, O_RDONLY);
    read(filedescriptor2, inbuf, sizeof(inbuf));

    printf("Received message: %s\n", inbuf);
    close(filedescriptor2);

    unlink(myfifo);
    return 0;
}
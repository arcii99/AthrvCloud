//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyS1"

int main(int argc, char *argv[])
{
    int fd, c, res;
    struct termios oldtio, newtio;
    char buf[255];

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror(MODEMDEVICE);
        exit(-1);
    }

    tcgetattr(fd, &oldtio);
    memset(&newtio, 0, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR | ICRNL;
    newtio.c_oflag = 0;
    newtio.c_lflag = ICANON;
    newtio.c_cc[VTIME] = 0;
    newtio.c_cc[VMIN] = 1;
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    while (1) {
        res = read(fd, buf, sizeof(buf));
        if (res < 0) {
            perror("read error");
            break;
        }
        if (res > 0) {
            buf[res] = 0;
            printf("received: %s", buf);
            if (strcmp(buf, "UP\n") == 0) {
                printf("moving drone up\n");
                // code to move drone up
            } else if (strcmp(buf, "DOWN\n") == 0) {
                printf("moving drone down\n");
                // code to move drone down
            } else if (strcmp(buf, "LEFT\n") == 0) {
                printf("moving drone left\n");
                // code to move drone left
            } else if (strcmp(buf, "RIGHT\n") == 0) {
                printf("moving drone right\n");
                // code to move drone right
            } else if (strcmp(buf, "STOP\n") == 0) {
                printf("stopping drone\n");
                // code to stop drone
            } else {
                printf("invalid command\n");
            }
        }
    }

    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);
    return 0;
}
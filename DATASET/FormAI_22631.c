//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main() {
    int fd;
    struct termios options;
    char command[100];

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }

    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~CRTSCTS;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;

    tcsetattr(fd, TCSANOW, &options);

    while (1) {
        fgets(command, 100, stdin);

        if (strcmp(command, "move forward\n") == 0) {
            write(fd, "F", 1);
        }
        else if (strcmp(command, "turn left\n") == 0) {
            write(fd, "L", 1);
        }
        else if (strcmp(command, "turn right\n") == 0) {
            write(fd, "R", 1);
        }
        else if (strcmp(command, "stop\n") == 0) {
            write(fd, "S", 1);
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
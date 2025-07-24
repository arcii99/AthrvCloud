//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ESC 27

int main()
{
    const char *portname = "/dev/ttyACM0"; // Change this port name to match your serial port
    int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        perror("Error opening serial port");
        return -1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof tty);
    if (tcgetattr(fd, &tty) != 0)
    {
        perror("Error getting serial attributes");
        close(fd);
        return -1;
    }

    cfsetospeed(&tty, B9600); // Set baud rate
    cfsetispeed(&tty, B9600);

    tty.c_cflag &= ~PARENB; // no parity bit
    tty.c_cflag &= ~CSTOPB; // 1 stop bit
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8; // 8 data bits

    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
    tty.c_cc[VMIN] = 1; // Read at least 1 character
    tty.c_cc[VTIME] = 5; // Wait for 0.5 seconds before timing out

    if (tcsetattr(fd, TCSANOW, &tty) != 0)
    {
        perror("Error setting serial attributes");
        close(fd);
        return -1;
    }

    char input;
    printf("Press ESC to exit\n");

    while (1)
    {
        input = getchar();
        if (input == ESC) // Exit loop if ESC key is pressed
            break;
        else if (input == 'w')
        {
            write(fd, "w", 1); // Send command to move forward
            printf("Moving Forward\n");
        }
        else if (input == 'a')
        {
            write(fd, "a", 1); // Send command to turn left
            printf("Turning Left\n");
        }
        else if (input == 'd')
        {
            write(fd, "d", 1); // Send command to turn right
            printf("Turning Right\n");
        }
        else if (input == 's')
        {
            write(fd, "s", 1); // Send command to move backward
            printf("Moving Backward\n");
        }
        else
            printf("Invalid Input\n");
    }

    close(fd);
    return 0;
}
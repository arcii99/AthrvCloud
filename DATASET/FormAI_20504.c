//FormAI DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define SPEED 50000

int set_interface_attribs (int fd, int speed, int parity);
void set_blocking (int fd, int should_block);

int main()
{
    int direction = UP;
    int position_x = 16, position_y = 10;
    char c;
    int fd = open ("/dev/ttyS0", O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        printf("Error opening device.\n");
        exit(EXIT_FAILURE);
    }
    set_interface_attribs (fd, B9600, 0);
    set_blocking (fd, 0);

    while(1)
    {
        switch (direction)
        {
            case LEFT:
                position_x--;
                write(fd, "L", 1);
                break;
            case RIGHT:
                position_x++;
                write(fd, "R", 1);
                break;
            case UP:
                position_y--;
                write(fd, "U", 1);
                break;
            case DOWN:
                position_y++;
                write(fd, "D", 1);
                break;
        }
        printf("\x1b[2J\x1b[1;1H");
        printf("ROBOT POSITION: (%d, %d)\n", position_x, position_y);
        printf("USE ARROW KEYS TO MOVE.\n");

        usleep(SPEED);

        if (read(STDIN_FILENO, &c, 1) > 0)
        {
            switch (c)
            {
                case '\x1b':
                    direction = -1;
                    break;
                case '[':
                    if (read(STDIN_FILENO, &c, 1) > 0)
                    {
                        switch (c)
                        {
                            case 'A':
                                direction = UP;
                                break;
                            case 'B':
                                direction = DOWN;
                                break;
                            case 'C':
                                direction = RIGHT;
                                break;
                            case 'D':
                                direction = LEFT;
                                break;
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}

int set_interface_attribs (int fd, int speed, int parity)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);
    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_lflag = 0;                // no signaling chars, no echo,
                                    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl
    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (fd, TCSANOW, &tty) != 0)
    {
        printf("Error with tcsetattr.\n");
        exit(EXIT_FAILURE);
    }
}

void set_blocking (int fd, int should_block)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0)
    {
        printf("Error with tcgetattr.\n");
        exit(EXIT_FAILURE);
    }
    tty.c_cc[VMIN]  = should_block ? 1 : 0;
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout
    if (tcsetattr (fd, TCSANOW, &tty) != 0)
    {
        printf("Error with tcsetattr.\n");
        exit(EXIT_FAILURE);
    }
}
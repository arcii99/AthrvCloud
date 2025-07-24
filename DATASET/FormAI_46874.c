//FormAI DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#define I2C_DEV "/dev/i2c-1"
#define ADDR 0x12

int fd;

void forward()
{
    unsigned char buf[1] = {0x01};
    if (write(fd, buf, 1) != 1)
    {
        printf("Error writing forward command.\n");
        exit(1);
    }
}

void backward()
{
    unsigned char buf[1] = {0x02};
    if (write(fd, buf, 1) != 1)
    {
        printf("Error writing backward command.\n");
        exit(1);
    }
}

void left()
{
    unsigned char buf[1] = {0x03};
    if (write(fd, buf, 1) != 1)
    {
        printf("Error writing left command.\n");
        exit(1);
    }
}

void right()
{
    unsigned char buf[1] = {0x04};
    if (write(fd, buf, 1) != 1)
    {
        printf("Error writing right command.\n");
        exit(1);
    }
}

void stop()
{
    unsigned char buf[1] = {0x05};
    if (write(fd, buf, 1) != 1)
    {
        printf("Error writing stop command.\n");
        exit(1);
    }
}

int main()
{
    if ((fd = open(I2C_DEV, O_RDWR)) < 0)
    {
        printf("Error opening i2c device.\n");
        exit(1);
    }

    if (ioctl(fd, I2C_SLAVE, ADDR) < 0)
    {
        printf("Error setting i2c slave address.\n");
        exit(1);
    }

    printf("Commands: 'f' for forward, 'b' for backward, 'l' for left, 'r' for right, 's' for stop.\n");

    while (1)
    {
        char input[10];
        printf("> ");
        fgets(input, 10, stdin);
        strtok(input, "\n");

        if (strcmp(input, "f") == 0)
        {
            forward();
        }
        else if (strcmp(input, "b") == 0)
        {
            backward();
        }
        else if (strcmp(input, "l") == 0)
        {
            left();
        }
        else if (strcmp(input, "r") == 0)
        {
            right();
        }
        else if (strcmp(input, "s") == 0)
        {
            stop();
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    close(fd);
    return 0;
}
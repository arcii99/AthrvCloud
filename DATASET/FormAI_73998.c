//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B9600
#define PORT "/dev/ttyACM0" // Change this to the appropriate port
#define TIMEOUT 10 // In seconds
#define BUF_SIZE 256

int main(void) {
    int fd;
    struct termios options;
    fd_set set;
    struct timeval timeout;
    char buffer[BUF_SIZE];
    int n;

    printf("Initializing connection...\n");

    // Open the port
    fd = open(PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Error opening port");
        exit(1);
    }

    // Set the port settings
    tcgetattr(fd, &options);
    cfsetospeed(&options, BAUDRATE);
    cfsetispeed(&options, BAUDRATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_oflag &= ~OPOST;
    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = TIMEOUT;
    tcsetattr(fd, TCSANOW, &options);

    // Wait for the Arduino to initialize
    sleep(2);

    printf("Connection established.\n");

    while (1) {
        // Clear the set and add the file descriptor
        FD_ZERO(&set);
        FD_SET(fd, &set);

        // Set the timeout
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        // Wait for data to read
        if (select(fd + 1, &set, NULL, NULL, &timeout) > 0) {
            if (FD_ISSET(fd, &set)) {
                // Read the data
                n = read(fd, buffer, BUF_SIZE);
                if (n == -1) {
                    perror("Error reading from serial port");
                    exit(1);
                }

                // Null-terminate the data
                buffer[n] = '\0';

                // Print the data
                printf("Temperature: %s\n", buffer);
            }
        }
    }

    // Close the connection
    close(fd);

    return 0;
}
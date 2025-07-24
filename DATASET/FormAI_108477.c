//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: careful
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main() {

    int fd; /* File descriptor for the port */
    struct termios options; /* Structure to store the port settings */
    srand(time(NULL)); /* Seed random with the current time */

    // Initialize serial port
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    fcntl(fd, F_SETFL, 0);
    tcgetattr(fd, &options);
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CRTSCTS;
    tcsetattr(fd, TCSANOW, &options);

    char command[8];
    int yaw = 0;
    int roll = 0;
    int pitch = 0;
    int throttle = 0;

    // Loop until user enters 'q' to quit
    while(1) {

        // Generate random values for yaw, roll, pitch, and throttle
        yaw = rand() % 201 - 100;
        roll = rand() % 201 - 100;
        pitch = rand() % 201 - 100;
        throttle = rand() % 101;

        // Construct command string
        sprintf(command, "a%03d%03d%03d%03d", yaw, roll, pitch, throttle);

        // Send command to drone
        write(fd, command, 8);

        usleep(25000); // Sleep for 25ms

        // Check if user entered 'q' to quit
        char input;
        if (read(STDIN_FILENO, &input, 1) != -1) {
            if (input == 'q') {
                break;
            }
        }
    }

    // Close serial port
    close(fd);
    return 0;
}
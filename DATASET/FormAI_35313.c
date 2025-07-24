//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int main(void) {
    int fd; // File Descriptor for keyboard input
    struct termios original_termios; // Termios struct for saving original terminal attributes
    struct termios raw; // Termios struct for configuring raw input mode

    // Open file descriptor for keyboard input
    fd = open("/dev/tty", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Save original terminal attributes
    if (tcgetattr(fd, &original_termios) == -1) {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    // Configure raw input mode
    raw = original_termios;
    cfmakeraw(&raw);
    raw.c_lflag &= ~(ECHO | ICANON); // Turn off echo and canonical mode
    raw.c_cc[VMIN] = 0; // Set read to return 0 if no input
    raw.c_cc[VTIME] = 1; // Set read to return after 100ms of no input

    // Set new terminal attributes
    if (tcsetattr(fd, TCSAFLUSH, &raw) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }

    // Simulation loop
    int x = 0, y = 0;
    while (1) {
        // Read keyboard input
        char c;
        if (read(fd, &c, 1) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Move vehicle based on keyboard input
        switch (c) {
            case 'a':
                x--;
                break;
            case 'd':
                x++;
                break;
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
        }

        // Print current vehicle position
        printf("\033[2J\033[1;1H"); // Clear screen
        printf("Vehicle position: (%d, %d)\n", x, y);

        // Sleep for 100ms
        usleep(100000);
    }

    // Restore original terminal attributes
    if (tcsetattr(fd, TCSAFLUSH, &original_termios) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
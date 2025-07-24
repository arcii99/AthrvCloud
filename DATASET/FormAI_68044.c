//FormAI DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function declarations
void toggle_lights(int signal);
bool lights_on();

// Global variables
volatile sig_atomic_t light_status = 0;
char* fifo_name = "/tmp/smart_home_light_control";

int main() {
    // Create a FIFO
    mkfifo(fifo_name, 0666);

    // Register signal handler for toggling light status
    signal(SIGUSR1, toggle_lights);

    // Check if lights are on or off initially
    light_status = lights_on();

    // Open FIFO for reading
    int fd;
    char buff[20];
    while (true) {
        fd = open(fifo_name, O_RDONLY);
        read(fd, buff, 20);
        if (strcmp(buff, "toggle") == 0) {
            // Send signal to toggle the lights
            pid_t pid = getpid();
            if (kill(pid, SIGUSR1) == 0) {
                // Wait for signal to be handled
                sleep(1);

                // Check light status and send response
                if (light_status == 1) {
                    printf("Lights are now on.\n");
                } else {
                    printf("Lights are now off.\n");
                }
            }
        }
        close(fd);
    }

    return 0;
}

// Function to toggle light status
void toggle_lights(int signal) {
    light_status = !light_status;
}

// Function to check if lights are on
bool lights_on() {
    srand(time(0));
    return rand() % 2;
}
//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_USAGE_FILE "/proc/stat"

int main(int argc, char *argv[]) {

    // Open the CPU usage file
    int fd = open(CPU_USAGE_FILE, O_RDONLY);
    if (fd < 0) {
        printf("Error opening CPU usage file\n");
        return -1;
    }

    // Read the initial values
    char buffer[1024];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        printf("Error reading CPU usage file\n");
        close(fd);
        return -1;
    }
    // Set the initial user, nice, system, and idle times
    int user_time, nice_time, system_time, idle_time;
    sscanf(buffer, "cpu %d %d %d %d", &user_time, &nice_time, &system_time, &idle_time);

    while (1) {
        // Sleep for one second
        sleep(1);

        // Seek to the start of the file
        if (lseek(fd, 0, SEEK_SET) < 0) {
            printf("Error seeking to start of CPU usage file\n");
            close(fd);
            return -1;
        }

        // Read the new values
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            printf("Error reading CPU usage file\n");
            close(fd);
            return -1;
        }

        // Parse the new values
        int new_user_time, new_nice_time, new_system_time, new_idle_time;
        sscanf(buffer, "cpu %d %d %d %d", &new_user_time, &new_nice_time, &new_system_time, &new_idle_time);

        // Calculate the total and idle times
        int total_time = (new_user_time + new_nice_time + new_system_time) - (user_time + nice_time + system_time);
        int idle_delta = new_idle_time - idle_time;
        float usage = 100.0 * (total_time - idle_delta) / total_time;

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", usage);

        // Set the user, nice, system, and idle times for the next iteration
        user_time = new_user_time;
        nice_time = new_nice_time;
        system_time = new_system_time;
        idle_time = new_idle_time;
    }

    // Close the file and exit
    close(fd);
    return 0;
}
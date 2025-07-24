//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// This program reads the temperature values from a thermal file and converts them to Celsius.
// The thermal file is system-specific, so it might need to be changed for different systems.

int main(int argc, char* argv[])
{
    char* thermal_file = "/sys/class/thermal/thermal_zone0/temp";
    char buf[256];
    int fd, len;
    double temp;

    // Open the thermal file
    fd = open(thermal_file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read the temperature value from the thermal file
    len = read(fd, buf, sizeof(buf)-1);
    if (len == -1) {
        perror("read");
        exit(1);
    }

    // Add null terminator to the buffer
    buf[len] = '\0';

    // Convert the temperature value to Celsius
    temp = atof(buf) / 1000.0;

    // Print the temperature value in Celsius
    printf("Temperature: %.2f C\n", temp);

    // Close the thermal file
    close(fd);

    return 0;
}
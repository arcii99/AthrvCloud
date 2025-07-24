//FormAI DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define TEMP_SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"

int main()
{
    int fd;
    char temp[6];

    // Open the temperature sensor file
    fd = open(TEMP_SENSOR_PATH, O_RDONLY);
    if (fd < 0)
    {
        perror("Error: Could not open the temperature sensor file");
        exit(1);
    }

    // Read current temperature from file
    read(fd, temp, 6);

    // Close the file
    close(fd);

    // Convert temperature from mC to C
    float celsius_temp = atof(temp) / 1000;

    // Print the temperature
    printf("Current Temperature: %.2f°C\n", celsius_temp);
    return 0;
}
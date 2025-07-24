//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"

// Function to read the temperature value from the system file
float read_temperature(){
    int fd = open(TEMP_FILE, O_RDONLY);
    if(fd < 0){
        printf("Error opening cpu temperature file.\n");
        exit(1);
    }

    char temperature_str[6] = {'\0'};
    int temperature_int = 0;

    read(fd, temperature_str, sizeof(temperature_str));
    close(fd);

    temperature_int = atoi(temperature_str);
    float temperature_celsius = temperature_int / 1000.0;

    return temperature_celsius;
}

int main(int argc, char *argv[]) {
    
    float temperature = read_temperature();

    // Print the current temperature with timestamp
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    printf("Current Temperature: %.2f °C\t Time: %s", temperature, c_time_string);

    return 0;
}
//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMPERATURE_FILEPATH "/sys/class/thermal/thermal_zone0/temp"

void print_temperature() {
    FILE *temp_file = fopen(TEMPERATURE_FILEPATH, "r");
    if (temp_file == NULL) {
        printf("Error opening temperature file.\n");
        exit(1);
    }

    char temp_str[256];
    fgets(temp_str, sizeof(temp_str), temp_file);

    float temperature = atoi(temp_str) / 1000.0;

    printf("Current temperature: %0.2f°C\n", temperature);

    fclose(temp_file);
}

int main() {
    printf("Starting temperature monitor...\n");

    while (1) {
        print_temperature();
        sleep(5);
    }

    return 0;
}
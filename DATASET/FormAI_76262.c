//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp;
    char filename[100] = "temp_monitor.txt";
    char input[50];
    float temperature;

    fp = fopen(filename, "a+");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Temperature Monitor\n");
    printf("===================\n");

    while (1) {
        printf("Enter temperature value (in Celsius) or type 'quit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        temperature = atof(input);

        if (temperature < -273.15) {
            printf("Invalid temperature value entered. Temperature cannot be below absolute zero.\n");
            continue;
        }

        printf("Temperature value (in Celsius): %.2f\n", temperature);
        fprintf(fp, "%.2f\n", temperature);
    }

    printf("Temperature data logged to file %s.\n", filename);

    fclose(fp);

    return 0;
}
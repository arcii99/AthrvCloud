//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char path[50];
    float temp;

    // ask user for the path to the thermal zone file
    printf("Enter path to thermal zone file: ");
    scanf("%s", path);

    // attempt to open the thermal zone file for reading
    fp = fopen(path, "r");

    // check if file was opened successfully
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    // read the temperature from the thermal zone file
    fscanf(fp, "%f", &temp);
    temp /= 1000;

    // print the temperature to the user
    printf("Current temperature: %.1f C\n", temp);

    // close the file
    fclose(fp);

    return 0;
}
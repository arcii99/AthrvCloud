//FormAI DATASET v1.0 Category: Data recovery tool ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    FILE *file;
    char *filename = "example.txt";
    char line[MAX_SIZE];
    char recovered_data[MAX_SIZE] = "";
    int i;
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Could not open file %s", filename);
        exit(EXIT_FAILURE);
    }
    
    while (fgets(line, MAX_SIZE, file) != NULL) {
        strcat(recovered_data, line);
    }
    
    fclose(file);
    
    printf("Recovered data:\n%s", recovered_data);
    
    return 0;
}
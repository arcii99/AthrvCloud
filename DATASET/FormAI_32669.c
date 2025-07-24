//FormAI DATASET v1.0 Category: Data recovery tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[50], ch;
    long int size;
    int i = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Could not open file %s", filename);
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *buffer = malloc(size * sizeof(char));

    if (buffer == NULL) {
        printf("Memory error: could not allocate buffer");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        buffer[i] = ch;
        i++;
    }

    fclose(fp);

    // Data recovery tool begins here
    for (int j = 0; j < size; j++){
        if (buffer[j] == 0){
            buffer[j] = ' ';
        }
    }

    printf("File data:\n%s", buffer);
    free(buffer);
    
    return 0;
}
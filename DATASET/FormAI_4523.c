//FormAI DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.txt"
#define MAX_DATA 100

int main()
{
    int i, count = 0;
    char data[MAX_DATA][MAX_DATA];
    FILE *fp;

    fp = fopen(FILENAME, "r");
    
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    while (fgets(data[count], MAX_DATA, fp) != NULL) {
        count++;
    }

    printf("Data recovered from %s:\n", FILENAME);
    for (i = 0; i < count; i++) {
        printf("%s", data[i]);
    }

    fclose(fp);
    
    return 0;
}
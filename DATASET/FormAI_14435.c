//FormAI DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    char filename[20];
    int n, i, sum = 0;

    printf("Enter the filename to open: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL){
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", &n);

    int numbers[n];

    for(i=0; i<n; i++){
        fscanf(file, "%d", &numbers[i]);
    }

    fclose(file);

    file = fopen("output.txt", "w");

    if(file == NULL){
        printf("Error: Could not create output file.\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<n; i++){
        fprintf(file, "%d\n", numbers[i]);
        sum += numbers[i];
    }

    fprintf(file, "Sum = %d\n", sum);

    fclose(file);

    printf("File read and wrote successfully.\n");
    return 0;
}
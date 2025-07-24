//FormAI DATASET v1.0 Category: File handling ; Style: irregular
#include <stdio.h>

int main() {

    // Let's create an array of 10 integers
    int arr[10];

    // Open a file name data.txt in write mode
    FILE *file = fopen("data.txt", "w");

    if(file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    printf("Enter 10 integers:\n");

    // Take input from the user and write into the file
    for(int i=0; i<10; i++) {
        scanf("%d", &arr[i]);
        fprintf(file, "%d\n", arr[i]);
    }

    printf("Data has been written to file successfully!\n");

    // Close the file
    fclose(file);

    // Open the same file in read mode
    file = fopen("data.txt", "r");

    if(file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read the contents of the file and print them on the console
    int num;
    printf("Reading data from file:\n");
    while(fscanf(file, "%d", &num) != EOF) {
        printf("%d\n", num);
    }

    // Close the file
    fclose(file);

    return 0;
}
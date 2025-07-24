//FormAI DATASET v1.0 Category: Data recovery tool ; Style: introspective
#include <stdio.h>

// Function to recover data from a file
void recover_data(char *file_name) {
    FILE *f = fopen(file_name, "rb");

    if (f == NULL) {
        printf("File not found!\n");
        return;
    }

    // Read and print bytes from the file
    int byte;
    while ((byte = fgetc(f)) != EOF) {
        printf("%c", byte);
    }

    // Close the file
    fclose(f);

    printf("Data recovered successfully!");
}

// Main function
int main() {
    char file_name[100];

    // Take input file name from the user
    printf("Enter the name of the file to recover: ");
    scanf("%s", file_name);

    // Recover data from the file
    recover_data(file_name);

    return 0;
}
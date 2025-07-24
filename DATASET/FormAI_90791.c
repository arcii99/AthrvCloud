//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>

// Calculate the checksum of input file
int main() {
    FILE *file_pointer;
    char filename[100];
    unsigned char hex;
    long sum = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file_pointer = fopen(filename, "rb");

    // Check if file exists
    if (file_pointer == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    // Read each byte in file and calculate checksum
    while (fread(&hex, 1, 1, file_pointer) == 1) {
        sum += hex;
    }

    // Print checksum result
    printf("Checksum is %02X.\n", (unsigned int)sum);

    fclose(file_pointer);
    return 0;
}
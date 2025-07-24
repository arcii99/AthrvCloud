//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100], ch;
    unsigned int crc = 0xFFFFFFFF;

    printf("Enter the name of file to calculate checksum: ");
    scanf("%s", filename);

    file = fopen(filename, "rb");

    if (file == NULL) {
        printf("File not found.\n");
        return 0;
    }

    while ((ch = fgetc(file)) != EOF) {
        crc ^= ch;

        for (int i = 0; i < 8; i++)
            crc = (crc & 1) ? (crc >> 1) ^ 0xEDB88320u : crc >> 1;
    }

    printf("The checksum of %s is %X\n", filename, crc ^ 0xFFFFFFFF);

    fclose(file);
    return 0;
}
//FormAI DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    char file_name[100];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size * sizeof(char));
    fread(buffer, sizeof(char), file_size, file);
    fclose(file);

    int key = 42;

    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key;
        key += 3;
    }

    char encrypted_file_name[100];
    sprintf(encrypted_file_name, "%s.enc", file_name);

    FILE *encrypted_file = fopen(encrypted_file_name, "wb");
    fwrite(buffer, sizeof(char), file_size, encrypted_file);
    fclose(encrypted_file);

    free(buffer);

    printf("File '%s' has been encrypted into '%s'.\n", file_name, encrypted_file_name);

    return 0;
}
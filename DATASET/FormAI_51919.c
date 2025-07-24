//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 256
#define MAX_FILE_SIZE 1024 * 1024

void recover_file(char *filename, char *recovered_data);

int main(int argc, char *argv[]) {
    char *recovered_data = malloc(MAX_FILE_SIZE);
    recover_file(argv[1], recovered_data);
    printf("Recovered data: %s", recovered_data);
    free(recovered_data);
    return 0;
}

void recover_file(char *filename, char *recovered_data) {
    FILE *f;
    int i, num_chars;

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file %s", filename);
        exit(1);
    }

    num_chars = fread(recovered_data, sizeof(char), MAX_FILE_SIZE - 1, f);
    if (num_chars == 0) {
        printf("No data found in file %s", filename);
        exit(2);
    }

    fclose(f);

    for (i = 0; i < num_chars; i++) {
        if (recovered_data[i] == '\0') {
            recovered_data[i] = '?';
        }
    }
}
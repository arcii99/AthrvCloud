//FormAI DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>

// function to encrypt the file
void encrypt_file(FILE *file_in, FILE *file_out, char key[]) {
    int c;
    int i = 0;
    while ((c = fgetc(file_in)) != EOF) {
        if (i == sizeof(key)-1) i = 0;
        fputc(c ^ key[i], file_out);
        i++;
    }
}

// function to prompt user for encryption key
void get_key(char key[]) {
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);
}

int main() {
    char key[100];
    get_key(key);

    FILE *file_in = fopen("test.txt", "r"); // open input file in read mode
    FILE *file_out = fopen("encrypted.txt", "w"); // open output file in write mode

    if (file_in == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    encrypt_file(file_in, file_out, key);

    printf("File encrypted successfully!\n");

    fclose(file_in);
    fclose(file_out);

    return 0;
}
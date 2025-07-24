//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <string.h>

void encrypt(char* input_file, char* output_file, int key);

int main() {
    char input_file[50], output_file[50];
    int key;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(input_file, output_file, key);

    printf("File has been encrypted!\n");

    return 0;
}

void encrypt(char* input_file, char* output_file, int key) {
    FILE *ifp, *ofp;
    char ch;

    ifp = fopen(input_file, "r");
    ofp = fopen(output_file, "w");

    while((ch = fgetc(ifp)) != EOF) {
        ch = ch + key;
        fputc(ch, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}
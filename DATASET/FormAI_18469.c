//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256

void generate_key(unsigned char *key) {
    int i, j, k;
    unsigned char s[KEY_SIZE];
    for (i = 0; i < KEY_SIZE; i++) {
        s[i] = i;
        key[i] = 0;
    }
    j = 0;
    for (i = 0; i < KEY_SIZE; i++) {
        j = (j + s[i] + key[i]) % KEY_SIZE;
        k = s[i];
        s[i] = s[j];
        s[j] = k;
    }
    i = 0;
    j = 0;
    for (k = 0; k < KEY_SIZE; k++) {
        i = (i + 1) % KEY_SIZE;
        j = (j + s[i]) % KEY_SIZE;
        unsigned char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        key[k] = s[(s[i] + s[j]) % KEY_SIZE];
    }
}

void encrypt(char *input_file, char *output_file, unsigned char *key) {
    FILE *fp1, *fp2;
    unsigned char buffer[KEY_SIZE];
    int i, j, len;
    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");
    while (!feof(fp1)) {
        len = fread(buffer, 1, KEY_SIZE, fp1);
        for (i = 0; i < len; i++) {
            buffer[i] ^= key[i];
        }
        fwrite(buffer, 1, len, fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

int main() {
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";
    unsigned char key[KEY_SIZE];
    generate_key(key);
    encrypt(input_file, output_file, key);
    printf("Encryption successful. Key: ");
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");
    return 0;
}
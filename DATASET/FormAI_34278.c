//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50

void encrypt(char *str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] ^= key;
    }
}

void backup_file(char *filename) {
    FILE *src, *dest;
    char dest_filename[MAX_FILENAME_LEN + 10];
    sprintf(dest_filename, "%s.bak", filename);
    src = fopen(filename, "rb");
    dest = fopen(dest_filename, "wb");
    if (src && dest) {
        int ch;
        while ((ch = fgetc(src)) != EOF) {
            fputc(ch, dest);
        }
        fclose(src);
        fclose(dest);
        printf("%s backed up successfully\n", filename);
        encrypt(dest_filename, 0xAF);
        printf("Encrypted backup filename: %s\n", dest_filename);
    } else {
        printf("Error backing up file %s\n", filename);
    }
}

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter filename to backup: ");
    scanf("%s", filename);
    backup_file(filename);
    return 0;
}
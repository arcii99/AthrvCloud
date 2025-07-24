//FormAI DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    FILE *fp_in, *fp_out;
    char key[MAX_SIZE], file_in[MAX_SIZE], file_out[MAX_SIZE];
    int i = 0, key_len = 0, file_len = 0;
    
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_in);
    printf("Enter the name of the output file: ");
    scanf("%s", file_out);
    printf("Enter the key for encryption: ");
    scanf("%s", key);
    
    while (key[i] != '\0') {
        key_len++;
        i++;
    }
    
    i = 0;
    while (file_in[i] != '\0') {
        file_len++;
        i++;
    }
    
    fp_in = fopen(file_in, "r");
    fp_out = fopen(file_out, "w");
    
    int j = 0;
    char c;
    while ((c = fgetc(fp_in)) != EOF) {
        fputc(c ^ key[j % key_len], fp_out);
        j++;
    }
    
    printf("File encryption successful!\n");
    
    fclose(fp_in);
    fclose(fp_out);
    
    return 0;
}
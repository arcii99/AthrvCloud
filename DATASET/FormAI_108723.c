//FormAI DATASET v1.0 Category: File Encyptor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100], key[100], c;
    FILE *fp1, *fp2;
    
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);
    fp1 = fopen(filename, "r");
    
    if (fp1 != NULL) {
        printf("Enter your encryption key: ");
        scanf("%s", key);
        
        // Create encrypted file
        int key_len = strlen(key);
        strcat(filename, ".encrypted");
        fp2 = fopen(filename, "w");
        
        // Encrypt each character of file
        while ((c = fgetc(fp1)) != EOF) {
            c = c ^ key[key_len % strlen(key)];
            fputc(c, fp2);
        }
        
        fclose(fp1);
        fclose(fp2);
        
        printf("\nFile encrypted successfully!\n");
    } else {
        printf("File not found.\n");
    }
    
    return 0;
}
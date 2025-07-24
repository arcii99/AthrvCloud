//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include<stdio.h>
#include<string.h>

#define MAX_FILE_SIZE 100000
#define MAX_KEY_SIZE 100

void encrypt(char *input_file, char *output_file, char *key){
    FILE *fp1, *fp2;
    char ch;
    int key_length = strlen(key);
    int key_index = 0;
    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening file");
        return;
    }
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch ^ key[key_index], fp2);
        key_index++;
        if(key_index == key_length){
            key_index = 0;
        }
    }
    fclose(fp1);
    fclose(fp2);
}

int main(){
    char input_file[50], output_file[50], key[MAX_KEY_SIZE];
    printf("Enter the name of input file: ");
    scanf("%s", input_file);
    printf("Enter the name of output file: ");
    scanf("%s", output_file);
    printf("Enter the key (must be less than or equal to 100 characters): ");
    scanf("%s", key);
    encrypt(input_file, output_file, key);
    printf("Encryption successful.");
    return 0;
}
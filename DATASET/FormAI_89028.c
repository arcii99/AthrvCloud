//FormAI DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LEN 50

void encryptFile(char* filename, char* key){
    FILE* fp = fopen(filename,"r");
    if(fp == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    char encrypted_filename[MAX_FILE_LEN] = "encrypted_";
    strcat(encrypted_filename, filename);
    FILE* fp_encrypted = fopen(encrypted_filename,"w");
    if(fp_encrypted == NULL){
        printf("Error opening file for writing!\n");
        exit(1);
    }
    char c;
    int key_len = strlen(key);
    int i = 0;
    while((c = fgetc(fp)) != EOF){
        if(i == key_len){
            i = 0;
        }
        char encrypted_c = c ^ key[i];
        fputc(encrypted_c, fp_encrypted);
        i++;
    }
    fclose(fp);
    fclose(fp_encrypted);
    remove(filename);
    printf("File encrypted successfully!\n");
}

int main(){
    char filename[MAX_FILE_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);
    char key[MAX_FILE_LEN];
    printf("Enter key: ");
    scanf("%s", key);
    encryptFile(filename, key);
    return 0;
}
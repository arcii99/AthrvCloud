//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1024

void XORcrypt(char* buffer, int key){
    int len = strlen(buffer);
    for(int i = 0; i < len; i++){
        buffer[i] = buffer[i] ^ key;
    }
}

void encrypt(char* filename, int key){
    FILE *fp = fopen(filename, "r+");
    if(fp == NULL){
        printf("Error: Unable to open the file!\n");
        exit(1);
    }
    char buffer[MAX_SIZE];
    while(fgets(buffer, MAX_SIZE, fp)){
        XORcrypt(buffer, key);
        fseek(fp, -strlen(buffer), SEEK_CUR);
        fputs(buffer, fp);
    }
    fclose(fp);
}

int main(){
    char filename[50];
    int key;
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    encrypt(filename, key);
    printf("Encryption successful!\n");
    return 0;
}
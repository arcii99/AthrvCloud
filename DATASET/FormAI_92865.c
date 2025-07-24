//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *file_name, char *key){
    FILE *fptr;
    fptr = fopen(file_name,"rb+");
    if(fptr == NULL){
        printf("Error in opening file!\n");
        exit(1);
    }
    char buffer[100];
    int key_len = strlen(key);
    int i=0;
    while(fgets(buffer,sizeof(buffer),fptr)!=NULL){
        for(i=0;i<strlen(buffer);i++){
            int ascii_val = buffer[i];
            ascii_val = ascii_val ^ key[i%key_len];
            buffer[i] = (char)ascii_val;
        }
        fseek(fptr,-strlen(buffer),SEEK_CUR);
        fwrite(buffer,sizeof(char),strlen(buffer),fptr);
    }
    fclose(fptr);
}

int main(){
    char file_name[100];
    printf("Enter the name of the file to be encrypted:\n");
    scanf("%s",file_name);

    char key[100];
    printf("Enter the encryption key:\n");
    scanf("%s",key);

    encrypt(file_name,key);
    printf("Encryption successful!\n");

    return 0;
}
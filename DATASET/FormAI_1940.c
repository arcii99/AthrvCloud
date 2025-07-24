//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] += 5; // shifting ASCII value by 5 places
    }
}

void decrypt(char* str) {
    int len = strlen(str);
    for(int i=0; i<len; i++) {
        str[i] -= 5; // shifting ASCII value back by 5 places
    }
}

int main() {
    FILE* fp;
    fp = fopen("secret_file.txt", "w+"); //creating file

    if(fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    char message[50] = "This is a secret message!";
    encrypt(message);
    fprintf(fp, "%s", message);
    printf("Message successfully encrypted and written to file.\n");

    fclose(fp);
    fp = fopen("secret_file.txt", "r");

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char read_message[50];
    fscanf(fp, "%s", read_message);
    decrypt(read_message);
    printf("Message read from file: %s\n", read_message);

    fclose(fp);
    return 0;
}
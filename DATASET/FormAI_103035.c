//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>

void writeData() {
    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL){
        printf("Error: Unable to create file\n");
        return;
    }
    char data[20] = "Hello World!";
    fputs(data, fp);
    fclose(fp);
}

void readData() {
    FILE *fp;
    char data[20];
    fp = fopen("data.txt", "r");
    if (fp == NULL){
        printf("Error: Unable to open file\n");
        return;
    }
    fgets(data, 20, fp);
    printf("Data read from file: %s\n", data);
    fclose(fp);
}

int main() {
    writeData();
    readData();
    return 0;
}
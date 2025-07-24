//FormAI DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float value;
    char name[20];
} Record;

void recover(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: file %s not found\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp) / sizeof(Record);

    fseek(fp, 0, SEEK_SET);
    Record* data = (Record*) malloc(file_size * sizeof(Record));
    fread(data, sizeof(Record), file_size, fp);

    printf("Recovered data:\n");
    printf("ID\tValue\tName\n");
    for (int i = 0; i < file_size; i++) {
        printf("%d\t%.2f\t%s\n", data[i].id, data[i].value, data[i].name);
    }

    free(data);
    fclose(fp);
}

int main() {
    printf("Welcome to the unique C Data Recovery Tool!\n");

    char filename[50];
    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    recover(filename);
    
    printf("Thank you for using the unique C Data Recovery Tool!\n");
    return 0;
}
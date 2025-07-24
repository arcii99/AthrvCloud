//FormAI DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int id;
    char name[20];
    float value;
} Data;

void writeData(FILE *file, Data *data) {
    fwrite(&data->id, sizeof(int), 1, file);
    fwrite(&data->name, sizeof(char), 20, file);
    fwrite(&data->value, sizeof(float), 1, file);
}

void readData(FILE *file, Data *data) {
    fread(&data->id, sizeof(int), 1, file);
    fread(&data->name, sizeof(char), 20, file);
    fread(&data->value, sizeof(float), 1, file);
}

int main() {
    FILE *file = fopen("data.bin", "wb+");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }
    
    Data data1 = {1, "John", 12.5};
    Data data2 = {2, "Alice", 20.0};
    
    writeData(file, &data1);
    writeData(file, &data2);
    
    rewind(file);
    
    Data readData1, readData2;
    readData(file, &readData1);
    readData(file, &readData2);
    
    printf("%d, %s, %f\n", readData1.id, readData1.name, readData1.value);
    printf("%d, %s, %f\n", readData2.id, readData2.name, readData2.value);
    
    fclose(file);
    return 0;
}
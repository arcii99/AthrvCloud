//FormAI DATASET v1.0 Category: Data recovery tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for holding our data representation
struct data {
    int id;
    char name[50];
    float value;
};

// Define a function for writing a data object to a file
void write_data(FILE *file, struct data *data) {
    fwrite(&(data->id), sizeof(int), 1, file);
    fwrite(data->name, sizeof(char), 50, file);
    fwrite(&(data->value), sizeof(float), 1, file);
}

// Define a function for reading a data object from a file
void read_data(FILE *file, struct data *data) {
    fread(&(data->id), sizeof(int), 1, file);
    fread(data->name, sizeof(char),50, file);
    fread(&(data->value), sizeof(float), 1, file);
}

int main(void) {
    // Open our data file
    FILE *file = fopen("data.dat", "wb");
    if (file == NULL) {
        printf("Failed to open data file\n");
        return 1;
    }

    // Write some test data to the file
    struct data data1 = {1, "Data 1", 10.5};
    struct data data2 = {2, "Data 2", 20.5};
    struct data data3 = {3, "Data 3", 30.5};
    write_data(file, &data1);
    write_data(file, &data2);
    write_data(file, &data3);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("data.dat", "rb");
    if (file == NULL) {
        printf("Failed to open data file\n");
        return 1;
    }

    // Read the data objects from the file
    struct data data4;
    read_data(file, &data4);
    printf("%d, %s, %f\n", data4.id, data4.name, data4.value);

    struct data data5;
    read_data(file, &data5);
    printf("%d, %s, %f\n", data5.id, data5.name, data5.value);

    struct data data6;
    read_data(file, &data6);
    printf("%d, %s, %f\n", data6.id, data6.name, data6.value);

    // Close the file
    fclose(file);

    return 0;
}
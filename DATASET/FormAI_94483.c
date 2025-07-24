//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "data.bin"

struct node {
    int id;
    char name[50];
    float salary;
};

int main() {
    FILE *file;
    struct node data[10];

    // Check if the data file exists
    if ((file = fopen(DATA_FILE, "rb")) == NULL) {
        printf("Error: The data file '%s' does not exist!\n", DATA_FILE);
        exit(1);
    }

    // Read the data from the file
    fread(data, sizeof(struct node), 10, file);

    // Print the recovered data
    printf("Recovered data:\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d\nName: %s\nSalary: $%.2f\n\n", data[i].id, data[i].name, data[i].salary);
    }

    // Close the file
    fclose(file);

    return 0;
}
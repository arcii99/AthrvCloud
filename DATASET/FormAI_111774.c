//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct Data {
    int id;
    char name[50];
    float price;
};

int main() {
    struct Data data[100];
    int num_records;

    printf("Enter the number of records to recover: ");
    scanf("%d", &num_records);

    // Read data from file
    FILE *fp;
    fp = fopen("data.dat", "rb");
    if (fp == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    fread(data, sizeof(struct Data), num_records, fp);
    fclose(fp);

    // Display recovered data
    printf("\nRecovering %d records:\n", num_records);
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("ID: %d\n", data[i].id);
        printf("Name: %s\n", data[i].name);
        printf("Price: $%.2f\n\n", data[i].price);
    }

    return 0;
}
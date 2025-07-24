//FormAI DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

/* Structure definition for a car record */

typedef struct car_record {
    char make[20];
    char model[20];
    int year;
    int price;
} car_record;

#pragma pack()

/* Function to read car records from a binary file and output them */

void read_car_records(char *filename) {
    FILE *fp;

    /* Open binary file for reading */
    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        exit(1);
    }

    /* Read car records from file */
    car_record car;
    while (fread(&car, sizeof(car_record), 1, fp) == 1) {
        printf("Make: %s\n", car.make);
        printf("Model: %s\n", car.model);
        printf("Year: %d\n", car.year);
        printf("Price: %d\n\n", car.price);
    }

    /* Close file */
    fclose(fp);
}

/* Function to write car records to a binary file */

void write_car_records(char *filename) {
    FILE *fp;

    /* Open binary file for writing */
    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        exit(1);
    }

    /* Write car records to file */
    car_record car;

    strcpy(car.make, "Honda");
    strcpy(car.model, "Civic");
    car.year = 2021;
    car.price = 25000;
    fwrite(&car, sizeof(car_record), 1, fp);

    strcpy(car.make, "Toyota");
    strcpy(car.model, "Camry");
    car.year = 2020;
    car.price = 30000;
    fwrite(&car, sizeof(car_record), 1, fp);

    strcpy(car.make, "Ford");
    strcpy(car.model, "F-150");
    car.year = 2019;
    car.price = 40000;
    fwrite(&car, sizeof(car_record), 1, fp);

    /* Close file */
    fclose(fp);
}

int main(int argc, char **argv) {

    /* Write car records to binary file */
    write_car_records("car_records.bin");

    /* Read car records from binary file and output them */
    read_car_records("car_records.bin");

    return 0;
}
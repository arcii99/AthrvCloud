//FormAI DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

void writeToFile(FILE *fp, Person p) {
    fwrite(&p, sizeof(Person), 1, fp);
}

void readFromFile(FILE *fp) {
    Person p;
    while(fread(&p, sizeof(Person), 1, fp)) {
        printf("Name: %s\nAge: %d\nAddress: %s\n", p.name, p.age, p.address);
    }
}

int main() {
    FILE *fp;
    char filename[] = "people.bin";
    char mode[] = "ab+";
    fp = fopen(filename, mode);
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Person p1 = {"John", 25, "123 Main St"};
    Person p2 = {"Mary", 30, "456 Second St"};
    
    writeToFile(fp, p1);
    writeToFile(fp, p2);
    
    readFromFile(fp);

    fclose(fp);
    return 0;
}
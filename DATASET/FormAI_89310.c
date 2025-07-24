//FormAI DATASET v1.0 Category: Database querying ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct {
    char name[MAX_SIZE];
    int age;
    char address[MAX_SIZE];
} Person;

int main() {
    FILE* fp;
    Person people[3];
    int i;

    // Populate the array of persons
    strcpy(people[0].name, "John");
    people[0].age = 32;
    strcpy(people[0].address, "123 Main St, Anytown USA");

    strcpy(people[1].name, "Mary");
    people[1].age = 25;
    strcpy(people[1].address, "456 Elm St, Anytown USA");

    strcpy(people[2].name, "Michael");
    people[2].age = 41;
    strcpy(people[2].address, "789 Oak St, Anytown USA");

    // Write the records to a file
    fp = fopen("people.dat", "wb");
    fwrite(people, sizeof(Person), 3, fp);
    fclose(fp);

    // Open the file for reading
    fp = fopen("people.dat", "rb");

    // Read the file and display records of people who are over 30 years old
    while (fread(&people, sizeof(Person), 1, fp)) {
        if (people[0].age > 30) {
            printf("Name: %s\n", people[0].name);
            printf("Age: %d\n", people[0].age);
            printf("Address: %s\n", people[0].address);
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}
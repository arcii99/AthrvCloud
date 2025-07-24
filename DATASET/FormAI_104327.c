//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char occupation[20];
} Person;

int main() {
    FILE *file;
    char filename[30];
    printf("Enter filename for data recovery: ");
    fgets(filename, 30, stdin);
    strtok(filename, "\n"); //remove newline character from filename
    file = fopen(filename, "rb"); //open file in binary mode
    if (file == NULL) {
        printf("Error opening file. Please check if file exists and try again.");
        return 1;
    }

    //count number of records in file
    fseek(file, 0, SEEK_END); //go to end of file
    long int fileSize = ftell(file); //get current position in bytes
    int numOfRecords = fileSize / sizeof(Person); //calculate number of records
    fseek(file, 0, SEEK_SET); //go back to beginning of file

    //read records from file
    Person *people = malloc(sizeof(Person) * numOfRecords);
    if (people == NULL) {
        printf("Memory allocation error. Could not read records.");
        fclose(file);
        return 1;
    }
    fread(people, sizeof(Person), numOfRecords, file);

    //print recovered data in medieval style
    printf("Harken, ye knights and maidens! We have recovered the following data from yonder file:\n");
    printf("+------------------+-----+------------------+\n");
    printf("|      NAME        | AGE |    OCCUPATION     |\n");
    printf("+------------------+-----+------------------+\n");
    for (int i = 0; i < numOfRecords; i++) {
        printf("| %-16s | %3d | %-16s |\n", people[i].name, people[i].age, people[i].occupation);
    }
    printf("+------------------+-----+------------------+\n");

    free(people);
    fclose(file);
    return 0;
}
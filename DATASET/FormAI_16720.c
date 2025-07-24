//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// define a struct to store csv data
typedef struct {
    char name[MAX_LENGTH];
    int age;
    char address[MAX_LENGTH];
} person;

// function to read csv file
void read_csv(person people[], int *length, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file\n");
        exit(1);
    }
    char line[MAX_LENGTH];
    int i = 0;
    while (fgets(line, MAX_LENGTH, fp)) {
        char * name = strtok(line, ",");
        char * age_str = strtok(NULL, ",");
        char * address = strtok(NULL, ",");
        int age = atoi(age_str);
        strcpy(people[i].name, name);
        strcpy(people[i].address, address);
        people[i].age = age;
        i++;
    }
    *length = i;
    fclose(fp);
}

int main() {
    person people[MAX_LENGTH];
    int length;

    read_csv(people, &length, "data.csv");

    printf("Name\t\tAge\tAddress\n");
    for(int i = 0; i < length; i++) {
        printf("%s\t%d\t%s\n", people[i].name, people[i].age, people[i].address);
    }

    return 0;
}
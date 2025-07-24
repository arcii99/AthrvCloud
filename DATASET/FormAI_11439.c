//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct person {
    char name[50];
    int age;
};

int main() {
    int numofpersons;
    printf("Enter the number of persons you want to add: ");
    scanf("%d", &numofpersons);
    struct person *people = (struct person*) malloc(sizeof(struct person) * numofpersons);

    // Writing to file
    FILE *fptr = fopen("people.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file...");
        return 1;
    }
    for (int i = 0; i < numofpersons; i++) {
        printf("Enter name and age for person #%d: ", i + 1);
        scanf("%s%d", (people + i)->name, &(people + i)->age);
        fprintf(fptr, "%s %d\n", (people + i)->name, (people + i)->age);
    }
    fclose(fptr);

    // Reading from file
    fptr = fopen("people.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file...");
        return 1;
    }
    struct person temp;
    printf("\nReading from file:\n");
    while(fscanf(fptr, "%s%d", temp.name, &temp.age) == 2) {
        printf("Name: %s, Age: %d\n", temp.name, temp.age);
    }
    fclose(fptr);

    free(people);
    return 0;
}
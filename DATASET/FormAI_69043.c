//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
} Person;

int main() {
    FILE *filePointer;
    Person personList[3];

    // write to file
    filePointer = fopen("people.txt", "w");
    if (filePointer == NULL) {
        printf("Error: unable to open file for writing.\n");
        exit(1);
    }
    for (int i = 0; i < 3; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", personList[i].name);
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &personList[i].age);
        printf("Enter email for person %d: ", i + 1);
        scanf("%s", personList[i].email);
        fprintf(filePointer, "Name: %s\nAge: %d\nEmail: %s\n\n", personList[i].name, personList[i].age, personList[i].email);
    }
    fclose(filePointer);

    // read from file
    filePointer = fopen("people.txt", "r");
    if (filePointer == NULL) {
        printf("Error: unable to open file for reading.\n");
        exit(1);
    }
    printf("Contents of file:\n");
    char c = fgetc(filePointer);
    while (c != EOF) {
        printf("%c", c);
        c = fgetc(filePointer);
    }
    fclose(filePointer);

    return 0;
}
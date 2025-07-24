//FormAI DATASET v1.0 Category: Data validation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int age;
} Person;

void validatePersonData(char *name, char *age, void (*callback)(int valid, Person person)) {
    int valid = 1;
    Person person;
    if (atoi(age) < 0) {
        valid = 0;
    } else {
        person.age = atoi(age);
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            valid = 0;
            break;
        }
    }
    if (valid) {
        strcpy(person.name, name);
    }
    callback(valid, person);
}

void onDataValidated(int valid, Person person) {
    if (valid) {
        printf("The following person's data is valid:\nName: %s\nAge: %d\n", person.name, person.age);
    } else {
        printf("Invalid data entered\n");
    }
}

int main() {
    char name[30], age[10];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%s", age);

    validatePersonData(name, age, onDataValidated);

    return 0;
}
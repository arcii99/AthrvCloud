//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structs to represent a person and their car
typedef struct {
    char name[50];
    int age;
    char gender[10];
} Person;

typedef struct {
    char make[20];
    char model[20];
    int year;
    int owner_age;
} Car;

int main() {
    // create arrays to hold people and cars
    Person people[5];
    Car cars[5];

    // populate the arrays with data
    strcpy(people[0].name, "John Doe");
    people[0].age = 25;
    strcpy(people[0].gender, "male");

    strcpy(people[1].name, "Jane Smith");
    people[1].age = 40;
    strcpy(people[1].gender, "female");

    strcpy(people[2].name, "Bob Johnson");
    people[2].age = 30;
    strcpy(people[2].gender, "male");

    strcpy(people[3].name, "Jasmine Lee");
    people[3].age = 35;
    strcpy(people[3].gender, "female");

    strcpy(people[4].name, "Tom Wilson");
    people[4].age = 45;
    strcpy(people[4].gender, "male");

    strcpy(cars[0].make, "Toyota");
    strcpy(cars[0].model, "Corolla");
    cars[0].year = 2018;
    cars[0].owner_age = 25;

    strcpy(cars[1].make, "Honda");
    strcpy(cars[1].model, "Civic");
    cars[1].year = 2015;
    cars[1].owner_age = 40;

    strcpy(cars[2].make, "Ford");
    strcpy(cars[2].model, "Fiesta");
    cars[2].year = 2017;
    cars[2].owner_age = 30;

    strcpy(cars[3].make, "Nissan");
    strcpy(cars[3].model, "Altima");
    cars[3].year = 2016;
    cars[3].owner_age = 35;

    strcpy(cars[4].make, "Chevrolet");
    strcpy(cars[4].model, "Cruze");
    cars[4].year = 2019;
    cars[4].owner_age = 45;

    // display all people and their cars
    printf("All people and their cars:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s (%s, %d years old) owns a %d %s %s.\n", people[i].name, people[i].gender, people[i].age, cars[i].year, cars[i].make, cars[i].model);
    }

    // find all people who own a car that is at least 4 years old
    printf("\nPeople who own a car that is at least 4 years old:\n");
    for (int i = 0; i < 5; i++) {
        if (2021 - cars[i].year >= 4) {
            printf("%s (%s, %d years old) owns a %d %s %s.\n", people[i].name, people[i].gender, people[i].age, cars[i].year, cars[i].make, cars[i].model);
        }
    }

    // find the youngest person who owns a car
    int min_age = 100;
    char youngest_person[50];
    for (int i = 0; i < 5; i++) {
        if (people[i].age < min_age) {
            min_age = people[i].age;
            strcpy(youngest_person, people[i].name);
        }
    }
    printf("\nThe youngest person who owns a car is %s (%d years old).\n", youngest_person, min_age);

    // find the most common car make among all owners
    int toyota_count = 0;
    int honda_count = 0;
    int ford_count = 0;
    int nissan_count = 0;
    int chevrolet_count = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(cars[i].make, "Toyota") == 0) {
            toyota_count++;
        } else if (strcmp(cars[i].make, "Honda") == 0) {
            honda_count++;
        } else if (strcmp(cars[i].make, "Ford") == 0) {
            ford_count++;
        } else if (strcmp(cars[i].make, "Nissan") == 0) {
            nissan_count++;
        } else if (strcmp(cars[i].make, "Chevrolet") == 0) {
            chevrolet_count++;
        }
    }
    char most_common_make[20];
    int max_count = 0;
    if (toyota_count > max_count) {
        max_count = toyota_count;
        strcpy(most_common_make, "Toyota");
    }
    if (honda_count > max_count) {
        max_count = honda_count;
        strcpy(most_common_make, "Honda");
    }
    if (ford_count > max_count) {
        max_count = ford_count;
        strcpy(most_common_make, "Ford");
    }
    if (nissan_count > max_count) {
        max_count = nissan_count;
        strcpy(most_common_make, "Nissan");
    }
    if (chevrolet_count > max_count) {
        max_count = chevrolet_count;
        strcpy(most_common_make, "Chevrolet");
    }
    printf("\nThe most common car make among all owners is %s.\n", most_common_make);

    return 0;
}
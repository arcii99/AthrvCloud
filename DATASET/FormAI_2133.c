//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[20];
    int age;
    int height;
    int weight;
    float bmi;
} Person;

void calculate_bmi(Person *p) {
    p->bmi = (float)p->weight / ((float)p->height / 100 * (float)p->height / 100);
}

void print_person(Person *p) {
    printf("Name: %s\nAge: %d\nHeight(cm): %d\nWeight(kg): %d\nBMI: %.2f\n\n", p->name, p->age, p->height, p->weight, p->bmi);
}

int main() {
    Person p;

    printf("Welcome to the Medieval Fitness Tracker!\n\n");
    printf("Enter your name: ");
    scanf("%s", p.name);
    printf("Enter your age: ");
    scanf("%d", &p.age);
    printf("Enter your height in cm: ");
    scanf("%d", &p.height);
    printf("Enter your weight in kg: ");
    scanf("%d", &p.weight);

    calculate_bmi(&p);
    print_person(&p);

    return 0;
}
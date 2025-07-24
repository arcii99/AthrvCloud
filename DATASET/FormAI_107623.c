//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include<stdio.h>
#include<string.h>

struct fitness {
    char name[20];
    int age;
    float height;
    float weight;
    float bmi;
};

void getFitnessData(struct fitness *fit) {
    printf("Enter your name: ");
    scanf("%s", fit->name);
    printf("Enter your age: ");
    scanf("%d", &fit->age);
    printf("Enter your height(in m): ");
    scanf("%f", &fit->height);
    printf("Enter your weight(in kg): ");
    scanf("%f", &fit->weight);
    fit->bmi = fit->weight/(fit->height*fit->height);
}

void printFitnessData(struct fitness fit) {
    printf("\nName: %s\n", fit.name);
    printf("Age: %d\n", fit.age);
    printf("Height: %.2f m\n", fit.height);
    printf("Weight: %.2f kg\n", fit.weight);
    printf("BMI: %.2f kg/m^2\n", fit.bmi);
    if(fit.bmi < 18.5) {
        printf("You are underweight.\n");
    } else if(fit.bmi < 25) {
        printf("You are normal.\n");
    } else if(fit.bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }
}

int main() {
    struct fitness fit;
    getFitnessData(&fit);
    printFitnessData(fit);
    return 0;
}
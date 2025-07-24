//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FitnessTracker{
    char name[30];
    int age;
    float height;
    float weight;
    float bmi;
    float dailyCalorieIntake;
};

void calculateBmi(struct FitnessTracker *ft){
    ft->bmi = ft->weight / ((ft->height / 100) * (ft->height / 100));
}

void calculateDailyCalorieIntake(struct FitnessTracker *ft){
    if(ft->bmi < 18.5){
        ft->dailyCalorieIntake = 30 * ft->weight;
    }
    else if(ft->bmi > 25){
        ft->dailyCalorieIntake = 25 * ft->weight;
    }
    else{
        ft->dailyCalorieIntake = 20 * ft->weight;
    }
}

void printFitnessTracker(struct FitnessTracker *ft){
    printf("\nName : %s", ft->name);
    printf("\nAge : %d", ft->age);
    printf("\nHeight : %.2f cm", ft->height);
    printf("\nWeight : %.2f kg", ft->weight);
    printf("\nBMI : %.2f", ft->bmi);
    printf("\nDaily calorie intake : %.2f", ft->dailyCalorieIntake);
}

int main(){
    struct FitnessTracker ft1;
    strcpy(ft1.name, "Steve");
    ft1.age = 35;
    ft1.height = 180;
    ft1.weight = 80;
    calculateBmi(&ft1);
    calculateDailyCalorieIntake(&ft1);
    printFitnessTracker(&ft1);

    struct FitnessTracker ft2;
    strcpy(ft2.name, "Amy");
    ft2.age = 27;
    ft2.height = 165;
    ft2.weight = 55;
    calculateBmi(&ft2);
    calculateDailyCalorieIntake(&ft2);
    printFitnessTracker(&ft2);

    return 0;
}
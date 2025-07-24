//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

typedef struct fitnessTracker{
    float weight;
    int age;
    int height;
    char gender[10];
} FitnessTracker;

int caloriesBurned(float weight, int age, int height, char gender[10], int duration, bool exercise){
    int cals_burned;
    float BMR;
    if(strcmp(gender, "male") == 0){
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    }
    else if(strcmp(gender, "female") == 0){
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }
    else{
        printf("Invalid input for gender.");
        return 0;
    }
    if(exercise){
        cals_burned = BMR * (duration / 1440) * 1.3;
        return cals_burned;
    }
    else{
        cals_burned = BMR * (duration / 1440);
        return cals_burned;
    }
}

int main(){
    FitnessTracker user1 = {60.0, 23, 175, "male"};
    int duration;
    bool exercise;
    printf("Enter the duration of your exercise session in minutes: ");
    scanf("%d", &duration);
    printf("Did you perform high intensity exercise? (Enter '1' for yes and '0' for no): ");
    scanf("%d", &exercise);
    int cals_burned = caloriesBurned(user1.weight, user1.age, user1.height, user1.gender, duration, exercise);
    printf("You burned %d calories in your exercise session.", cals_burned);
    return 0;
}
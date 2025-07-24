//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct FitnessTracker {
    int user_id;
    float weight;
    float height;
    float bmi;
};

void calculate_bmi(struct FitnessTracker *user) {
    user->bmi = user->weight / ((user->height / 100.0) * (user->height / 100.0));
}

void print_user(struct FitnessTracker user) {
    printf("User ID: %d\n", user.user_id);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f cm\n", user.height);
    printf("BMI: %.2f\n", user.bmi);
}

int main() {

    struct FitnessTracker user1, user2;
    printf("Enter user 1 ID: ");
    scanf("%d", &user1.user_id);
    printf("Enter user 1 weight (kg): ");
    scanf("%f", &user1.weight);
    printf("Enter user 1 height (cm): ");
    scanf("%f", &user1.height);

    printf("Enter user 2 ID: ");
    scanf("%d", &user2.user_id);
    printf("Enter user 2 weight (kg): ");
    scanf("%f", &user2.weight);
    printf("Enter user 2 height (cm): ");
    scanf("%f", &user2.height);

    calculate_bmi(&user1);
    calculate_bmi(&user2);

    printf("\nUser 1:\n");
    print_user(user1);
    printf("\nUser 2:\n");
    print_user(user2);

    return 0;
}
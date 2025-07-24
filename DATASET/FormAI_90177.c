//FormAI DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

/* This program calculates the total cost of ingredients for a cooking recipe. */

int main() {
    int num_of_ingredients;
    float cost_per_ingredient, total_cost = 0;
    char ingredient_name[20];
    
    printf("How many ingredients are in your recipe?\n");
    scanf("%d", &num_of_ingredients);
    printf("\n");
    
    for(int i=0; i<num_of_ingredients; i++) {
        printf("Enter the name of ingredient %d: ", i+1);
        scanf("%s", ingredient_name);
        printf("Enter the cost per %s: $", ingredient_name);
        scanf("%f", &cost_per_ingredient);
        total_cost += cost_per_ingredient;
        printf("\n");
    }
    
    printf("The total cost of all ingredients is: $%.2f\n", total_cost);
    
    return 0;
}
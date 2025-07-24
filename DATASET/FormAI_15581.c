//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include<stdio.h>

int main(){

    printf("Welcome to the Greedy Algorithm Example Program!\n\n");

    int n,egg,flour,sugar,cookingTime, maxCakes;
    int totalEgg=0, totalFlour=0, totalSugar=0, totalTime=0;
  
    printf("Enter the number of cakes you want to bake: ");
    scanf("%d",&maxCakes);

    for(n=0;n<maxCakes;n++){  
        printf("\nCake %d:\n", n+1 );

        printf("Enter the amount of eggs required: ");
        scanf("%d",&egg);
        totalEgg += egg;

        printf("Enter the amount of flour required (in grams): ");
        scanf("%d",&flour);
        totalFlour += flour;

        printf("Enter the amount of sugar required (in grams): ");
        scanf("%d",&sugar);
        totalSugar += sugar;

        printf("Enter the cooking time required (in minutes): ");
        scanf("%d",&cookingTime);
        totalTime += cookingTime;

    }

    printf("\nTotal ingredients required to make %d cakes:\n", maxCakes);
    printf("Eggs: %d\n", totalEgg);
    printf("Flour: %d grams\n", totalFlour);
    printf("Sugar: %d grams\n", totalSugar);
    printf("Total Cooking Time: %d minutes\n", totalTime);

    return 0;
}
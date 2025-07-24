//FormAI DATASET v1.0 Category: Data validation ; Style: funny
#include<stdio.h>

int main() {
    printf("Welcome to the Data Validation Program!\n");
    printf("Keep in mind this program can't validate your life choices... yet.\n");
    printf("Let's start with some basic validation, shall we?\n");
    printf("Please enter your age: ");
    int age;
    scanf("%d", &age);
    if(age < 0) {
        printf("Error: Invalid age. Please enter a valid age next time.\n");
        return 1;
    } else if(age >= 120) {
        printf("Are you sure you're that old? That's impressive!\n");
        char response[10];
        printf("Type \"yes\" to confirm or \"no\" to double-check: ");
        scanf("%s", response);
        if(strcmp(response, "yes") != 0) {
            printf("Okay, let's start over.\n");
            return 1;
        }
    }
    
    printf("Next, please enter your shoe size: ");
    int shoe_size;
    scanf("%d", &shoe_size);
    if(shoe_size < 0 || shoe_size > 20) {
        printf("Sorry, we only accept shoe sizes between 0 and 20. Please try again.\n");
        return 1;
    }

    printf("Great, now can you enter your weight in pounds: ");
    int weight;
    scanf("%d", &weight);
    if(weight < 50) {
        printf("Are you sure you're not a hobbit? You weigh too little for a human!\n");
        printf("Please try again with a different weight.\n");
        return 1;
    } else if(weight > 1000) {
        printf("I'm sorry, we can't process that weight. That's either a typo or you're a giant!\n");
        return 1;
    }
 
    printf("Thank you for entering your information. Everything looks good!\n");
    printf("Other than the fact that you're being validated by a computer... That's a bit sad, don't you think?\n"); 
    return 0;
}
//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    printf("Welcome to our surrealistic date converter program!\n");
    printf("Enter the date you want to convert in natural language: ");
    fgets(input, 100, stdin);
    printf("\n");

    char month[15];
    int day, year;
    sscanf(input, "%d %s %d", &day, month, &year);

    if (strcmp(month, "Surreal")==0){
        printf("Error: Cannot convert surrealistic date.\n");
    }
    else if (strcmp(month, "January")==0){
        printf("You have entered an ordinary date with no surrealistic elements.\n");
        printf("%s %d, %d\n", month, day, year);
    }
    else if (strcmp(month, "Metamorphosis")==0){
        printf("We have detected surrealistic elements in your date!\n");
        printf("Welcome to the world of magical numbers and strange transformations!\n");
        printf("Your converted date is: ");
        printf("%d %s %d\n", year, month, day);
    }
    else if (strcmp(month, "Dream")==0){
        printf("Sweet dreams ahead!\n");
        printf("Your converted date is: ");
        printf("%s %d, %d\n", month, day, year);
    }
    else if (strcmp(month, "Galaxy")==0){
        printf("Your date is truly out of this world!\n");
        printf("Your converted date is: ");
        printf("%d-%s-%d\n", day, month, year);
    }
    else if (strcmp(month, "Absurdity")==0){
        printf("Things are about to get weird...\n");
        printf("Your converted date is: ");
        printf("%s %dth, %d\n", month, day, year);
    }
    else{
        printf("We are sorry, but we could not understand your input.");
    }

    return 0;
}
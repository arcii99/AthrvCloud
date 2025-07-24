//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
#include<stdio.h>

int main()
{
    char name[20];
    int age;
    double height;
    char language[10];

    /* Taking inputs from user */
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nEnter your age: ");
    scanf("%d", &age);
    printf("\nEnter your height: ");
    scanf("%lf", &height);
    printf("\nEnter your preferred programming language: ");
    scanf("%s", language);

    /* Validating inputs */
    if(age <= 0 || age > 120)
    {
        printf("\nInvalid age! Please enter a valid age.\n");
        return 1;
    }

    if(height <= 0.0 || height >= 10.0)
    {
        printf("\nInvalid height! Please enter a valid height.\n");
        return 1;
    }

    if(strcmp(language, "C") != 0 && strcmp(language, "c") != 0)
    {
        printf("\nSorry, this program only supports C programming language.\n");
        return 1;
    }

    /* Output */
    printf("\nName: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2lf\n", height);
    printf("Preferred Programming Language: %s\n", language);

    return 0;
}
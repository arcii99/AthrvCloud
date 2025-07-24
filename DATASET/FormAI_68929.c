//FormAI DATASET v1.0 Category: Data validation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char name[50];
    int age;
    float height;
    printf("Please enter your name: ");
    fgets(name, 50, stdin);
    int i = 0;
    while (name[i] != '\n')
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            printf("Error: Invalid name - Only letters and spaces are allowed\n");
            return 1;
        }
        i++;
    }
    printf("Please enter your age: ");
    scanf("%d", &age);
    if (age < 0 || age > 120)
    {
        printf("Error: Invalid age - age should be between 0 and 120\n");
        return 1;
    }
    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    if (height < 0.5 || height > 2.5)
    {
        printf("Error: Invalid height - height should be between 0.5 and 2.5 meters\n");
        return 1;
    }
    printf("Name: %sAge: %d\n", name, age);
    printf("Height: %.2f meters\n", height);
    return 0;
}
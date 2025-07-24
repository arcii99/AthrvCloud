//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include<stdio.h>

void main()
{
    int choice;
    printf("Welcome to Retro Image Classification System\n\n");
    printf("Please choose an option:\n");
    printf("1. Classify animal images\n");
    printf("2. Classify object images\n");
    printf("3. Classify scenery images\n");
    scanf("%d",&choice);
    switch(choice)
    {   
        case 1:
            printf("\nYou have selected to classify animal images!\n\n");
            animal();
            break;

        case 2:
            printf("\nYou have selected to classify object images!\n\n");
            object();
            break;

        case 3:
            printf("\nYou have selected to classify scenery images!\n\n");
            scenery();
            break;

        default:
            printf("\nInvalid choice!\n\n");
            break;
    }
}

void animal()
{
    char animal_names[4][20]={"Tiger","Lion","Elephant","Giraffe"};
    int i, index;
    printf("Enter the index of the animal you want to classify:\n");
    for(i=0;i<4;i++)
        printf("%d. %s\n",i+1,animal_names[i]);
    scanf("%d",&index);
    printf("\nThe %s image is classified as a wildlife image!\n\n",animal_names[index-1]);
}

void object()
{
    char object_names[4][20]={"Car","Bicycle","Train","Motorcycle"};
    int i, index;
    printf("Enter the index of the object you want to classify:\n");
    for(i=0;i<4;i++)
        printf("%d. %s\n",i+1,object_names[i]);
    scanf("%d",&index);
    printf("\nThe %s image is classified as a transportation image!\n\n",object_names[index-1]);
}

void scenery()
{
    char scenery_names[4][20]={"Beach","Mountains","City","Desert"};
    int i, index;
    printf("Enter the index of the scenery you want to classify:\n");
    for(i=0;i<4;i++)
        printf("%d. %s\n",i+1,scenery_names[i]);
    scanf("%d",&index);
    printf("\nThe %s image is classified as a nature image!\n\n",scenery_names[index-1]);
}
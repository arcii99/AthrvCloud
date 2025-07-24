//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
//Imagine a world where fruits are sorted with the help of C code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fruit {
    char name[20];
    char color[10];
    int weight;
};

typedef struct Fruit Fruit;

//Function to Swap two Fruits
void swapFruits(Fruit* f1, Fruit* f2) 
{ 
    Fruit temp = *f1; 
    *f1 = *f2; 
    *f2 = temp; 
} 

//Function to Sort Fruits based on weight using Selection Sort Algorithm
void sortFruits(Fruit* fruits, int n)
{
    int i, j, min_index; 
  
    for (i = 0; i < n-1; i++) 
    { 
        min_index = i; 
        for (j = i+1; j < n; j++) 
            if (fruits[j].weight < fruits[min_index].weight) 
                min_index = j; 
  
        swapFruits(&fruits[min_index], &fruits[i]); 
    } 
}

int main() {

    Fruit fruits[6];

    //Fill in Fruits Details
    strcpy(fruits[0].name, "Apple");
    strcpy(fruits[0].color, "Red");
    fruits[0].weight = 50;

    strcpy(fruits[1].name, "Banana");
    strcpy(fruits[1].color, "Yellow");
    fruits[1].weight = 30;

    strcpy(fruits[2].name, "Grapes");
    strcpy(fruits[2].color, "Green");
    fruits[2].weight = 20;

    strcpy(fruits[3].name, "Mango");
    strcpy(fruits[3].color, "Yellow");
    fruits[3].weight = 70;

    strcpy(fruits[4].name, "Pineapple");
    strcpy(fruits[4].color, "Brown");
    fruits[4].weight = 40;

    strcpy(fruits[5].name, "Watermelon");
    strcpy(fruits[5].color, "Dark Green");
    fruits[5].weight = 90;

    int nFruits = sizeof(fruits) / sizeof(fruits[0]);

    //Print the Fruits Before Sorting
    printf("Fruits Before Sorting:\n");
    for(int i=0; i<nFruits; i++) {
        printf("\nName: %s", fruits[i].name);
        printf("\nColor: %s", fruits[i].color);
        printf("\nWeight: %d", fruits[i].weight);
        printf("\n");
    }

    //Sort Fruits based on Weight
    sortFruits(fruits, nFruits);

    //Print the Fruits After Sorting
    printf("\n\nFruits After Sorting based on Weight:\n");
    for(int i=0; i<nFruits; i++) {
        printf("\nName: %s", fruits[i].name);
        printf("\nColor: %s", fruits[i].color);
        printf("\nWeight: %d", fruits[i].weight);
        printf("\n");
    }

    return 0;
}
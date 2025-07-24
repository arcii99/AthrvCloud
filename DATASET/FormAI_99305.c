//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    char gender[10];
} Knight;

void findOldestKnight(Knight knights[], int numKnights) {
    int maxAge = 0;
    int oldestKnightIndex = 0;
    for(int i = 0; i < numKnights; i++) {
        if(knights[i].age > maxAge) {
            maxAge = knights[i].age;
            oldestKnightIndex = i;
        }
    }
    printf("%s is the oldest knight at %d years old.\n", knights[oldestKnightIndex].name, knights[oldestKnightIndex].age);
}

int main() {
    int numKnights;
    printf("Enter the number of knights: ");
    scanf("%d", &numKnights);

    Knight knights[numKnights];
    for(int i = 0; i < numKnights; i++) {
        printf("Enter the name of knight %d: ", i+1);
        scanf("%s", knights[i].name);
        printf("Enter the age of knight %d: ", i+1);
        scanf("%d", &knights[i].age);
        printf("Enter the gender of knight %d (male/female): ", i+1);
        scanf("%s", knights[i].gender);
        printf("\n");
    }

    findOldestKnight(knights, numKnights);

    return 0;
}
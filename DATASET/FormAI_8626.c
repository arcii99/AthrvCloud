//FormAI DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
// Romeo and Juliet C Sorting Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our struct
typedef struct {
    char name[20];
    int age;
} Person;

// Define our compare function (the one that decides if one person is greater than another)
// In our case, the person with the higher age is considered greater
int compare(const void* a, const void* b) {
    return ((Person*)b)->age - ((Person*)a)->age;
}

int main() {
    
    // Declare our two arrays of persons, Romeo and Juliet
    Person romeo[5], juliet[5];
    
    // Populate our arrays with some life
    strcpy(romeo[0].name, "Romeo");
    romeo[0].age = 18;
    strcpy(romeo[1].name, "Benvolio");
    romeo[1].age = 19;
    strcpy(romeo[2].name, "Mercutio");
    romeo[2].age = 20;
    strcpy(romeo[3].name, "Paris");
    romeo[3].age = 23;
    strcpy(romeo[4].name, "Tybalt");
    romeo[4].age = 22;
    
    strcpy(juliet[0].name, "Juliet");
    juliet[0].age = 16;
    strcpy(juliet[1].name, "Nurse");
    juliet[1].age = 40;
    strcpy(juliet[2].name, "Lady Capulet");
    juliet[2].age = 36;
    strcpy(juliet[3].name, "Capulet");
    juliet[3].age = 45;
    strcpy(juliet[4].name, "Prince");
    juliet[4].age = 50;
    
    // Let's sort our arrays using the qsort algorithm
    qsort(romeo, 5, sizeof(Person), compare);
    qsort(juliet, 5, sizeof(Person), compare);
    
    // Let's print out our sorted arrays
    printf("Romeo's Friends, sorted by age:\n");
    for(int i = 0; i < 5; i++) {
        printf("%s (%d)\n", romeo[i].name, romeo[i].age);
    }
    
    printf("\nJuliet's Family, sorted by age:\n");
    for(int i = 0; i < 5; i++) {
        printf("%s (%d)\n", juliet[i].name, juliet[i].age);
    }
    
    return 0;
}
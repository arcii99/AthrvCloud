//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>

/* Define a custom struct representing a car */
struct Car {
    char make[20];
    char model[20];
    int year;
};

/* Define a custom compare function for sorting cars by year */
int compare_cars(const void *a, const void *b) {
    struct Car car1 = *(struct Car *)a;
    struct Car car2 = *(struct Car *)b;
    return car1.year - car2.year;
}

int main() {
    int i;
    struct Car garage[5] = {{"Honda", "Civic", 2011}, {"Toyota", "Corolla", 2008}, {"Ford", "Mustang", 2018}, {"Chevy", "Camaro", 2015}, {"Tesla", "Model S", 2020}};

    /* Print the unsorted array of cars */
    printf("Unsorted Cars:\n");
    for (i = 0; i < 5; i++) {
        printf("%s %s (%d)\n", garage[i].make, garage[i].model, garage[i].year);
    }
    printf("\n");

    /* Sort the array of cars by year */
    qsort(garage, 5, sizeof(struct Car), compare_cars);

    /* Print the sorted array of cars */
    printf("Sorted Cars:\n");
    for (i = 0; i < 5; i++) {
        printf("%s %s (%d)\n", garage[i].make, garage[i].model, garage[i].year);
    }

    return 0;
}
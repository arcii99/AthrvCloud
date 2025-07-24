//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello! Let's start finding some treasures in data mining.\n");

    // Let's define our dataset as an array of numbers
    int dataset[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    // We will find the average of the dataset by summing the numbers and dividing by the number of elements
    int num_elements = sizeof(dataset) / sizeof(dataset[0]);
    int sum = 0;
    for (int i = 0; i < num_elements; i++) {
        sum += dataset[i];
    }
    float average = (float) sum / num_elements;
    printf("The average of the dataset is %f.\n", average);

    // Now let's find the maximum and minimum values in the dataset
    int max_val = dataset[0];
    int min_val = dataset[0];
    for (int i = 1; i < num_elements; i++) {
        if (dataset[i] > max_val) {
            max_val = dataset[i];
        }
        if (dataset[i] < min_val) {
            min_val = dataset[i];
        }
    }
    printf("The maximum value in the dataset is %d.\n", max_val);
    printf("The minimum value in the dataset is %d.\n", min_val);

    // Lastly, let's find if the number 5 exists in the dataset
    int found = 0;
    for (int i = 0; i < num_elements; i++) {
        if (dataset[i] == 5) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("The number 5 exists in the dataset!\n");
    } else {
        printf("The number 5 does not exist in the dataset.\n");
    }

    printf("Thanks for exploring this dataset with me!\n");
    return 0;
}
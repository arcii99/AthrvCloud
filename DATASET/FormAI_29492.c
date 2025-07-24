//FormAI DATASET v1.0 Category: Data mining ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare struct for storing data
struct Data {
    char category[20];
    int value;
};

int main() {
    // create an array of data instances
    struct Data data[5];
    // populate the array with sample data
    strcpy(data[0].category, "A");
    data[0].value = 10;
    strcpy(data[1].category, "B");
    data[1].value = 20;
    strcpy(data[2].category, "B");
    data[2].value = 15;
    strcpy(data[3].category, "A");
    data[3].value = 5;
    strcpy(data[4].category, "C");
    data[4].value = 25;

    // create an array for storing summaries of each category's data
    int summaries[3] = {0, 0, 0}; // 3 categories: A, B, C

    // iterate through the array of data and update the summaries accordingly
    for (int i = 0; i < 5; i++) {
        if (strcmp(data[i].category, "A") == 0) {
            summaries[0] += data[i].value;
        } else if (strcmp(data[i].category, "B") == 0) {
            summaries[1] += data[i].value;
        } else if (strcmp(data[i].category, "C") == 0) {
            summaries[2] += data[i].value;
        }
    }

    // print out the summaries for each category
    printf("Category A has a total value of %d\n", summaries[0]);
    printf("Category B has a total value of %d\n", summaries[1]);
    printf("Category C has a total value of %d\n", summaries[2]);

    return 0;
}
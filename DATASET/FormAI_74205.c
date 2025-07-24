//FormAI DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>

// Sample data struct
struct Data {
    int id;
    float sales;
    int age;
};

int main() {
    // Declare an array of data
    struct Data dataSet[] = {
        { 1, 234.5, 22 },
        { 2, 654.2, 35 },
        { 3, 452.6, 29 },
        { 4, 542.9, 41 },
        { 5, 325.1, 28 },
        { 6, 781.2, 38 }
    };

    // Calculate the average sales and age
    float avgSales = 0;
    float avgAge = 0;
    int dataSize = sizeof(dataSet)/sizeof(dataSet[0]);
    for (int i = 0; i < dataSize; i++) {
        avgSales += dataSet[i].sales;
        avgAge += dataSet[i].age;
    }
    avgSales = avgSales / dataSize;
    avgAge = avgAge / dataSize;

    // Identify the sales outliers
    printf("The sales outliers are: ");
    for (int i = 0; i < dataSize; i++) {
        if (dataSet[i].sales > avgSales * 1.5) {
            printf("%d ", dataSet[i].id);
        }
    }
    printf("\n");

    // Identify the age outliers
    printf("The age outliers are: ");
    for (int i = 0; i < dataSize; i++) {
        if (dataSet[i].age > avgAge * 1.5) {
            printf("%d ", dataSet[i].id);
        }
    }
    printf("\n");

    return 0;
}
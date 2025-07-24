//FormAI DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0, average = 0, max = data[0], min = data[0];
    int i;

    for(i=0;i<10;i++) {
        if(data[i] > max) {
            max = data[i];
        }
        if(data[i] < min) {
            min = data[i];
        }
        sum += data[i];
    }

    average = sum / 10;

    printf("Data set: ");
    for(i=0;i<10;i++) {
        printf("%d ", data[i]);
    }
    printf("\n\n");

    printf("Sum of the data set: %d\n", sum);
    printf("Average of the data set: %d\n", average);
    printf("Maximum value in the data set: %d\n", max);
    printf("Minimum value in the data set: %d\n", min);

    return 0;
}
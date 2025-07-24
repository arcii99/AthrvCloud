//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define THRESHOLD 7

typedef struct data {
    char name[10];
    int age;
    int height;
} Data;

void generate_data(Data arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int num = rand() % 3;
        if (num == 0) {
            sprintf(arr[i].name, "Alice");
        } else if (num == 1) {
            sprintf(arr[i].name, "Bob");
        } else if (num == 2) {
            sprintf(arr[i].name, "Charlie");
        }
        arr[i].age = rand() % 6 + 20;
        arr[i].height = rand() % 41 + 160;
    }
}

int main() {
    Data data[MAX_SIZE];
    generate_data(data, MAX_SIZE);

    int count = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (data[i].age > THRESHOLD && data[i].height > THRESHOLD) {
            printf("%s, %d years old, %dcm tall\n", data[i].name, data[i].age, data[i].height);
            count++;
        }
    }

    printf("%d people are above the threshold.\n", count);

    return 0;
}
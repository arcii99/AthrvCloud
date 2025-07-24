//FormAI DATASET v1.0 Category: Memory Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void shuffle(int *array, size_t size);
void printArray(int *array, size_t size);
int playGame(int *array, size_t size);

int main() {
    srand(time(NULL));
    int array[MAX];
    for (int i = 0; i < MAX; i++) {
        array[i] = i + 1;
    }
    shuffle(array, MAX);
    int score = playGame(array, MAX);
    printf("Your score is %d out of %d\n", score, MAX / 2);
    return 0;
}

void shuffle(int *array, size_t size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int playGame(int *array, size_t size) {
    int score = 0;
    int *seen = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        if (seen[i]) {
            continue;
        }
        printf("Enter the index of a card to flip (1-%zu): ", size);
        int index1, index2;
        scanf("%d", &index1);
        printf("Enter the index of another card to flip (1-%zu): ", size);
        scanf("%d", &index2);
        index1--;
        index2--;
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size || seen[index1] || seen[index2]) {
            printf("Invalid input\n");
            i--;
            continue;
        }
        printf("The value of card %d is %d\n", index1 + 1, array[index1]);
        printf("The value of card %d is %d\n", index2 + 1, array[index2]);
        if (array[index1] == array[index2]) {
            printf("MATCH!\n");
            seen[index1] = 1;
            seen[index2] = 1;
            score++;
        }
        printf("\n");
    }
    free(seen);
    return score;
}
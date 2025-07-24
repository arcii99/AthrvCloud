//FormAI DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a student
typedef struct {
    int id;
    char name[50];
    int score;
} Student;

// Function prototype for quicksort
void quicksort(Student list[], int left, int right);

// Function prototype for printing the sorted list
void printList(Student list[], int length);

int main() {
    int length = 5;
    Student list[length];

    // Initialize the list with random values
    for (int i = 0; i < length; i++) {
        list[i].id = i + 1;
        sprintf(list[i].name, "Student%d", i + 1);
        list[i].score = rand() % 101;
    }

    // Print the unsorted list
    printf("Unsorted List:\n");
    printList(list, length);

    // Sort the list using quicksort
    quicksort(list, 0, length - 1);

    // Print the sorted list
    printf("Sorted List:\n");
    printList(list, length);

    return 0;
}

void quicksort(Student list[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = list[(left + right) / 2].score;
    int i = left - 1;
    int j = right + 1;

    while (1) {
        do {
            i++;
        } while (list[i].score < pivot);

        do {
            j--;
        } while (list[j].score > pivot);

        if (i >= j) {
            break;
        }

        Student temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }

    quicksort(list, left, j);
    quicksort(list, j + 1, right);
}

void printList(Student list[], int length) {
    printf("ID\tName\tScore\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t%s\t%d\n", list[i].id, list[i].name, list[i].score);
    }
}
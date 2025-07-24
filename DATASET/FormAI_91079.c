//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void mergeSort(Person *arr, int l, int r);
void merge(Person *arr, int l, int m, int r);
void printArr(Person *arr, int n);
void swap(Person *a, Person *b);

int main() {
    printf("My dear, I have a list of People I want to sort for you.\n");
    printf("These are the names and ages of all the people I know:\n");

    // list of people to sort
    Person people[] = {
        {"John", 25},
        {"Emily", 32},
        {"James", 22},
        {"Olivia", 29},
        {"Lucas", 20},
        {"Avery", 26},
        {"Ethan", 30},
        {"Sophia", 27},
        {"Benjamin", 28},
        {"Emma", 24}
    };

    int n = sizeof(people) / sizeof(people[0]);

    printArr(people, n); // print unsorted list of people

    mergeSort(people, 0, n - 1); // sort people list

    printf("\n\nAfter I sorted them, this is the final list of people:\n");

    printArr(people, n); // print sorted list of people

    printf("\n\nMy love, I hope you like this sorted list of our friends.\n");

    return 0;
}

// Merge sort implementation
void mergeSort(Person *arr, int l, int r) {
    if (l < r) {
        int m = l + (r-l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void merge(Person *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Person L[n1], R[n2];

    for (i = 0; i < n1; i++){
        strcpy(L[i].name, arr[l + i].name);
        L[i].age = arr[l + i].age;
    }
        
    for (j = 0; j < n2; j++){
        strcpy(R[j].name, arr[m + 1 + j].name);
        R[j].age = arr[m + 1 + j].age;

    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].age <= R[j].age) {
            strcpy(arr[k].name, L[i].name);
            arr[k].age = L[i].age;
            i++;
        }
        else {
            strcpy(arr[k].name, R[j].name);
            arr[k].age = R[j].age;
            j++;
        }
        k++;
    }

    while (i < n1) {
        strcpy(arr[k].name, L[i].name);
        arr[k].age = L[i].age;
        i++;
        k++;
    }

    while (j < n2) {
        strcpy(arr[k].name, R[j].name);
        arr[k].age = R[j].age;
        j++;
        k++;
    }
}

// Swap two Person objects
void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

// Print a list of Person objects
void printArr(Person *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s, %d\n", arr[i].name, arr[i].age);
    }
}
//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NUMS 1000

/* function prototypes */
bool is_sorted(int arr[], int size);
void print_array(int arr[], int size);
void merge(int arr[], int p, int q, int r);
void merge_sort(int arr[], int p, int r);
void sort_worker(int arr[], int p, int r);

int main()
{
    printf("Welcome to the Asynchronous Merge Sort program!\n");

    int nums[MAX_NUMS];
    srand(time(NULL));

    /* randomly generate array of ints */
    printf("Generating array of random integers...\n");
    for (int i = 0; i < MAX_NUMS; i++) {
        nums[i] = rand() % MAX_NUMS;
    }

    printf("Printing initial array...\n");
    print_array(nums, MAX_NUMS);

    pid_t child_pid = fork();

    /* child process: sorts first half of array */
    if (child_pid == 0) {
        printf("Child process: Sorting first half of array...\n");
        sort_worker(nums, 0, MAX_NUMS / 2);
        exit(0);
    }
    /* parent process: sorts second half of array */
    else {
        printf("Parent process: Sorting second half of array...\n");
        sort_worker(nums, MAX_NUMS/2 + 1, MAX_NUMS - 1);
        /* wait for child process to finish */
        wait(NULL);
    }

    /* merge sorted halves of array */
    printf("Merging sorted halves of array...\n");
    merge(nums, 0, MAX_NUMS/2, MAX_NUMS - 1);

    /* print final sorted array */
    printf("Printing final sorted array...\n");
    print_array(nums, MAX_NUMS);

    return 0;
}

/* worker function for merge-sorting a part of the array */
void sort_worker(int arr[], int p, int r)
{
    /* base case */
    if (p < r) {
        merge_sort(arr, p, r);
    }
}

/* merge the two sorted halves of the array */
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    /* copy data to temporary arrays */
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* copy remaining elements of L[] */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* copy remaining elements of R[] */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* merge-sort the array */
void merge_sort(int arr[], int p, int r)
{
    if (p < r) {
        int q = (p + r) / 2;
        pid_t child_pid = fork();

        /* child process: sorts first half of array */
        if (child_pid == 0) {
            sort_worker(arr, p, q);
            exit(0);
        }
        /* parent process: sorts second half of array */
        else {
            sort_worker(arr, q + 1, r);
            /* wait for child process to finish */
            wait(NULL);
        }

        merge(arr, p, q, r);
    }
}

/* check if array is sorted */
bool is_sorted(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

/* print array */
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//FormAI DATASET v1.0 Category: Funny ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

void print_array(int arr[], int n);
void shuffle_array(int arr[], int n);
void sort_array(int arr[], int n);
void guess_number(int arr[], int n);

int main()
{
    int arr[MAX_NUM];
    int n = MAX_NUM;

    // Initialize array with numbers 1 to MAX_NUM
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    // Shuffle array randomly
    shuffle_array(arr, n);

    // Sort array in ascending order
    sort_array(arr, n);

    // Print sorted array
    printf("Sorted Array: ");
    print_array(arr, n);

    // Guess a number in the array
    guess_number(arr, n);

    return 0;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shuffle_array(int arr[], int n)
{
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void sort_array(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void guess_number(int arr[], int n)
{
    int number;
    printf("Guess a number between 1 and %d: ", n);
    scanf("%d", &number);
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == number)
        {
            printf("Congratulations! You guessed the number.\n");
            return;
        }
        else if (arr[mid] < number)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("Sorry, the number was not in the array.\n");
}
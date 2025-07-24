//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 100

// function declarations
void read_file(FILE *fp, int *arr, int n);
void print_to_file(FILE *fp, int *arr, int n);
void calculate_squares(int *arr, int n);
void calculate_kth_root(int *arr, int n, int k);

int main()
{
    FILE *fp;
    int arr[MAX_LENGTH], n, k;

    // open the file for reading
    if ((fp = fopen("data.txt", "r")) == NULL)
    {
        printf("Failed to open the file.\n");
        exit(1);
    }

    // read the file and store data in the array
    fscanf(fp, "%d", &n);
    read_file(fp, arr, n);

    // close the file
    fclose(fp);

    // calculate the squares of the numbers in the array
    calculate_squares(arr, n);

    // open the file for writing
    if ((fp = fopen("output.txt", "w")) == NULL)
    {
        printf("Failed to open the file.\n");
        exit(1);
    }

    // print the squared numbers to the file
    print_to_file(fp, arr, n);

    // close the file
    fclose(fp);

    // ask the user for the value of k
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // calculate the k-th root of the numbers in the array
    calculate_kth_root(arr, n, k);

    // open the file for writing
    if ((fp = fopen("output.txt", "w")) == NULL)
    {
        printf("Failed to open the file.\n");
        exit(1);
    }

    // print the k-th root numbers to the file
    print_to_file(fp, arr, n);

    // close the file
    fclose(fp);

    return 0;
}

// read the file and store data in the array
void read_file(FILE *fp, int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
}

// print the array to the file
void print_to_file(FILE *fp, int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }

    fprintf(fp, "\n");
}

// calculate the squares of the numbers in the array
void calculate_squares(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        arr[i] = pow(arr[i], 2);
    }
}

// calculate the k-th root of the numbers in the array
void calculate_kth_root(int *arr, int n, int k)
{
    int i;

    for (i = 0; i < n; i++)
    {
        arr[i] = pow(arr[i], 1.0 / k);
    }
}
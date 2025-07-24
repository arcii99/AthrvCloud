//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n);
void swap(int* a, int* b);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
	printf("C Sorting Example Program\n\n");

	// Seed random number generator
	srand(time(NULL));

	// Generate random array of 10 integers
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100;

	// Display unsorted array
	printf("Unsorted Array:\n");
	printArray(arr, 10);

	// Sort the array using different algorithms
	bubbleSort(arr, 10);
	printf("\nBubble Sort:\n");
	printArray(arr, 10);

	selectionSort(arr, 10);
	printf("\nSelection Sort:\n");
	printArray(arr, 10);

	insertionSort(arr, 10);
	printf("\nInsertion Sort:\n");
	printArray(arr, 10);

	mergeSort(arr, 0, 9);
	printf("\nMerge Sort:\n");
	printArray(arr, 10);

	quickSort(arr, 0, 9);
	printf("\nQuick Sort:\n");
	printArray(arr, 10);

	return 0;
}

// Function to print an array
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Function to swap two integers
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Bubble sort algorithm
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

// Selection sort algorithm
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		swap(&arr[i], &arr[minIndex]);
	}
}

// Insertion sort algorithm
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j-1]) {
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}

// Merge sort algorithm
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

// Function to merge two sorted arrays
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
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
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Quick sort algorithm
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Function to partition the array for quick sort
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}
//FormAI DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a struct for the data structure
typedef struct {
  int values[MAX_SIZE]; // Array to hold values
  int count; // Number of values in the array
} DataSet;


// Define a helper function to print the dataset
void printDataSet(DataSet* data) {
  printf("{");
  for (int i = 0; i < data->count; i++) {
    printf("%d", data->values[i]);
    if (i != data->count - 1) {
      printf(", ");
    }
  }
  printf("}\n");
}

// Define a function to add a value to the dataset
void addValue(DataSet* data, int value) {
  // Check if there is space in the array
  if (data->count < MAX_SIZE) {
    // Add the value to the end of the array
    data->values[data->count] = value;
    data->count++;
  } else {
    // Otherwise, print an error message and exit the program
    printf("Error: dataset is full!\n");
    exit(1);
  }
}

// Define a function to calculate the mean of the dataset
float calculateMean(DataSet* data) {
  int sum = 0;
  // Loop through the array and add up all values
  for (int i = 0; i < data->count; i++) {
    sum += data->values[i];
  }

  // Calculate and return the mean
  return (float) sum / data->count;
}

// Define a function to calculate the median of the dataset
float calculateMedian(DataSet* data) {
  int mid = data->count / 2;
  // Check if the dataset has an even or odd number of values
  if (data->count % 2 == 0) {
    // If there are an even number of values, return the average of the two middle values
    return (float) (data->values[mid] + data->values[mid-1]) / 2;
  } else {
    // If there are an odd number of values, return the middle value
    return data->values[mid];
  }
}

int main() {
  // Create a dataset and initialize it with some values
  DataSet data = {{1, 2, 3, 4, 5}, 5};

  // Add some more values to the dataset
  addValue(&data, 6);
  addValue(&data, 7);

  // Print the dataset
  printf("Dataset: ");
  printDataSet(&data);

  // Calculate the mean and median of the dataset
  float mean = calculateMean(&data);
  float median = calculateMedian(&data);

  // Print the mean and median
  printf("Mean: %.2f\n", mean);
  printf("Median: %.2f\n", median);

  return 0;
}
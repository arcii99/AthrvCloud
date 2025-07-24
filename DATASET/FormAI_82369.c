//FormAI DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_DATA_POINTS 1000

// Struct to represent a data point 
typedef struct {
  int id; 
  double value; 
} DataPoint; 

// Function to read data from a file and store in an array of DataPoint structs 
int readData(char* filename, DataPoint* dataPoints) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return -1;
  }

  int i = 0; 
  char line[MAX_STRING_LENGTH]; 
  while (fgets(line, MAX_STRING_LENGTH, file)) {
    char* id_str = strtok(line, ",");
    char* value_str = strtok(NULL, ",");

    if (id_str == NULL || value_str == NULL) {
      continue;
    }

    int id = atoi(id_str);
    double value = atof(value_str);

    DataPoint dataPoint = {id, value};
    dataPoints[i] = dataPoint;
    ++i;
  }

  fclose(file);
  return i;
}

// Function to find the maximum data point value 
double findMax(DataPoint* dataPoints, int numDataPoints) {
  double max = dataPoints[0].value;
  for (int i = 1; i < numDataPoints; ++i) {
    if (dataPoints[i].value > max) {
      max = dataPoints[i].value;
    }
  }
  return max;
}

int main() {

  // Read data from file 
  DataPoint dataPoints[MAX_DATA_POINTS];
  int numDataPoints = readData("data.csv", dataPoints);
  if (numDataPoints == -1) {
    printf("Error reading data file\n");
    return 1;
  }

  // Find max value 
  double max = findMax(dataPoints, numDataPoints);
  printf("Maximum value: %lf\n", max);

  return 0;
}
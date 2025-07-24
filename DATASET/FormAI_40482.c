//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>

#define MAX_TEMPERATURES 30

float temperatures[MAX_TEMPERATURES];
int numTemperatures = 0;

float getAverageTemperature();
float getHighestTemperature();
float getLowestTemperature();
void printTemperatures();

int main() {
  printf("***C Temperature Monitor***\n\n");

  while (numTemperatures < MAX_TEMPERATURES) {
    printf("Enter temperature (q to quit): ");
    char line[10];
    fgets(line, sizeof(line), stdin);

    if (line[0] == 'q') {
      break;
    }

    float temperature = atof(line);

    temperatures[numTemperatures] = temperature;
    numTemperatures++;
  }

  printf("\n%d temperatures were entered.\n", numTemperatures);

  float averageTemperature = getAverageTemperature();
  float highestTemperature = getHighestTemperature();
  float lowestTemperature = getLowestTemperature();

  printf("\nAverage temperature: %.2f\n", averageTemperature);
  printf("Highest temperature: %.2f\n", highestTemperature);
  printf("Lowest temperature: %.2f\n", lowestTemperature);

  printf("\nTemperature log:\n");
  printTemperatures();

  return 0;
}

float getAverageTemperature() {
  float sum = 0;

  for (int i = 0; i < numTemperatures; i++) {
    sum += temperatures[i];
  }

  return sum / numTemperatures;
}

float getHighestTemperature() {
  float highest = temperatures[0];

  for (int i = 1; i < numTemperatures; i++) {
    if (temperatures[i] > highest) {
      highest = temperatures[i];
    }
  }

  return highest;
}

float getLowestTemperature() {
  float lowest = temperatures[0];

  for (int i = 1; i < numTemperatures; i++) {
    if (temperatures[i] < lowest) {
      lowest = temperatures[i];
    }
  }

  return lowest;
}

void printTemperatures() {
  for (int i = 0; i < numTemperatures; i++) {
    printf("%.2f\n", temperatures[i]);
  }
}
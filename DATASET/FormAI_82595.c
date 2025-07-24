//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define QoS categories
#define CRITICAL 0
#define HIGH 1
#define MEDIUM 2
#define LOW 3

// Define QoS values
#define CRITICAL_VALUE 90
#define HIGH_VALUE 80
#define MEDIUM_VALUE 70
#define LOW_VALUE 60

// Define data structure for network QoS data
typedef struct {
  int critical;
  int high;
  int medium;
  int low;
} qos_data_t;

// Define function to generate random QoS data
qos_data_t generate_qos_data() {
  qos_data_t qos_data;
  qos_data.critical = rand() % 101;
  qos_data.high = rand() % 101;
  qos_data.medium = rand() % 101;
  qos_data.low = rand() % 101;
  return qos_data;
}

int main(int argc, char *argv[]) {
  // Initialize seed for random number generation
  srand(time(NULL));

  // Initialize QoS data
  qos_data_t qos_data = generate_qos_data();

  // Display QoS data
  printf("Critical: %d\n", qos_data.critical);
  printf("High: %d\n", qos_data.high);
  printf("Medium: %d\n", qos_data.medium);
  printf("Low: %d\n", qos_data.low);

  // Evaluate QoS categories
  if (qos_data.critical >= CRITICAL_VALUE) {
    printf("QoS category: CRITICAL\n");
  } else if (qos_data.high >= HIGH_VALUE) {
    printf("QoS category: HIGH\n");
  } else if (qos_data.medium >= MEDIUM_VALUE) {
    printf("QoS category: MEDIUM\n");
  } else if (qos_data.low >= LOW_VALUE) {
    printf("QoS category: LOW\n");
  } else {
    printf("QoS category: NONE\n");
  }

  return 0;
}
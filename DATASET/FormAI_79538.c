//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

int main() {
  bool is_intrusion_detected = false;
  int previous_count = 0;
  int current_count;

  while(!is_intrusion_detected) {
    printf("Enter the number of requests: ");
    scanf("%d", &current_count);

    if(current_count > previous_count*2) {
      printf("Intrusion Detected!\n");
      is_intrusion_detected = true;
    }

    previous_count = current_count;
  }

  return 0;
}
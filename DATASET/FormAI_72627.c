//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

int main() {
  int n, i, j;
  float v[100], w[100], r[100], max_weight, total_value = 0;

  printf("How many items do you have?\n");
  scanf("%d", &n);

  printf("What's the maximum weight you can carry?\n");
  scanf("%f", &max_weight);

  for(i=0; i<n; i++) {
    printf("Enter the weight and value for item %d:\n", i+1);
    scanf("%f %f", &w[i], &v[i]);
    r[i] = v[i]/w[i];
  }

  for(i=0; i<n-1; i++) {
    for(j=i+1; j<n; j++) {
      if(r[i] < r[j]) {
        float temp = r[i];
        r[i] = r[j];
        r[j] = temp;

        temp = w[i];
        w[i] = w[j];
        w[j] = temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }

  for(i=0; i<n; i++) {
    if(w[i] > max_weight) {
      break;
    }
    total_value += v[i];
    max_weight -= w[i];
  }

  printf("Total weight taken: %.2f\nTotal value taken: $%.2f\n", max_weight, total_value);

  return 0;
}
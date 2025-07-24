//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include <stdio.h>

void recursiveDSP(int signal[], int n, int index, int result[]) {
   if (index == 0) {               // Base case
      result[index] = signal[index];
      return;
   }

   recursiveDSP(signal, n, index-1, result); // Recursive call

   result[index] = signal[index] + result[index-1]; // Recursive step
}

int main() {
   int signal[] = {1, 3, 6, 9, 12};
   int n = sizeof(signal) / sizeof(signal[0]);

   int result[n];
   recursiveDSP(signal, n, n-1, result);

   printf("Signal: ");
   for (int i = 0; i < n; i++)
      printf("%d ", signal[i]);

   printf("\n\nDigital Signal Processed Using Recursion: ");
   for (int i = 0; i < n; i++)
      printf("%d ", result[i]);

   return 0;
}
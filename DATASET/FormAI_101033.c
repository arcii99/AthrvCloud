//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include <stdio.h>

int main() {
  // Declare variables
  int data[1000], n, sum = 0, i, j, k;
  
  // Get input from user
  printf("Enter the number of data bytes (max 1000): ");
  scanf("%d", &n);
  
  printf("Enter the data bytes in hex format:\n");
  
  // Get data bytes from user
  for (i = 0; i < n; i++) {
    scanf("%X", &data[i]);
  }
  
  // Calculate checksum
  for (j = 0; j <= n / 2; j++) {
    if (n % 2 == 0 && j == (n / 2)) {
      break;
    }
    
    k = (j * 2);
    sum += (data[k] << 8) + data[k+1];
    
    if (sum & 0xffff0000) {
      sum = sum & 0xffff;
      sum++;
    }
  }
  
  // Print checksum
  printf("Checksum = %04X\n", ~(sum & 0xffff));
  
  return 0;
}
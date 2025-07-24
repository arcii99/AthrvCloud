//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: creative
#include <stdio.h>

int main() {
  int signalStrength;
  printf("Enter the signal strength from 1 - 5: ");
  scanf("%d", &signalStrength);

  switch(signalStrength){
    case 1:
      printf("Signal strength is very weak\n");
      break;
    case 2:
      printf("Signal strength is weak\n");
      break;
    case 3:
      printf("Signal strength is moderate\n");
      break;
    case 4:
      printf("Signal strength is strong\n");
      break;
    case 5:
      printf("Signal strength is very strong!\n");
      break;
    default:
      printf("Invalid option entered\n");
  }
  
  return 0;
}
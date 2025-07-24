//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>

//function to check if a number is prime or not
int isPrime(int num) {
  int i;
  for(i=2; i<=num/2; i++) {
    if(num % i == 0) {
      return 0; //not a prime number
    }
  }
  return 1; //prime number
}

int main() {
  int watermark = 314; //digital watermark
  int original_num, encoded_num, decoded_num, i;
  
  printf("Enter an integer to encode: ");
  scanf("%d", &original_num);
  
  //encode the given integer
  encoded_num = original_num + watermark;
  
  //check if encoded number is a prime number
  if(isPrime(encoded_num)) {
    printf("Encoded number is a prime number.\n");
  } else {
    printf("Encoded number is not a prime number.\n");
  }
  
  //decode the encoded number
  decoded_num = encoded_num - watermark;
  
  printf("Encoded Number: %d\n", encoded_num);
  printf("Decoded Number: %d\n", decoded_num);
  
  //check if decoded number is equal to the original number or not
  if(decoded_num == original_num) {
    printf("Decoded number is same as original number.\n");
  } else {
    printf("Decoded number is not same as original number.\n");
  }
  
  return 0;
}
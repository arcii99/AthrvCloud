//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
  //Once upon a time, in Verona city so fair,
  //Lived Romeo and Juliet, a love so rare.
  
  float principal, rate, payment;
  int term;
  
  printf("What is the principal amount, my love?: ");
  scanf("%f", &principal);
  // "Principal", Romeo smiled, and his heart skipped a beat,
  // As he looked into Juliet's eyes, so pure and so sweet.
  
  printf("What is the interest rate, my dear?: ");
  scanf("%f", &rate);
  // "Rate", Juliet whispered, her voice soft as a breeze,
  // As she gazed at Romeo, so handsome with ease.
  
  printf("What is the term of the loan, my love?: ");
  scanf("%d", &term);
  // "Term", Romeo said, and he held Juliet's hand,
  // As they dreamed of their future, together as planned.
  
  float r = rate/1200;
  float n = term*12;
  
  // Calculating the monthly payment, with care,
  // As Romeo and Juliet sat, side by side in the chair.
  
  payment = (principal * r) / (1 - pow(1 + r, -n));
  
  printf("The monthly mortgage payment, my dear, is: $%.2f\n", payment);
  // "Payment", Juliet exclaimed, a smile on her face,
  // As she thought of their home, in a warm, loving place.
  
  return 0;
  //"Thank you", Romeo whispered, as he kissed Juliet's hand,
  // As they walked off, into a life so grand.
}
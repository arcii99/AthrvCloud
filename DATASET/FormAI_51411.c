//FormAI DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
/* The Adventure of the Mysterious Calculation */

#include<stdio.h>

int main() {
  printf("It was a dark and stormy night when Sherlock Holmes received a call from the Scotland Yard.\n");
  printf("They were stumped by a mysterious arithmetic calculation which had got them all in a bind.\n");
  printf("Sherlock decided to take on the case and got to work.\n");

  int a, b, c, d;
  float result;
  
  printf("Please enter the first three numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("Thank you. Now please enter the fourth number: ");
  scanf("%d", &d);

  result = (float)(a * b) / (float)(c + d);
  
  printf("The result of the calculation is: %.2f", result);
  
  printf("\n\nSherlock Holmes sat back in his chair, triumphant, having cracked the case.");
  printf("He smiled to himself, knowing that the Scotland Yard would be grateful for his help yet again.\n");

  return 0;
}
//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>

int main() {
  int x = 20;
  char* y = "hello";
  float z = 3.14159;
  
  printf("%d\n", x);
  printf("%s\n", y);
  printf("%f\n", z);
  
  printf("Let's have some fun with our variables!\n");
  
  x = x * 2;
  printf("x is now %d\n", x);
  
  y[0] = 'j';
  printf("y is now %s\n", y); // Oops, we can't change a string like that!
  
  z = z + 1;
  printf("z is now %f\n", z);
  
  printf("But wait, what happens if we divide by 0?\n");
  printf("%f\n", x / 0); // Uh oh, we got a runtime error!
  
  printf("Let's involve some user input now. Give me a number.\n");
  
  int a;
  scanf("%d", &a);
  
  printf("Thanks! You entered %d\n", a);
  
  printf("Let's do something crazy with your number.\n");
  int b = a / 0;
  printf("Your number divided by 0 is... %d\n", b); // Oops, we did it again!
  
  return 0;
}
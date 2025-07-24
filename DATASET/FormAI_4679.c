//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to my geometry class!\n");
  printf("Today we will be calculating the area of a trapezoid. But first, let me introduce you to our lazy student, Bob.\n");
  
  printf("Bob, what is the length of the top base of our trapezoid? ");
  double topBase;
  scanf("%lf", &topBase);
  printf("Very good, Bob. And what is the length of the bottom base? ");
  double bottomBase;
  scanf("%lf", &bottomBase);
  printf("Excellent. And what is the height of the trapezoid? ");
  double height;
  scanf("%lf", &height);
  
  double area = (topBase + bottomBase) / 2 * height;
  printf("The area of the trapezoid is %.2lf.\n", area);
  
  printf("Now let's move on to our next lesson: the Pythagorean theorem.\n");
  printf("But first, let me tell you a joke. Why was the math book sad? Because it had too many problems!\n");
  
  printf("Alright, let's get to the theorem. Please enter the length of side A: ");
  double sideA;
  scanf("%lf", &sideA);
  printf("Great. And what is the length of side B? ");
  double sideB;
  scanf("%lf", &sideB);
  
  double sideC = sqrt(sideA * sideA + sideB * sideB);
  printf("The length of side C is %.2lf.\n", sideC);
  
  printf("Congratulations, you have completed our geometry lesson for today. Please come back again for more terrible jokes and great math skills.\n");
  
  return 0;
}
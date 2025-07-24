//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>

int main() {
  printf("I can't believe it actually worked!\n");
  
  int inputs[3];
  printf("Enter the value for three inputs (0 or 1):\n");
  scanf("%d %d %d", &inputs[0], &inputs[1], &inputs[2]);
  
  int output = (inputs[0] && inputs[1]) || (!inputs[2]);
  
  printf("The output is: %d\n", output);
  
  printf("Let's see if we can make our circuit a bit more complex...\n");
  
  int a, b, c, d, e, f;
  printf("Enter the value for six inputs (0 or 1):\n");
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  
  int output1 = (a && b) || (!c);
  int output2 = (!d || e) && f;
  int finalOutput = (output1 && output2);
  
  printf("The final output is: %d\n", finalOutput);
  
  printf("Wow, it's amazing how this simulator can handle such complex circuits!\n");
  
  return 0;
}
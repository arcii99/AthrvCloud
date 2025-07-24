//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {

  int a, b, c, d, result;
  
  printf("Let's rock this program! Enter four numbers:\n");
  scanf("%d %d %d %d", &a, &b, &c, &d);

  if (a%2 == 0){
    result = (a + b) * (c - d);
    printf("\n\e[1;34mThe result of (%d + %d) * (%d - %d) is %d\e[0m", a, b, c, d, result);
    printf("\n\e[1;32mWohoo! You smashed it Bro!!\e[0m");
  }

  else{
    result = (a * b) + (c * d);
    printf("\n\e[1;34mThe result of (%d * %d) + (%d * %d) is %d\e[0m", a, b, c, d, result);
    printf("\n\e[1;32mHell yeah! You killed it!!\e[0m");
  }

  return 0;
}
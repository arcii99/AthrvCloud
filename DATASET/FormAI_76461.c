//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include<stdio.h>

int main() {
  int rows, i, j, space, k = 0;
  printf("Wow! I'm so excited to show you a unique pattern today! \n");
  printf("Enter number of rows (at least 5): ");
  scanf("%d", &rows);

  if(rows < 5) {
    printf("Sorry, this pattern requires at least 5 rows. Let's try again later!");
    return 0;
  }

  printf("Here we go, printing your amazing pattern... \n");

  for(i = 1; i <= rows; ++i, k = 0) {
    for(space = 1; space <= rows-i; ++space) {
      printf("  ");
    }
    while(k != 2*i-1) {
      if(i == rows || k == 0 || k == 2*i-2)
        printf("* ");
      else
        printf("# ");
      ++k;
    }
    printf("\n");
  }

  printf("Did you like it?! I knew it! :D\n");
  return 0;
}
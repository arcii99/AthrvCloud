//FormAI DATASET v1.0 Category: Pattern printing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int rows, cols, i, j, count;
  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &rows, &cols);

  if (rows < 1 || cols < 1)
  {
    printf("Invalid inputs. Please enter positive values.\n");
    exit(1);
  }

  count = 1;
  for (i = 1; i <= rows; i++)
  {
    for (j = 1; j <= cols; j++)
    {
      if (i == 1 || i == rows)
      {
        // print the * pattern in the first and last row
        printf("* ");
      }
      else if (j == 1 || j == cols)
      {
        // print the * pattern in the first and last column
        printf("* ");
      } else if (j == count || j == cols - count + 1) {
        // print * in the diagonal pattern
        printf("* ");
      } else {
        printf("  "); // print the empty space otherwise
      }
    }
    printf("\n");
    // update the count variable for diagonal pattern
    count = count + (i <= rows / 2 ? 1 : -1);
  }
  return 0;
}
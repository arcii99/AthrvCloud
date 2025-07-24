//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
  printf("My dearest Romeo, pray tell me, what is the date today?\n");
  int date;
  scanf("%d", &date);

  if (date % 4 == 0) {
    printf("Ah, my sweet, today is a leap year indeed!\n");
  }
  
  if (date / 100 == 13) {
    printf("Oh no! Such unlucky date is upon us, my love.\n");
  } else {
    printf("Fear not, my dear Romeo, today is a lovely day.\n");
  }
  
  if (date >= 1597 && date <= 1603) {
    printf("Alas, my love, we are in the time of Queen Elizabeth.\n");
  } else {
    printf("My heart sings out with joy knowing we are free to love in any time period.\n");
  }

  return 0;  
}
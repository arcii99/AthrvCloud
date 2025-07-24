//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>

int main() {
  printf("I am a sorting program! \n\n");
  printf("I can sort numbers, and even words \n");
  printf("Let me show you a surprise! \n\n");
  
  int numbers[10] = {2, 4, 1, 5, 3, 8, 9, 7, 6, 10};
  
  printf("Before sorting: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", numbers[i]);
  }
  
  // surprise! sorting with a twist
  for (int i = 0; i < 10; i++) {
    if (numbers[i] % 2 == 0) {
      for (int j = i + 1; j < 10; j++) {
        if (numbers[j] % 2 == 0 && numbers[i] > numbers[j]) {
          int temp = numbers[i];
          numbers[i] = numbers[j];
          numbers[j] = temp;
          break;
        }
      }
    } else {
      for (int j = i + 1; j < 10; j++) {
        if (numbers[j] % 2 == 1 && numbers[i] < numbers[j]) {
          int temp = numbers[i];
          numbers[i] = numbers[j];
          numbers[j] = temp;
          break;
        }
      }
    }
  }
  
  printf("\nAfter sorting: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", numbers[i]);
  }
  
  char words[5][20] = {"orange", "banana", "apple", "kiwi", "pear"};
  
  printf("\n\nNow let's sort some words!\n");
  printf("Before sorting: ");
  for (int i = 0; i < 5; i++) {
    printf("%s ", words[i]);
  }
  
  // sorting words in reverse alphabetical order
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (strcmp(words[i], words[j]) < 0) {
        char temp[20];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
      }
    }
  }
  
  printf("\nAfter sorting: ");
  for (int i = 0; i < 5; i++) {
    printf("%s ", words[i]);
  }
  
  printf("\n\nSurprised? I can sort anything with a little twist! \n");
  
  return 0;
}
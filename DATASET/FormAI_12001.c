//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
  char string_array[6][50] = {"cat", "dog", "fish", "horse", "bird", "hamster"};
  char search_string[50];
  int flag=0;

  printf("Enter a word to search: ");
  scanf("%s", search_string);

  for(int i=0; i<6; i++) {
    if(strcmp(search_string, string_array[i]) == 0) {
      printf("The word %s is present at index %d\n", search_string, i);
      flag = 1;
    }
  }

  if(flag==0){
    printf("The word %s is not present in the array.\n", search_string);
  }

  return 0;
}
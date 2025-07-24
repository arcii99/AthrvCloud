//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  int count = 0;
  printf("Enter a sentence: ");
  fgets(input, sizeof(input), stdin);
  for(int i=0; i<strlen(input); i++) {
    if(input[i] == ' ' && input[i+1] != ' ') {
      count++;
    }
  }
  if(count>0) {
    printf("There are %d words in the sentence.\n", count+1);
  } else {
    printf("There is 1 word in the sentence.\n");
  }
  return 0;
}
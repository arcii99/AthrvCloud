//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <string.h>

int count_paranoid(char str[]){
  int i, j, k, l, count = 0;
  char match[] = "paranoid";
  int match_length = strlen(match);
  int str_length = strlen(str);

  for (i = 0; i <= str_length - match_length; i++){
    j = i;

    for (k = 0; k < match_length; k++){
      if (match[k] != str[j]){
        break;
      }
      j++;
    }
    if (k == match_length){
      count++;
    } else {
      for (l = i; l <= j; l++){
        if (str[l] >= 'a' && str[l] <= 'z'){
          str[l] -= 32; // Convert to capital letters
        }
      }
    }
  }
  return count;
}

int main(){
  char str[1000];
  printf("Enter a string of characters: ");
  fgets(str, 1000, stdin);
  int count = count_paranoid(str);
  printf("The word paranoid appeared %d times:\n", count);
  printf("%s", str);
  return 0;
}
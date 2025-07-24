//FormAI DATASET v1.0 Category: String manipulation ; Style: single-threaded
#include<stdio.h>
#include<string.h>

int main(){
  char str1[100], str2[100], temp[100];
  printf("Enter the first string: ");
  scanf("%s", str1);
  printf("Enter the second string: ");
  scanf("%s", str2);

  // String Concatenation
  printf("String Concatenation: %s\n", strcat(str1, str2));

  // String Copy
  printf("String Copy: %s\n", strcpy(temp, str1));

  // String Comparison
  if(strcmp(str1, temp) == 0){
      printf("Strings are equal!\n");
    }
  else{
      printf("Strings are not equal!\n");
    }

  // String Length
  printf("String Length of the first string: %ld\n", strlen(str1));

  // String Reversal
  int len = strlen(str1);
  for(int i=0; i<len/2; i++){
      char temp = str1[i];
      str1[i] = str1[len-i-1];
      str1[len-i-1] = temp;
    }
  printf("String Reversal of the first string: %s\n", str1);

  // Substring Extraction
  char substr[100];
  printf("Enter the substring to be extracted from the first string: ");
  scanf("%s", substr);
  if(strstr(str1, substr) != NULL){
      int firstIndex = strstr(str1, substr) - str1;
      printf("Substring found at index: %d\n", firstIndex);
    }
  else{
      printf("Substring not found in the first string!\n");
    }
  return 0;
}
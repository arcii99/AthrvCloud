//FormAI DATASET v1.0 Category: String manipulation ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
  char my_string[] = "The elephant walked into the room wearing a tutu";
  char temp_string[50];
  int index, i, j;
  
  printf("Original string: %s\n", my_string);
  
  // Remove the elephant
  index = strstr(my_string, "elephant") - my_string;
  for(i = 0; i < index; i++) {
    temp_string[i] = my_string[i];
  }
  for(i = index + strlen("elephant"); i < strlen(my_string); i++) {
    temp_string[i - strlen("elephant")] = my_string[i];
  }
  temp_string[i - strlen("elephant")] = '\0';
  strcpy(my_string, temp_string);
  printf("After removing the elephant: %s\n", my_string);
  
  // Replace "walked" with "galloped"
  index = strstr(my_string, "walked") - my_string;
  for(i = 0; i < index; i++) {
    temp_string[i] = my_string[i];
  }
  strcpy(temp_string + index, "galloped");
  j = index + strlen("galloped");
  for(i = index + strlen("walked"); i < strlen(my_string); i++) {
    temp_string[j++] = my_string[i];
  }
  temp_string[j] = '\0';
  strcpy(my_string, temp_string);
  printf("After replacing 'walked' with 'galloped': %s\n", my_string);

  // Reverse the entire string
  for(i = 0, j = strlen(my_string) - 1; i < j; i++, j--) {
    char temp = my_string[i];
    my_string[i] = my_string[j];
    my_string[j] = temp;
  }
  printf("After reversing the string: %s\n", my_string);

  // Capitalize every other letter
  for(i = 0; i < strlen(my_string); i++) {
    if(i % 2 == 0) {
      my_string[i] = toupper(my_string[i]);
    }
  }
  printf("After capitalizing every other letter: %s\n", my_string);

  return 0;
}
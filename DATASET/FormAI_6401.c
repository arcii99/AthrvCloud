//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
  char c_cat[100], human[100];
  
  printf("Enter a sentence in the C Cat Language: ");
  scanf("%[^\n]",c_cat);
  
  //translation rules for the C Cat Language
  if(strcmp(c_cat,"meow")==0) {
    strcpy(human,"Hello");
  } else if(strcmp(c_cat,"purr")==0) {
    strcpy(human,"Thank You");
  } else if(strcmp(c_cat,"hiss")==0) {
    strcpy(human,"Goodbye");
  } else {
    strcpy(human,"I don't speak C Cat!");
  }
  
  printf("\nTranslation: %s\n",human);
  
  return 0;
}
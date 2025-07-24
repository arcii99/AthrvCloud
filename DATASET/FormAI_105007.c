//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char text[1000];
  int count = 0;
  
  printf("Enter some text: ");
  fgets(text, 1000, stdin);
  
  // Counting the number of vowels in the entered text
  for(int i=0; text[i]!='\0'; i++) {
    if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || 
       text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U') {
      count++;
    }
  }
  
  // Displaying the result
  printf("\n");
  printf("The number of vowels in the entered text is: %d\n", count);
  
  // Converting the text to uppercase
  for(int i=0; i<strlen(text); i++) {
    if(text[i]>='a' && text[i]<='z') {
      text[i] -= 32;
    }
  }
  
  // Displaying the uppercase text
  printf("\n");
  printf("The text in uppercase is: %s", text);
  
  // Converting the text to lowercase
  for(int i=0; i<strlen(text); i++) {
    if(text[i]>='A' && text[i]<='Z') {
      text[i] += 32;
    }
  }
  
  // Displaying the lowercase text
  printf("\n");
  printf("The text in lowercase is: %s", text);
  
  return 0;
}
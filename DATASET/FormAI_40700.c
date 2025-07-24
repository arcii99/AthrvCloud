//FormAI DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin); // Reading input from user
  int vowelCount=0, consonantCount=0;
  for(int i=0; str[i]!='\0'; i++) {
    if(str[i]=='a' || str[i]=='e' || str[i]=='i' 
       || str[i]=='o' || str[i]=='u' || str[i]=='A'
       || str[i]=='E' || str[i]=='I' || str[i]=='O'
       || str[i]=='U') { // counting vowels
      vowelCount++;
    }
    else {
      consonantCount++; // counting consonants
    }
  }
  printf("Number of vowels in the string: %d\n", vowelCount);
  printf("Number of consonants in the string: %d\n", consonantCount);
  char reverseStr[100];
  int j=0;
  for(int i=strlen(str)-1; i>=0; i--) {
    reverseStr[j] = str[i]; // reversing the string
    j++;
  }
  reverseStr[j] = '\0';
  printf("Reversed string: %s\n", reverseStr);
  return 0;
}
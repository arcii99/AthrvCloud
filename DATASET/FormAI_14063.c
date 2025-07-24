//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>

int main() {
  char str[50];
  printf("Enter your string: ");
  fgets(str, 50, stdin); // getting input string
  
  // processing string
  int vowels = 0, consonants = 0, spaces = 0, digits = 0, specialchars = 0;
  for(int i=0; str[i]!='\0'; i++) {
    if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z') {
      char ch = tolower(str[i]); // convert to lowercase
      if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') vowels++;
      else consonants++;
    }
    else if(str[i]>='0' && str[i]<='9') digits++;
    else if(str[i]==' ') spaces++;
    else specialchars++;
  }
  
  // output results
  printf("\nYour string contains:\n");
  printf("%d vowels\n", vowels);
  printf("%d consonants\n", consonants);
  printf("%d spaces\n", spaces);
  printf("%d digits\n", digits);
  printf("%d special characters\n", specialchars);

  return 0;
}
//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>

int main()
{
  char input_str[100];  // Input string to be processed
  int input_len;  // Length of the input string

  printf("Enter some text to process: ");
  fgets(input_str, 100, stdin);   // Get input string from the user

  input_len = strlen(input_str);  // Find the length of the input string

  // Print the input string in reverse order
  printf("The reverse of the input string is: ");
  for (int i = input_len - 1; i >= 0; i--)
  {
    printf("%c", input_str[i]);
  }
  printf("\n");

  // Print the number of vowels and consonants in the input string
  int vowels = 0, consonants = 0;
  for (int i = 0; i < input_len; i++)
  {
    if (input_str[i] == 'a' || input_str[i] == 'e' || input_str[i] == 'i' || input_str[i] == 'o' || input_str[i] == 'u' || input_str[i] == 'A' || input_str[i] == 'E' || input_str[i] == 'I' || input_str[i] == 'O' || input_str[i] == 'U')
    {
      vowels++;
    }
    else if ((input_str[i] >= 'a' && input_str[i] <= 'z') || (input_str[i] >= 'A' && input_str[i] <= 'Z'))
    {
      consonants++;
    }
  }
  printf("The input string contains %d vowels and %d consonants.\n", vowels, consonants);

  // Print the input string with all uppercase characters converted to lowercase
  printf("The input string with all uppercase characters converted to lowercase: ");
  for (int i = 0; i < input_len; i++)
  {
    if (input_str[i] >= 'A' && input_str[i] <= 'Z')
    {
      printf("%c", input_str[i] + 32);   // Convert uppercase character to lowercase by adding 32
    }
    else
    {
      printf("%c", input_str[i]);
    }
  }
  printf("\n");

  return 0;
}
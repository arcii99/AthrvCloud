//FormAI DATASET v1.0 Category: String manipulation ; Style: irregular
#include<stdio.h>
#include<string.h>

int main(){

  char input_string[100];
  int choice, len;

  printf("Welcome to the String Manipulation Program!\n");

  while(1){
    printf("\nPlease enter a string (type 'exit' to quit): ");
    scanf("%s", input_string);
    len = strlen(input_string);
    if(strcmp(input_string, "exit") == 0){
       printf("Thank you for using the program. Goodbye!\n");
       break;  
    }
    printf("\nPlease choose an option below:\n");
    printf("1. Reverse the string\n");
    printf("2. Convert to uppercase\n");
    printf("3. Convert to lowercase\n");
    printf("4. Replace a character in the string\n");
    printf("5. Count the number of characters in the string\n");
    printf("Choice: ");

    scanf("%d", &choice);

    switch(choice){
      case 1: 
        printf("\nThe reversed string is: ");
        for(int i = len-1; i >= 0; i--)
           printf("%c", input_string[i]);
        break;
      case 2:
        printf("\nThe uppercase string is: ");
        for(int i = 0; i < len; i++)
           printf("%c", toupper(input_string[i]));
        break;
      case 3:
        printf("\nThe lowercase string is: ");
        for(int i = 0; i < len; i++)
           printf("%c", tolower(input_string[i]));
        break;
      case 4:
        char search_char, replace_char;
        printf("\nEnter the search character: ");
        scanf(" %c", &search_char);
        printf("\nEnter the replace character: ");
        scanf(" %c", &replace_char);
        printf("\nThe new string is: ");
        for(int i = 0; i < len; i++){
           if(input_string[i] == search_char)
              printf("%c", replace_char);
           else
              printf("%c", input_string[i]);
        }
        break;
      case 5:
        printf("\nThe number of characters in the string is: %d", len);
        break;
      default:
        printf("\nInvalid choice. Please try again.");
    }
  }

  return 0;
}
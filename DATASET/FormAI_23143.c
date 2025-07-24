//FormAI DATASET v1.0 Category: String manipulation ; Style: bold
#include <stdio.h>
#include <string.h>

int main() {
  char name[30] = "John Doe";
  char in[30];
  
  printf("Welcome to the Bold String Manipulator!\n");
  printf("Your current string is: %s\n", name);
  
  printf("Would you like to modify the string? (y/n): ");
  fgets(in, sizeof(in), stdin);
  in[strcspn(in, "\n")] = 0; //remove newline from input
  
  while(strcmp(in, "y") == 0) {
    printf("What would you like to do with the string?\n");
    printf("1. Make it all caps\n");
    printf("2. Make it all lower-case\n");
    printf("3. Replace a letter with another letter\n");
    printf("4. Reverse the string\n");
    printf("5. Append another string\n");
    printf("6. Prepend another string\n");
    printf("7. Count the number of characters\n");
    printf("8. Count the number of words\n");
    
    int choice;
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);
    getchar(); //clear input buffer
    
    switch(choice) {
      case 1:
        for(int i = 0; i < strlen(name); i++) {
          if(name[i] >= 'a' && name[i] <= 'z') {
            name[i] = name[i] - 32;
          }
        }
        break;
      case 2:
        for(int i = 0; i < strlen(name); i++) {
          if(name[i] >= 'A' && name[i] <= 'Z') {
            name[i] = name[i] + 32;
          }
        }
        break;
      case 3:
        printf("Enter the letter you want to replace: ");
        char oldLetter = getchar();
        getchar(); //clear input buffer
        printf("Enter the letter to replace it with: ");
        char newLetter = getchar();
        getchar(); //clear input buffer
        
        for(int i = 0; i < strlen(name); i++) {
          if(name[i] == oldLetter) {
            name[i] = newLetter;
          }
        }
        break;
      case 4:
        for(int i = 0; i < strlen(name)/2; i++) {
          char temp = name[i];
          name[i] = name[strlen(name)-i-1];
          name[strlen(name)-i-1] = temp;
        }
        break;
      case 5:
        printf("Enter the string to append: ");
        char toAppend[30];
        fgets(toAppend, sizeof(toAppend), stdin);
        toAppend[strcspn(toAppend, "\n")] = 0; //remove newline from input
        
        strcat(name, toAppend);
        break;
      case 6:
        printf("Enter the string to prepend: ");
        char toPrepend[30];
        fgets(toPrepend, sizeof(toPrepend), stdin);
        toPrepend[strcspn(toPrepend, "\n")] = 0; //remove newline from input
        
        char temp[30];
        strcpy(temp, name);
        strcpy(name, toPrepend);
        strcat(name, temp);
        break;
      case 7:
        printf("The number of characters in the string is: %d\n", strlen(name));
        break;
      case 8:
        int wordCount = 0;
        for(int i = 0; i < strlen(name); i++) {
          if(name[i] == ' ') {
            wordCount++;
          }
        }
        printf("The number of words in the string is: %d\n", wordCount+1);
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
    
    printf("Your current string is: %s\n", name);
    printf("Would you like to modify the string again? (y/n): ");
    fgets(in, sizeof(in), stdin);
    in[strcspn(in, "\n")] = 0; //remove newline from input
  }
  
  printf("Thank you for using the Bold String Manipulator!");
  
  return 0;
}
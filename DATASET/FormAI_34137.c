//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include<stdio.h>
#include<string.h>

int main(){
    char name[50];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); //input name with spaces
    name[strcspn(name, "\n")] = 0; //remove newline character from fgets
    
    printf("Your name is: %s\n", name);
    
    //count the number of words in the name
    int wordCount = 0;
    for(int i=0; name[i]!='\0'; i++){
        if(name[i] == ' '){
            wordCount++;
        }
    }
    wordCount++; //increment word count after last word
    
    printf("Number of words in your name: %d\n", wordCount);
    
    //determine the length of the name
    int nameLength = strlen(name);
    
    printf("Length of your name: %d\n", nameLength);
    
    //convert the name to uppercase
    for(int i=0; name[i]!='\0'; i++){
        if(name[i] >= 'a' && name[i] <= 'z'){
            name[i] = name[i] - 32;
        }
    }
    
    printf("Your name in uppercase: %s\n", name);
    
    //check if the name starts with a vowel
    if(name[0] == 'A' || name[0] == 'E' || name[0] == 'I' || name[0] == 'O' || name[0] == 'U'){
        printf("Your name starts with a vowel.\n");
    }
    else{
        printf("Your name does not start with a vowel.\n");
    }
    
    return 0;
}
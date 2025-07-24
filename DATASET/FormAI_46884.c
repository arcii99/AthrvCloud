//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

char text[100];
int choice, length;

printf("Enter a string:\n");
scanf("%[^\n]%*c", text); 

length=strlen(text);

printf("\nSelect from the following:\n");
printf("1. Convert all characters to uppercase\n");
printf("2. Convert all characters to lowercase\n");
printf("3. Replace all vowels with *\n");
printf("4. Count the number of words\n");
printf("5. Reverse the string\n");
printf("6. Exit\n");

scanf("%d", &choice);

switch(choice) {

case 1:
    for(int i=0; i<length; i++) {
        text[i]= toupper(text[i]);
    }
    printf("Result: %s\n", text);
    break;

case 2:
    for(int i=0; i<length; i++) {
        text[i]= tolower(text[i]);
    }
    printf("Result: %s\n", text);
    break;

case 3:
    for(int i=0; i<length; i++) {
        if((text[i]=='a') || (text[i]=='e') || (text[i]=='i') || (text[i]=='o') || (text[i]=='u') || (text[i]=='A') || (text[i]=='E') || (text[i]=='I') || (text[i]=='O') || (text[i]=='U')) {
            text[i]= '*';
        }
    }
    printf("Result: %s\n", text);
    break;

case 4:
    int word_count=0;
    for(int i=0; i<length; i++) {
        if(text[i]==' ') {
            word_count++;
        }
    }
    printf("Number of words: %d\n", word_count+1);
    break;

case 5:
    for(int i=0; i<length/2; i++) {
        char temp = text[i];
        text[i] = text[length-i-1];
        text[length-i-1] = temp;
    }
    printf("Result: %s\n", text);
    break;

case 6:
    printf("Exiting program...\n");
    break;

default:
    printf("Invalid choice!\n");
    break;
}

return 0;
}
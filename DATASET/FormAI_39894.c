//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
#include<stdio.h>
#include<string.h>

// Defining Morse code array
char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

//Function to convert text to Morse code
void text_to_morse(char text[1000]){
    int len = strlen(text);
    for(int i=0;i<len;i++){
        if(text[i]>='a' && text[i]<='z'){
            printf("%s ", morse[text[i]-'a']);
        }else if(text[i]>='A' && text[i]<='Z'){
            printf("%s ", morse[text[i]-'A']);
        }else if(text[i]==' '){
            printf("  ");
        }
    }
}

//Main function
int main(){
    char text[1000];
    printf("Enter the text to convert to Morse code: ");
    scanf("%[^\n]", text);
    printf("Morse code: ");
    text_to_morse(text);
    printf("\n");
    return 0;
}
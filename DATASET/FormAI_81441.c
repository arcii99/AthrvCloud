//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include<stdio.h>
#include<string.h>

int main(){

char text[200]; 
char word[20];
int count=0,i,j;
printf("Enter a text: ");
gets(text); // Inputting the text

printf("Enter a word to count: ");
gets(word); // Inputting the word to be counted

int text_length = strlen(text); //Length of inputted text
int word_length = strlen(word); //Length of inputted word

for(i=0;i<text_length;i++) //Loop for checking each character in the text
{
    if(text[i]==word[0])
    {
        int check=1;
        for(j=1;j<word_length;j++) //Loop for checking rest of the characters within the word
        {
            if(text[i+j]!=word[j]) //If they do not match, check is set to 0
            {
                check=0;
                break; //No further matching needed
            }
        }
        if(check==1) //If all the characters in the word matches with text starting from the ith character, this counts as a match
        {
            count++; //Increase count
            i+=word_length-1; //Skip the characters that are already checked
        }
    }
}

printf("\n\nThe word \"%s\" occurs %d times in the given text.\n\n",word,count); //Prints the output

return 0;

}
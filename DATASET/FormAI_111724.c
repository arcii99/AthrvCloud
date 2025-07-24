//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: visionary
#include<stdio.h>
#include<string.h>
int main()
{
char text[100];
printf("Enter the text to convert into Morse code:\n");
scanf("%[^\n]", text);
convert_to_morse(text);
return 0;
}
void convert_to_morse(char text[])
{
int i;
char morse[26][6]={{".-"},{"-..."},{"-.-."},{"-.."},{"."},{"..-."},{"--."},{"...."},{".."},{"-.--"},{"--.-"},{"-."},
               {"---"},{".--."},{"--.-"},{".-."},{"..."},{"-"},{"..-"},{"...-"},
               {".--"},{"-..-"},{"-.--"},{"--.."}};
for(i=0-strlen(text);i<strlen(text);i++)
{
if(text[i]==' ')
{
printf("/ ");
}
else if(text[i]>=65 && text[i]<=90)
{
printf("%s ",morse[text[i]-65]);
}
else
{
printf("%c ",text[i]);
}
}
}
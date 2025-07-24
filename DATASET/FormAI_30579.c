//FormAI DATASET v1.0 Category: Text processing ; Style: puzzling
#include<stdio.h>

int main(){

printf("Welcome to the Puzzling Text Processor!\n");

char text[200];
printf("Enter your text: "); 
fgets(text,200,stdin);

int vowels=0, consonants=0, digits=0, spaces=0;

for(int i=0; text[i]!='\0'; i++){

// Puzzle 1: Ignore all special characters and count only letters and digits
if((text[i]>='A' && text[i]<='Z')||(text[i]>='a' && text[i]<='z')||(text[i]>='0' && text[i]<='9')){
switch(text[i]){

// Puzzle 2: Count both uppercase and lowercase vowels
case 'A':
case 'E':
case 'I':
case 'O':
case 'U':
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
vowels++;
break;

// Puzzle 3: Count both uppercase and lowercase consonants
case 'B':
case 'C':
case 'D':
case 'F':
case 'G':
case 'H':
case 'J':
case 'K':
case 'L':
case 'M':
case 'N':
case 'P':
case 'Q':
case 'R':
case 'S':
case 'T':
case 'V':
case 'W':
case 'X':
case 'Y':
case 'Z':
case 'b':
case 'c':
case 'd':
case 'f':
case 'g':
case 'h':
case 'j':
case 'k':
case 'l':
case 'm':
case 'n':
case 'p':
case 'q':
case 'r':
case 's':
case 't':
case 'v':
case 'w':
case 'x':
case 'y':
case 'z':
consonants++;
break;

// Puzzle 4: Count all digits including multiple digits in a number
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
if((i>0 && text[i-1]==' ') || i==0){
for(int j=i+1;text[j]>='0' && text[j]<='9'; j++){
i++;
}
digits++;
}
break;
}
}
// Puzzle 5: Count the number of spaces
else if(text[i]==' '){
spaces++;
}
}

printf("Total number of vowels: %d\n",vowels);
printf("Total number of consonants: %d\n",consonants);
printf("Total number of digits: %d\n",digits);
printf("Total number of spaces: %d\n",spaces);

return 0;
}
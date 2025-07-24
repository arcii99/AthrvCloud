//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Cryptic
#include<stdio.h>
#include<string.h> //include string library
int main(){
char cryptic12[200], cryptic23[200], cryptic123[200];
int cryptic32, cryptic321, crypticstart, crypticend, crypticlast, crypticfirst, cryptica, crypticb;
int cryptici;

//user input
printf("Welcome to Cryptic Palindrome Checker!\nPlease enter your string: ");
scanf("%s",&cryptic12);

//copying the string and reversing it using a for loop
for(cryptici=0; cryptic12[cryptici]!='\0'; cryptici++){
cryptic23[cryptic32] = cryptic12[cryptici];
cryptic32++;
}
cryptic23[cryptic32] = '\0';
cryptic321 = strlen(cryptic23)-1; 

//checking if the copied string matches the original string
for(cryptica=0; cryptic12[cryptica]!='\0'; cryptica++){
if(cryptic12[cryptica]!=cryptic23[cryptic321]){
crypticb = 1;
break;
}
cryptic321--;
}

//if the string is a palindrome
if(crypticb == 0){
printf("\nCongratulation! Your string is a cryptic palindrome!\n");
}
//if the string is not a palindrome
else{
printf("\nUnfortunately, your string is not a cryptic palindrome.\n");
}
return 0;
}
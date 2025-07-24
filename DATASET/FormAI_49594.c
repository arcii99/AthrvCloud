//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include<stdio.h>
#include<string.h>

int main() {

char str[100], temp[100];
int i, j, k, l;

// Getting Input from User
printf("Enter the string: ");
gets(str);

// Copy string to temp array
strcpy(temp, str);

// Converting string to Lowercase
for(i=0; str[i]!='\0'; i++){
    if(str[i]>='A' && str[i]<='Z'){
        str[i] = str[i] + 32;
    }
}

// Finding length of string
l = strlen(str);

// Reversing the string
for(i=0, j=l-1; i<j; i++, j--) {
    temp[i] = str[j];
    temp[j] = str[i];
}

// Removing vowels from the string
for(i=0; temp[i]!='\0'; i++){
    if(temp[i]=='a' || temp[i]=='e' || temp[i]=='i' || temp[i]=='o' || temp[i]=='u' || temp[i]=='A' || temp[i]=='E' || temp[i]=='I' || temp[i]=='O' || temp[i]=='U'){
        for(j=i; temp[j]!='\0'; j++){
            temp[j] = temp[j+1];
        }
        temp[j] = '\0';
        i--;
    }
}

// Displaying the final result
printf("The original string is: %s\n", str);
printf("The reverse string is: %s\n", temp);

return 0;
}
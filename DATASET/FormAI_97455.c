//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: satisfied
#include <stdio.h>

int main() {

char text[1000];
int length,i,j;

printf("Enter text to convert to ASCII art: ");
scanf("%[^\n]", text);

length=strlen(text);

// Printing Art Header
printf("\n");
for(i=0;i<=length+3;++i){
    printf("/");
}
printf("\n");

// Printing Text in ASCII Art
printf("// ");
for(i=0;i<=length;++i){
    printf("%c ",text[i]);
}
printf("//\n");

// Printing Art Footer
printf("/");
for(i=0;i<=length+2;++i){
    printf("¯");
}
printf("/\n");

return 0;
}
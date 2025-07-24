//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include<stdio.h>
#include<string.h>

int main() {
    char text[100];
    int i, j, len;
    
    printf("Enter the text: ");
    scanf("%[^\n]%*c", text);
    
    len = strlen(text);
    
    // Remove duplicate spaces
    for(i=0; i<len; i++) {
        if(text[i]==' ' && text[i+1]==' ') {
            for(j=i+1; j<len; j++) {
                text[j] = text[j+1];
            }
            len--;
            i--;
        }
    }
    
    // Count number of words
    int wordCount = 0;
    for(i=0; i<=len; i++) {
        if(text[i]==' ' || text[i]=='\0') {
            wordCount++;
        }
    }
    
    // Count number of vowels and consonants
    int vowelCount = 0, consonantCount = 0;
    for(i=0; i<len; i++) {
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U') {
            vowelCount++;
        }
        else if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')) {
            consonantCount++;
        }
    }
    
    // Print results
    printf("\nThe processed text is: %s\n", text);
    printf("\nNumber of words: %d\n", wordCount);
    printf("\nNumber of vowels: %d\n", vowelCount);
    printf("\nNumber of consonants: %d\n", consonantCount);
    
    return 0;
}
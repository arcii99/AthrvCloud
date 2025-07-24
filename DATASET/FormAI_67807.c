//FormAI DATASET v1.0 Category: Encryption ; Style: careful
#include<stdio.h>
#include<string.h>

char* encrypt(char str[], int key) 
{ 
    int len = strlen(str); 
    char *out = (char*)malloc((len+1)*sizeof(char));
    strcpy(out,str);
    for (int i=0; i<len; i++) 
    { 
        if (isalpha(out[i])) 
        { 
            if (isupper(out[i])) 
                out[i] = ((out[i]-'A'+key) % 26) + 'A'; 
            else
                out[i] = ((out[i]-'a'+key) % 26) + 'a'; 
        } 
    } 
    return out; 
} 

int main() 
{ 
    char str[100],*out; 
    int key;

    printf("Enter string to encrypt: ");
    scanf("%[^\n]s",str);

    printf("Enter key: ");
    scanf("%d",&key);

    out = encrypt(str,key);
    
    printf("Encrypted string: %s",out); 
    free(out);
    return 0; 
}
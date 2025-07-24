//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
    char str[1000]; 
    int key, n, i; 

    printf("Enter a string to encrypt: "); 
    fgets(str, sizeof(str), stdin); 
            
    printf("Enter a key for encryption: "); 
    scanf("%d", &key); 

    n = strlen(str); 
    
    // Shocked by the strings, let's shuffle the letters!
    for (i = 0; i < n; i++) 
    { 
        if (str[i] >= 'a' && str[i] <= 'z') 
            str[i] = ((str[i] - 'a' + key) % 26) + 'a'; 
        else if (str[i] >= 'A' && str[i] <= 'Z') 
            str[i] = ((str[i] - 'A' + key) % 26) + 'A'; 
    } 

    printf("The encrypted string is: %s\n", str); 

    return 0; 
}
//FormAI DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

int prime[MAX], k=0;

// Function to generate all prime numbers up to a given limit
void generatePrimeNumbers(int limit){
    int i, j, flag;
    // Initialize all elements of prime[] to 1
    memset(prime, 1, sizeof(prime));
    // Mark 0 and 1 as non-prime
    prime[0] = 0;
    prime[1] = 0;
    // Sieve of Eratosthenes to mark the non-prime numbers
    for(i=2; i<=sqrt(limit); i++){
        if(prime[i]){
            for(j=i*i; j<=limit; j+=i){
                prime[j] = 0;
            }
        }
    }
    // Count the number of prime numbers generated
    for(i=2; i<=limit; i++){
        if(prime[i]){
            k++;
        }
    }
}

// Function to encrypt the given message
void encrypt(char *message, int key){
    int len = strlen(message), i, j;
    int rows = key;
    int cols = ceil((float)len/key);
    int k=0;
     
    // Create the matrix to store the message
    char matrix[rows][cols];
    // Fill the matrix column-wise
    for(i=0; i<cols; i++){
        for(j=0; j<rows; j++){
            if(k<len){
                matrix[j][i] = message[k++];
            }else{
                matrix[j][i] = ' ';
            }
        }
    }
    // Print the encrypted message row-wise
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("%c", matrix[i][j]);
        }
    }
}

int main(){
    int limit = 1000;
    char message[MAX];
    int key;
    
    // Generate all prime numbers up to a given limit
    generatePrimeNumbers(limit);
    
    printf("Enter the message to encrypt: ");
    fgets(message, MAX, stdin);
    printf("Enter the encryption key: ");
    scanf("%d", &key);
    
    // Check if the key is prime
    if(prime[key]){
        printf("Encrypted message: ");
        encrypt(message, key);
        printf("\n");
    }else{
        printf("Invalid key! Key must be a prime number\n");
    }
    
    return 0;
}
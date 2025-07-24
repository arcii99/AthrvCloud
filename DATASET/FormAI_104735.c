//FormAI DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include<stdio.h>

int main(){
    int num, n, i, j, k, bits[1000];
    printf("O Romeo, Romeo! wherefore art thou Romeo?\n"); // Oh Romeo, Romeo! Why are you a binary number?
    printf("Enter thy decimal number: "); // Enter your decimal number
    scanf("%d", &num);
    n = num;
    i = 0;
    while(n > 0){
        bits[i] = n % 2; // Convert to binary
        n = n / 2;
        i++;
    }
    printf("It is the east, and Juliet is the sun.\n"); // It is the east, and Juliet is the sun. (Output start)
    printf("Forsooth! Thy binary equivalent is: ");
    for(j = i - 1; j >= 0; j--){
        printf("%d", bits[j]);
    }
    printf("\nArise, fair sun, and kill the envious moon,\n"); // Arise, fair sun, and kill the envious moon,
    printf("Who is already sick and pale with grief,\n"); // Who is already sick and pale with grief,
    printf("That thou her maid art far more fair than she.\n"); // That thou her maid art far more fair than she. (End of Output)
    printf("Would'st thou like to try again? Y/N: "); // Would you like to try again? Y/N:
    char choice;
    scanf(" %c", &choice);
    if(choice == 'Y' || choice == 'y'){
        main(); // Call the main function recursively
    }
    else{
        printf("Good night, good night! parting is such\nsweet sorrow,\n"); // Good night, good night! Parting is such sweet sorrow,
        printf("That I shall say good night till it be morrow.\n"); // That I shall say good night till it be morrow.
    } 
    return 0;
}
//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

//function to encrypt the plaintext using the Caesar cipher
char* encrypt(char plaintext[], int shift) {
    int n = strlen(plaintext);
    char* ciphertext = (char*) malloc(sizeof(char) * (n+1));
    for(int i=0; i<n; i++) {
        if(isalpha(plaintext[i])) {
            if(isupper(plaintext[i])) {
                ciphertext[i] = (((plaintext[i] - 'A') + shift) % 26) + 'A';
            } else {
                ciphertext[i] = (((plaintext[i] - 'a') + shift) % 26) + 'a';;
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
    return ciphertext;
}

//function to decrypt the ciphertext using the Caesar cipher
char* decrypt(char ciphertext[], int shift) {
    int n = strlen(ciphertext);
    char* plaintext = (char*) malloc(sizeof(char) * (n+1));
    for(int i=0; i<n; i++) {
        if(isalpha(ciphertext[i])) {
            if(isupper(ciphertext[i])) {
                plaintext[i] = (((ciphertext[i] - 'A') - shift + 26) % 26) + 'A';
            } else {
                plaintext[i] = (((ciphertext[i] - 'a') - shift + 26) % 26) + 'a';
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[n] = '\0';
    return plaintext;
}

//function to calculate the frequency of characters in the given text
float* characterFrequency(char text[]) {
    int n = strlen(text);
    float* frequency = (float*) malloc(sizeof(float) * 26);
    int count[26] = {0};
    //counting the characters in the text
    for(int i=0; i<n; i++) {
        if(isalpha(text[i])) {
            if(isupper(text[i])) {
                count[text[i] - 'A']++;
            } else {
                count[text[i] - 'a']++;
            }
        }
    }
    //calculating the relative frequency of each character
    for(int i=0; i<26; i++) {
        frequency[i] = (float) count[i] / n;
    }
    return frequency;
}

//function to calculate the index of coincidence of the given text
float indexOfCoincidence(char text[]) {
    int n = strlen(text);
    float* frequency = characterFrequency(text);
    float index = 0;
    //calculating the index of coincidence using the formula
    for(int i=0; i<26; i++) {
        index += (frequency[i] * (frequency[i] - 1));
    }
    free(frequency);
    return index;
}

int main() {
    char plaintext[] = "thequickbrownfoxjumpsoverthelazydog";
    int shift = 5;
    printf("Original Text : %s\n", plaintext);
    char* ciphertext = encrypt(plaintext, shift);
    printf("Encrypted Text : %s\n", ciphertext);
    char* decryptedtext = decrypt(ciphertext, shift);
    printf("Decrypted Text : %s\n", decryptedtext);
    float ic = indexOfCoincidence(plaintext);
    printf("Index of Coincidence of Original Text : %.4f\n", ic);
    ic = indexOfCoincidence(ciphertext);
    printf("Index of Coincidence of Encrypted Text : %.4f\n", ic);
    free(ciphertext);
    free(decryptedtext);
    return 0;
}
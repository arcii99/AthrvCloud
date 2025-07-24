//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// function to encrypt vote
int encrypt(int vote, int key){
    return (int)pow(vote,key);
}

// function to decrypt vote
int decrypt(int vote, int key){
    return (int)pow(vote,1/key);
}

// function to get vote from user
int getVote(){
    int vote;
    printf("Enter your vote (1 or 2):\n");
    do {
        scanf("%d",&vote);
        if (vote != 1 && vote != 2){
            printf("Invalid vote. Please enter 1 or 2.\n");
        }
    } while (vote != 1 && vote != 2);
    return vote;
}

// function to get private key
int getPrivateKey(){
    int key;
    do {
        printf("Enter your private key (must be a prime number):\n");
        scanf("%d",&key);
        if (!isPrime(key)){
            printf("%d is not a prime number. Please enter a prime number.\n",key);
        }
    } while (!isPrime(key));
    return key;
}

// function to check if number is prime
int isPrime(int num){
    if (num <= 1) return 0;
    for (int i=2;i<=sqrt(num);i++){
        if (num % i == 0) return 0;
    }
    return 1;
}

int main(){
    int vote, privateKey, encryptedVote, decryptedVote;
    // get vote from user
    vote = getVote();
    // get private key
    privateKey = getPrivateKey();
    // encrypt vote
    encryptedVote = encrypt(vote,privateKey);
    printf("Your encrypted vote is: %d\n",encryptedVote);
    // decrypt vote
    decryptedVote = decrypt(encryptedVote,privateKey);
    printf("Your decrypted vote is: %d\n",decryptedVote);
    // check if decrypted vote matches original vote
    if (decryptedVote == vote){
        printf("Your vote was successfully recorded.\n");
    } else {
        printf("There was an error recording your vote. Please try again.\n");
    }
    return 0;
}
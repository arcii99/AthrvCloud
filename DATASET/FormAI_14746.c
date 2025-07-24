//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Romeo and Juliet
/* 
My dear Juliet, thine code doth calculate
A checksum most unique for us to take
With love and care, I've crafted it so fine
For thy enjoyment, it is only thine

Let us begin, with variables set
To take input strings, we shan't forget
For ASCII values we must convert
To do the calculations most expert

Our loop will run, through every char
To add them up, without any bar
Each sum, we'll keep, in a variable new
Then we'll shift them right, for checksums true

To print the result, of our hard work
We'll use hexadecimal, to not go berserk
For checksums thus displayed, are easiest to compare
And to check for errors, much easier to dare

So here it is, my love, my gift to you
A checksum calculator, so unique and true
May it bring you happiness, and ease your mind
And protect our data, so true and kind */

#include <stdio.h>
#include <string.h>

unsigned int calculate_checksum(char* str) {
    int len = strlen(str);
    unsigned int sum = 0;
    for(int i=0; i<len; i++) {
        sum += (unsigned int) str[i];
    }
    return (sum >> 16) + (sum & 0xFFFF);
}

int main() {
    char input[100];
    printf("My Juliet, please enter a string: ");
    fgets(input, 100, stdin);
    printf("The checksum of thy string is: %X\n", calculate_checksum(input));
    return 0;
}
//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

int main(){
    char input[100];
    int sum = 0;
    printf("Greetings noble knight! Please enter the message you want to calculate the checksum for:\n");
    fgets(input, 100, stdin);
    printf("Your message is:\n%s", input);
    for(int i = 0; i < strlen(input) - 1; i++){ //subtracting 1 to remove the newline character
        sum += (int)(input[i]) * (i + 1);
    }
    printf("The checksum of your message is: %d\n", sum);
    printf("Thank you for using our checksum calculator!\n");
    return 0;
}
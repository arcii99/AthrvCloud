//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include<stdio.h>
#include<string.h>

char stack[100];
int top=-1;

void push(char x) {
    stack[++top]=x;
}

char pop() {
    if(top==-1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    char str[100];
    int len,i=0,j=0;

    printf("Enter a string: ");
    scanf("%s",str);

    len=strlen(str);

    for(i=0;i<len;i++) {
        push(str[i]);
    }

    for(i=0;i<len;i++) {
        if(str[i]==pop()) {
            j++;
        }
    }

    if(j==len) {
        printf("\nThe string is a palindrome.");
    } else {
        printf("\nThe string is not a palindrome.");
    }

    return 0;
}
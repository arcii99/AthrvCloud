//FormAI DATASET v1.0 Category: Text processing ; Style: Cryptic
#include<stdio.h>
int main() {
    char msg[] = "KpyIlg Lvmw Xrksvi?";
    int key = 19;
    printf("\t\t\t\t\tDecrypt Your Message\n");
    for(int i=0; msg[i]!='\0'; ++i) {
        char c = msg[i];
        if(c >= 'a' && c <= 'z') {
            c += key;
            if(c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            msg[i] = c;
        }
        else if(c >= 'A' && c <= 'Z') {
            c += key;
            if(c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            msg[i] = c;
        }
    }
    printf("\nYour decrypted message is: %s", msg);
    printf("\n\nCongratulations! You have decrypted the message successfully!");
    return 0;
}
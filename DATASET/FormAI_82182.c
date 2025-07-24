//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int i = 0, wifi_strength = 0;
    char key[] = {'W', 'I', 'F', 'I', '_', 'S', 'T', 'R', 'E', 'N', 'G', 'T', 'H', '\0'};
    char password[] = {'1','2','3','4','5','6','7','8','9','0','\0'};
    char pass[30];
    printf("Enter the password:");
    scanf("%s", pass);

    if(strcmp(pass, password) != 0) {
        printf("Incorrect password, access denied.\n");
        return 0;
    }

    printf("\nAnalyzing WiFi Signal Strength...\n\n");
    for(i=0; i<strlen(key); i++) {
        wifi_strength += (int)key[i];
    }
    if(wifi_strength > 1000) {
        printf("Strong Wi-Fi signal strength detected.\n");
    }
    else if(wifi_strength > 500 && wifi_strength <= 1000) {
        printf("Moderate Wi-Fi signal strength detected.\n");
    }
    else {
        printf("Weak Wi-Fi signal strength detected.\n");
    }
    return 0;
}
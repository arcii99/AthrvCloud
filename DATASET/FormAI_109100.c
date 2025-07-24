//FormAI DATASET v1.0 Category: Browser Plugin ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char city[50];
    char url[200];
    printf("Enter your city name: ");
    scanf("%[^\n]s", city);
    sprintf(url, "https://api.openweathermap.org/data/2.5/weather?q=%s&appid=API_KEY_HERE", city);
    printf("%s\n", url);
    return 0;
}
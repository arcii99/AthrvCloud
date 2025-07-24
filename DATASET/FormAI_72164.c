//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include<stdio.h>
#include<string.h>

const char *COLORS[] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
const char *CODES[] = {"\033[0;30m", "\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m", "\033[0;37m"};

int colorToCode(const char *color) {
    for(int i=0; i<8; i++) {
        if(strcmp(COLORS[i], color) == 0) {
            return i;
        }
    }
    return -1; //invalid color
}

void printColor(const char *color) {
    int code = colorToCode(color);
    if(code == -1) {
        printf("Invalid color specified\n");
    } else {
        printf("%s", CODES[code]);
    }
}

int main() {
    char color[20];
    printf("Enter color name: ");
    scanf("%s", color);
    printColor(color);
    printf("This text should be in the color: %sHello World\033[0m\n", CODES[colorToCode(color)]);
    return 0;
}
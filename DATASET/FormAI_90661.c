//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Claude Shannon
#include <stdio.h>

void print_a(){
    printf("        /\\\n");
    printf("       //\\\\\n");
    printf("      //  \\\\\\n");
    printf("     //    \\\\\\\n");
    printf("    //======\\\\\n");
    printf("   //        \\\\\n");
    printf("  //          \\\\\n");
    printf(" //            \\\\\n");
}

void print_b(){
    printf("  ______\n");
    printf(" |      \\\n");
    printf(" |       |\n");
    printf(" |______/\n");
    printf(" |      \\\n");
    printf(" |___    |\n");
    printf("     |___/\n");
}

void print_c(){
    printf("    ___\n");
    printf("  /    \\\n");
    printf(" |      \\\n");
    printf(" |       |\n");
    printf(" |      /\n");
    printf("  \\__/\n");
}

void print_space(){
    printf("     \n");
    printf("     \n");
    printf("     \n");
    printf("     \n");
    printf("     \n");
    printf("     \n");
    printf("     \n");
}

void convert_to_ascii(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        switch(str[i]){
            case 'a':
                print_a();
                break;
            case 'b':
                print_b();
                break;
            case 'c':
                print_c();
                break;
            default:
                print_space();
                break;
        }
    }
}

int main(){
    char *text = "abc abc";
    convert_to_ascii(text);
    return 0;
}
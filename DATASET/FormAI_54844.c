//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void printAsciiArt(char input[]){
    int length = strlen(input);
    int i, j, k, l;

    for(i=0; i<length; i++){
        if(input[i] == 'A' || input[i] == 'a'){
            for(j=0; j<5; j++){
                if(j == 2){
                    printf(" ##### ");
                }
                else{
                    printf("#     #");
                }
                printf("\n");
            }
        }
        if(input[i] == 'B' || input[i] == 'b'){
            for(j=0; j<5; j++){
                printf("###### \n");
                if(j == 2){
                    printf("#     #\n");
                }
                else{
                    printf("#     #\n");
                }
                printf("###### \n");
            }
        }
        if(input[i] == 'C' || input[i] == 'c'){
            for(j=0; j<5; j++){
                printf(" ######\n");
                printf("#      \n");
                printf("#      \n");
                printf(" ######\n");
            }
        }
        if(input[i] == 'D' || input[i] == 'd'){
            for(j=0; j<5; j++){
                printf("###### \n");
                printf("#     #\n");
                if(j == 2){
                    printf("#     #\n");
                }
                else{
                    printf("#     #\n");
                }
                printf("###### \n");
            }
        }
        if(input[i] == 'E' || input[i] == 'e'){
            for(j=0; j<5; j++){
                printf("######\n");
                printf("#      \n");
                if(j == 2){
                    printf("######\n");
                }
                else{
                    printf("#      \n");
                }
                printf("######\n");
            }
        }
        if(input[i] == 'F' || input[i] == 'f'){
            for(j=0; j<5; j++){
                printf("######\n");
                printf("#      \n");
                if(j == 2){
                    printf("######\n");
                }
                else{
                    printf("#      \n");
                }
                printf("#      \n");
            }
        }
        if(input[i] == 'G' || input[i] == 'g'){
            for(j=0; j<5; j++){
                printf(" ######\n");
                printf("#      \n");
                printf("#   ###\n");
                printf(" ##### \n");
            }
        }
        if(input[i] == 'H' || input[i] == 'h'){
            for(j=0; j<5; j++){
                printf("#     #\n");
                printf("#     #\n");
                if(j == 2){
                    printf("###### \n");
                }
                else{
                    printf("#     #\n");
                }
                printf("#     #\n");
            }
        }
        if(input[i] == 'I' || input[i] == 'i'){
            for(j=0; j<5; j++){
                printf("######\n");
                printf("  ##  \n");
                printf("  ##  \n");
                printf("######\n");
            }
        }
        if(input[i] == 'J' || input[i] == 'j'){
            for(j=0; j<5; j++){
                printf("######\n");
                printf("   ## \n");
                printf("   ## \n");
                printf("####  \n");
            }
        }
        if(input[i] == 'K' || input[i] == 'k'){
            for(j=0; j<5; j++){
                printf("#   ##\n");
                printf("#  ## \n");
                if(j == 2){
                    printf("###   \n");
                }
                else{
                    printf("##    \n");
                }
                printf("#  ## \n");
            }
        }
        if(input[i] == 'L' || input[i] == 'l'){
            for(j=0; j<5; j++){
                printf("#      \n");
                printf("#      \n");
                printf("#      \n");
                printf("######\n");
            }
        }
        if(input[i] == 'M' || input[i] == 'm'){
            for(j=0; j<5; j++){
                printf("#     #\n");
                printf("##   ##\n");
                if(j == 2){
                    printf("# # # #\n");
                }
                else{
                    printf("#  #  #\n");
                }
                printf("#     #\n");
            }
        }
        if(input[i] == 'N' || input[i] == 'n'){
            for(j=0; j<5; j++){
                printf("#     #\n");
                printf("##    #\n");
                if(j == 2){
                    printf("# #   #\n");
                }
                else{
                    printf("#  #  #\n");
                }
                printf("#   ## \n");
            }
        }
        if(input[i] == 'O' || input[i] == 'o'){
            for(j=0; j<5; j++){
                printf(" ##### \n");
                printf("#     #\n");
                printf("#     #\n");
                printf(" ##### \n");
            }
        }
        if(input[i] == 'P' || input[i] == 'p'){
            for(j=0; j<5; j++){
                printf("###### \n");
                printf("#     #\n");
                if(j == 2){
                    printf("###### \n");
                }
                else{
                    printf("#####  \n");
                }
                printf("#      \n");
            }
        }
        if(input[i] == 'Q' || input[i] == 'q'){
            for(j=0; j<5; j++){
                if(j == 0 || j == 4){
                    printf(" ##### \n");
                }
                else{
                    printf("#     #\n");
                }
                if(j == 3){
                    printf("   ##  \n");
                }
                else if(j == 4){
                    printf("  ###  \n");
                }
                else{
                    printf(" #   # \n");
                }
            }
        }
        if(input[i] == 'R' || input[i] == 'r'){
            for(j=0; j<5; j++){
                printf("###### \n");
                printf("#     #\n");
                if(j == 2){
                    printf("###### \n");
                }
                else{
                    printf("#   #  \n");
                }
                printf("#    # \n");
            }
        }
        if(input[i] == 'S' || input[i] == 's'){
            for(j=0; j<5; j++){
                if(j == 0 || j == 4){
                    printf(" ##### \n");
                }
                else if(j == 1 || j == 3){
                    printf("#      \n");
                }
                else{
                    printf(" ##### \n");
                }
                if(j == 1){
                    printf("      #\n");
                }
                else if(j == 3){
                    printf("#      \n");
                }
                else{
                    printf(" ##### \n");
                }
            }
        }
        if(input[i] == 'T' || input[i] == 't'){
            for(j=0; j<5; j++){
                printf("######\n");
                printf("  ##  \n");
                printf("  ##  \n");
                if(j == 0){
                    printf("  ##  \n");
                }
                else{
                    printf(" #####\n");
                }
            }
        }
        if(input[i] == 'U' || input[i] == 'u'){
            for(j=0; j<5; j++){
                printf("#     #\n");
                printf("#     #\n");
                printf("#     #\n");
                printf(" ##### \n");
            }
        }
        if(input[i] == 'V' || input[i] == 'v'){
            for(j=0; j<5; j++){
                printf("#     #\n");
                printf("#     #\n");
                printf(" #   # \n");
                if(j == 3){
                    printf("  # #  \n");
                }
                else{
                    printf("   #   \n");
                }
            }
        }
        if(input[i] == 'W' || input[i] == 'w'){
            for(j=0; j<5; j++){
                printf("#     #\n");
                printf("#  #  #\n");
                if(j == 2){
                    printf("#  #  #\n");
                }
                else{
                    printf("#  #  #\n");
                }
                printf(" ## ## \n");
            }
        }
        if(input[i] == 'X' || input[i] == 'x'){
            for(j=0; j<5; j++){
                if(j == 0 || j == 4){
                    printf("#     #\n");
                }
                else if(j == 1 || j == 3){
                    printf(" #   # \n");
                }
                else{
                    printf("  ###  \n");
                }
            }
        }
        if(input[i] == 'Y' || input[i] == 'y'){
            for(j=0; j<5; j++){
                if(j == 0 || j == 1){
                    printf("#     #\n");
                }
                else if(j == 2){
                    printf(" ##### \n");
                }
                else{
                    printf("   #   \n");
                }
                if(j == 3){
                    printf("  #    \n");
                }
                else if(j == 4){
                    printf(" ##### \n");
                }
                else{
                    printf("   #   \n");
                }
            }
        }
        if(input[i] == 'Z' || input[i] == 'z'){
            for(j=0; j<5; j++){
                printf("######\n");
                if(j == 1){
                    printf("    # \n");
                }
                else if(j == 2){
                    printf("   #  \n");
                }
                else if(j == 3){
                    printf("  #   \n");
                }
                else{
                    printf("######\n");
                }
            }
        }
        printf("\n");
    }
}

int main(){
    char input[100];
    printf("Enter the string (in uppercase letters): ");
    scanf("%s", input);

    printAsciiArt(input);

    return 0;
}
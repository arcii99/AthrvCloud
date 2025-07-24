//FormAI DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include <stdio.h>
int main()
{
    char inputString[100];
    char currentChar;
    int state = 0, index = 0, isSyntaxCorrect = 1;
    printf("Enter your C syntax: ");
    fgets(inputString, 100, stdin);
    currentChar = inputString[index];
    while(currentChar != '\n' && isSyntaxCorrect)
    {
        switch(state)
        {
            case 0: // initial state
                if(currentChar == 'i')
                    state = 1;
                else if(currentChar == 'f')
                    state = 4;
                else if(currentChar == 'w')
                    state = 7;
                else if(currentChar == 'e')
                    state = 9;
                else if(currentChar == 'd')
                    state = 13;
                else if(currentChar == 's')
                    state = 16;
                else
                    isSyntaxCorrect = 0;
                break;
            case 1: // expecting 'n'
                if(currentChar == 'n')
                    state = 2;
                else
                    isSyntaxCorrect = 0;
                break;
            case 2: // expecting 't'
                if(currentChar == 't')
                    state = 3;
                else
                    isSyntaxCorrect = 0;
                break;
            case 3: // expecting '('
                if(currentChar == '(')
                    state = 0;
                else
                    isSyntaxCorrect = 0;
                break;
            case 4: // expecting 'o'
                if(currentChar == 'o')
                    state = 5;
                else
                    isSyntaxCorrect = 0;
                break;
            case 5: // expecting 'r'
                if(currentChar == 'r')
                    state = 6;
                else
                    isSyntaxCorrect = 0;
                break;
            case 6: // expecting '('
                if(currentChar == '(')
                    state = 0;
                else
                    isSyntaxCorrect = 0;
                break;
            case 7: // expecting 'h'
                if(currentChar == 'h')
                    state = 8;
                else
                    isSyntaxCorrect = 0;
                break;
            case 8: // expecting 'i'
                if(currentChar == 'i')
                    state = 3;
                else
                    isSyntaxCorrect = 0;
                break;
            case 9: // expecting 'l'
                if(currentChar == 'l')
                    state = 10;
                else if(currentChar == 'n')
                    state = 12;
                else
                    isSyntaxCorrect = 0;
                break;
            case 10: // expecting 's'
                if(currentChar == 's')
                    state = 11;
                else
                    isSyntaxCorrect = 0;
                break;
            case 11: // expecting 'e'
                if(currentChar == 'e')
                    state = 3;
                else
                    isSyntaxCorrect = 0;
                break;
            case 12: // expecting '('
                if(currentChar == '(')
                    state = 0;
                else
                    isSyntaxCorrect = 0;
                break;
            case 13: // expecting 'e'
                if(currentChar == 'e')
                    state = 14;
                else
                    isSyntaxCorrect = 0;
                break;
            case 14: // expecting 'f'
                if(currentChar == 'f')
                    state = 15;
                else
                    isSyntaxCorrect = 0;
                break;
            case 15: // expecting '('
                if(currentChar == '(')
                    state = 0;
                else
                    isSyntaxCorrect = 0;
                break;
            case 16: // expecting 't'
                if(currentChar == 't')
                    state = 17;
                else
                    isSyntaxCorrect = 0;
                break;
            case 17: // expecting 'r'
                if(currentChar == 'r')
                    state = 18;
                else
                    isSyntaxCorrect = 0;
                break;
            case 18: // expecting 'c'
                if(currentChar == 'c')
                    state = 19;
                else
                    isSyntaxCorrect = 0;
                break;
            case 19: // expecting 'm'
                if(currentChar == 'm')
                    state = 20;
                else
                    isSyntaxCorrect = 0;
                break;
            case 20: // expecting 'p'
                if(currentChar == 'p')
                    state = 21;
                else
                    isSyntaxCorrect = 0;
                break;
            case 21: // expecting ')'
                if(currentChar == ')')
                    state = 0;
                else
                    isSyntaxCorrect = 0;
                break;
        }
        index++;
        currentChar = inputString[index];
    }
    if(state == 0 && isSyntaxCorrect)
        printf("Congratulations! Your C syntax is correct.\n");
    else
        printf("Sorry, your C syntax is incorrect.\n");
    return 0;
}
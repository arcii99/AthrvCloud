//FormAI DATASET v1.0 Category: Syntax parsing ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold token information
typedef struct TokenInfo{
    char token[50]; // The token
    int line; // Line number of the token
    int type; // Token type (1 = identifier, 2 = number, 3 = operator, 4 = delimiter)
}TokenInfo;

// Structure to hold syntax tree node information
typedef struct SyntaxTreeNode{
    char nodeValue[50]; // The value of the node in the syntax tree
    struct SyntaxTreeNode* leftChild; // Pointer to left child of node
    struct SyntaxTreeNode* rightChild; // Pointer to right child of node
}SyntaxTreeNode;

// Function to determine if a token is an identifier
int isIdentifier(char* token){
    // Check if first character is a letter or underscore
    if((token[0]>='a' && token[0]<='z') || (token[0]>='A' && token[0]<='Z') || token[0]=='_'){
        // Check if all remaining characters are letters, digits, or underscores
        for(int i=1;i<strlen(token);i++){
            if(!((token[i]>='a' && token[i]<='z') || (token[i]>='A' && token[i]<='Z') || (token[i]>='0' && token[i]<='9') || token[i]=='_')){
                return 0; // Not a valid identifier
            }
        }
        return 1; // Valid identifier
    }
    return 0; // Not a valid identifier
}

// Function to determine if a token is a number
int isNumber(char* token){
    // Check if all characters are digits
    for(int i=0;i<strlen(token);i++){
        if(!(token[i]>='0' && token[i]<='9')){
            return 0; // Not a valid number
        }
    }
    return 1; // Valid number
}

// Function to determine if a token is an operator
int isOperator(char* token){
    if(strlen(token)==1){ // Check if token is one character long
        char operators[] = "+-*/%><="; // List of valid operators
        for(int i=0;i<strlen(operators);i++){
            if(operators[i]==token[0]){
                return 1; // Valid operator
            }
        }
    }
    else if(strlen(token)==2){ // Check if token is two characters long
        char operators[] = "+-*/%><="; // List of valid operators
        char combinations[][3] = {"+=", "-=", "*=", "/=", "%=", "==", "!=",
                                    ">=", "<="}; // List of valid two-character operator combinations
        for(int i=0;i<sizeof(combinations)/sizeof(combinations[0]);i++){
            if(strcmp(combinations[i], token)==0){
                return 1; // Valid operator
            }
        }
    }
    return 0; // Not a valid operator
}

// Function to determine if a token is a delimiter
int isDelimiter(char* token){
    char delimiters[] = "(){}[],;"; // List of valid delimiters
    for(int i=0;i<strlen(delimiters);i++){
        if(token[0]==delimiters[i]){
            return 1; // Valid delimiter
        }
    }
    return 0; // Not a valid delimiter
}

// Function to tokenize input program and store tokens in array of TokenInfo structures
int tokenizeProgram(char* program, TokenInfo* tokens){
    char* token = strtok(program, " \t\r\n"); // Tokenize by whitespace characters
    int tokenCount = 0;
    while(token!=NULL){
        strcpy(tokens[tokenCount].token, token); // Copy token to TokenInfo structure
        tokens[tokenCount].line = 1; // For simplicity, all tokens are on line 1
        if(isIdentifier(token)){
            tokens[tokenCount].type = 1; // Token is an identifier
        }
        else if(isNumber(token)){
            tokens[tokenCount].type = 2; // Token is a number
        }
        else if(isOperator(token)){
            tokens[tokenCount].type = 3; // Token is an operator
        }
        else if(isDelimiter(token)){
            tokens[tokenCount].type = 4; // Token is a delimiter
        }
        else{
            printf("Error: Invalid token '%s'\n", token); // Token is not a valid identifier, number, operator, or delimiter
            exit(1);
        }
        token = strtok(NULL, " \t\r\n"); // Get next token
        tokenCount++; // Keep track of number of tokens
    }
    return tokenCount; // Return number of tokens
}

// Function to recursively build a syntax tree from an array of tokens
SyntaxTreeNode* buildSyntaxTree(TokenInfo* tokens, int start, int end){
    SyntaxTreeNode* node = (SyntaxTreeNode*)malloc(sizeof(SyntaxTreeNode)); // Allocate memory for node
    if(start==end){ // If start and end of range are equal, then this node is a leaf
        strcpy(node->nodeValue, tokens[start].token); // Value of leaf node is the token
        node->leftChild = NULL; // No left child
        node->rightChild = NULL; // No right child
        return node; // Return leaf node
    }
    else{ // If start and end of range are not equal, then this node is an operator
        int opCount = 0; // Keep track of number of operator tokens in range
        int minPrecedence = 100; // Variable to store minimum precedence found so far
        int minIndex = -1; // Variable to store index of token with minimum precedence
        for(int i=start;i<=end;i++){ // Loop through range of tokens
            if(tokens[i].type==3){ // If token is an operator, increment opCount
                opCount++;
                int precedence;
                if(tokens[i].token[0]=='+' || tokens[i].token[0]=='-'){ // Add special handling for + or - operator, which can also be unary
                    if(i==start || tokens[i-1].type==3){ // If + or - operator is at start of range or is preceded by an operator, it is unary
                        precedence = 6; // Unary + and - have highest precedence (i.e. lowest value)
                    }
                    else{ // Otherwise, it is binary
                        precedence = 2; // Binary + and - have lower precedence than *, /, and %
                    }
                }
                else if(tokens[i].token[0]=='*' || tokens[i].token[0]=='/' || tokens[i].token[0]=='%'){ // For * or / or % operators
                    precedence = 3; // * and / and % have higher precedence than + and -
                }
                else{ // For all other operators
                    precedence = 4; // > and < and = have lower precedence than * and / and %
                }
                if(precedence<=minPrecedence){ // If current token has equal or lower precedence than minimum found so far
                    minPrecedence = precedence; // Update minimum precedence
                    minIndex = i; // Update index of token with minimum precedence
                }
            }
        }
        if(opCount==0){ // No operator tokens found in range
            return buildSyntaxTree(tokens, start+1, end-1); // recursively build a syntax tree with the interior of parentheses
        }
        else{
            node->leftChild = buildSyntaxTree(tokens, start, minIndex-1); // Recursively build left subtree of node
            node->rightChild = buildSyntaxTree(tokens, minIndex+1, end); // Recursively build right subtree of node
            strcpy(node->nodeValue, tokens[minIndex].token); // Value of operator node is the operator token
            return node; // Return operator node
        }
    }
}

// Function to print syntax tree in infix notation
void printSyntaxTree(SyntaxTreeNode* root){
    if(root->leftChild==NULL && root->rightChild==NULL){ // If this is a leaf node
        printf("%s", root->nodeValue); // Print leaf value
    }
    else{
        printf("("); // Print opening parenthesis
        printSyntaxTree(root->leftChild); // Recursively print left subtree
        printf("%s", root->nodeValue); // Print operator value
        printSyntaxTree(root->rightChild); // Recursively print right subtree
        printf(")"); // Print closing parenthesis
    }
}

int main(){
    char program[] = "x = 1+\n2*(3-4)/5;"; // Input program
    TokenInfo tokens[50]; // Array to hold tokens
    int tokenCount = tokenizeProgram(program, tokens); // Tokenize input program and get number of tokens
    SyntaxTreeNode* root = buildSyntaxTree(tokens, 0, tokenCount-1); // Build syntax tree from tokens
    printSyntaxTree(root); // Print syntax tree
    return 0;
}
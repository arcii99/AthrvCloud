//FormAI DATASET v1.0 Category: Syntax parsing ; Style: protected
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_SYMBOL_TABLE_SIZE 100

typedef enum {
    nulsym = 1, identsym, numbersym, plussym, minussym, multsym,  slashsym ,
    oddsym, eqlsym, neqsym, lessym, leqsym, gtrsym, geqsym, lparentsym, rparentsym,
    commasym, semicolonsym, periodsym, becomessym, beginsym, endsym, ifsym, thensym,
    whilesym, dosym, callsym, constsym, varsym, procsym, writesym, readsym , elsesym
} token_type;

typedef struct {
    int kind;
    char name[MAX_TOKEN_LENGTH];
    int val;
} symbol;

int sym_count = 0;
symbol symbol_table[MAX_SYMBOL_TABLE_SIZE];
char source_code[MAX_TOKEN_LENGTH];
int code_index = 0;
int line_num = 1;

void print_error(char* error_message){
    printf("Error (line %d): %s\n", line_num, error_message);
    exit(1);
}

void add_symbol(int type, char* name, int value){
    if(sym_count == MAX_SYMBOL_TABLE_SIZE){
        print_error("Symbol table full.");
    }
    symbol new_symbol;
    new_symbol.kind = type;
    strncpy(new_symbol.name, name, MAX_TOKEN_LENGTH - 1);
    new_symbol.val = value;
    symbol_table[sym_count] = new_symbol;
    sym_count++;
}

void remove_comments(){
    int current_index = 0;
    int source_length = strlen(source_code);
    char new_source[MAX_TOKEN_LENGTH];
    int new_index = 0;
    while(current_index < source_length){
        if(source_code[current_index] == '/'){
            if(current_index + 1 >= source_length){
                print_error("Invalid comment.");
            }
            if(source_code[current_index + 1] == '*'){
                current_index += 2;
                while(current_index < source_length && !(source_code[current_index] == '*' && 
                        source_code[current_index+1] == '/')){
                    if(source_code[current_index] == '\n'){
                        line_num++;
                    }
                    current_index++;
                }
                if(current_index >= source_length){
                    print_error("Invalid comment.");
                }
                current_index += 2;
                continue;
            }
            else if(source_code[current_index + 1] == '/'){
                while(current_index < source_length && source_code[current_index] != '\n'){
                    current_index++;
                }
                if(current_index >= source_length){
                    break;
                }
                continue;
            }
        }
        new_source[new_index] = source_code[current_index];
        current_index++;
        new_index++;
    }
    new_source[new_index] = '\0';
    strncpy(source_code, new_source, strlen(new_source));
}

int parse_number(){
    char number_string[MAX_TOKEN_LENGTH];
    int index = 0;
    while(isdigit(source_code[code_index]) && index < MAX_TOKEN_LENGTH){
        number_string[index] = source_code[code_index];
        code_index++;
        index++;
    }
    number_string[index] = '\0';
    if(index == MAX_TOKEN_LENGTH){
        print_error("Number too long.");
    }
    return atoi(number_string);
}

int parse_word(){
    char word_string[MAX_TOKEN_LENGTH];
    int index = 0;
    while(isalnum(source_code[code_index]) && index < MAX_TOKEN_LENGTH){
        word_string[index] = source_code[code_index];
        code_index++;
        index++;
    }
    word_string[index] = '\0';
    if(index == MAX_TOKEN_LENGTH){
        print_error("Identifier too long.");
    }
    if(strcmp(word_string, "const") == 0){
        return constsym;
    }
    else if(strcmp(word_string, "var") == 0){
        return varsym;
    }
    else if(strcmp(word_string, "procedure") == 0){
        return procsym;
    }
    else if(strcmp(word_string, "call") == 0){
        return callsym;
    }
    else if(strcmp(word_string, "begin") == 0){
        return beginsym;
    }
    else if(strcmp(word_string, "end") == 0){
        return endsym;
    }
    else if(strcmp(word_string, "if") == 0){
        return ifsym;
    }
    else if(strcmp(word_string, "then") == 0){
        return thensym;
    }
    else if(strcmp(word_string, "else") == 0){
        return elsesym;
    }
    else if(strcmp(word_string, "while") == 0){
        return whilesym;
    }
    else if(strcmp(word_string, "do") == 0){
        return dosym;
    }
    else if(strcmp(word_string, "read") == 0){
        return readsym;
    }
    else if(strcmp(word_string, "write") == 0){
        return writesym;
    }
    else if(strcmp(word_string, "odd") == 0){
        return oddsym;
    }
    return identsym;
}

int get_token(){
    if(source_code[code_index] == '\0'){
        return 0;
    }
    while(isspace(source_code[code_index])){
        if(source_code[code_index] == '\n'){
            line_num++;
        }
        code_index++;
    }
    if(isdigit(source_code[code_index])){
        return numbersym;
    }
    else if(isalpha(source_code[code_index])){
        return parse_word();
    }
    else if(source_code[code_index] == ':'){
        if(code_index+1 < strlen(source_code) && source_code[code_index+1] == '='){
            code_index += 2;
            return becomessym;
        }
        else{
            code_index++;
            print_error("Invalid token.");
        }
    }
    else if(source_code[code_index] == '<'){
        if(code_index+1 < strlen(source_code) && source_code[code_index+1] == '='){
            code_index += 2;
            return leqsym;
        }
        else if(code_index+1 < strlen(source_code) && source_code[code_index+1] == '>'){
            code_index += 2;
            return neqsym;
        }
        else{
            code_index++;
            return lessym;
        }
    }
    else if(source_code[code_index] == '>'){
        if(code_index+1 < strlen(source_code) && source_code[code_index+1] == '='){
            code_index += 2;
            return geqsym;
        }
        else{
            code_index++;
            return gtrsym;
        }
    }
    switch(source_code[code_index]){
        case '+':
            code_index++;
            return plussym;
        case '-':
            code_index++;
            return minussym;
        case '*':
            code_index++;
            return multsym;
        case '/':
            code_index++;
            return slashsym;
        case '(':
            code_index++;
            return lparentsym;
        case ')':
            code_index++;
            return rparentsym;
        case '=':
            code_index++;
            return eqlsym;
        case ',':
            code_index++;
            return commasym;
        case '.':
            code_index++;
            return periodsym;
        case ';':
            code_index++;
            return semicolonsym;
        default:
            print_error("Invalid token.");
    }
    return -1;
}

int parse_factor();

int parse_expression(){
    int result = parse_factor();
    while(get_token() == plussym || get_token() == minussym){
        int token = get_token();
        if(token == plussym){
            result += parse_factor();
        }
        else{
            result -= parse_factor();
        }
    }
    code_index--;
    return result;
}

int parse_term(){
    int result = parse_factor();
    while(get_token() == multsym || get_token() == slashsym){
        int token = get_token();
        if(token == multsym){
            result *= parse_factor();
        }
        else{
            int divisor = parse_factor();
            if(divisor == 0){
                print_error("Can't divide by zero.");
            }
            result /= divisor;
        }
    }
    code_index--;
    return result;
}

int parse_factor(){
    int token = get_token();
    if(token == numbersym){
        return parse_number();
    }
    else if(token == lparentsym){
        int result = parse_expression();
        if(get_token() != rparentsym){
            print_error("Expected right parenthesis.");
        }
        return result;
    }
    else if(token == identsym){
        char identifier[MAX_TOKEN_LENGTH];
        strncpy(identifier, symbol_table[code_index-1].name, MAX_TOKEN_LENGTH - 1);
        int kind = symbol_table[code_index-1].kind;
        if(kind != identsym && kind != numbersym){
            print_error("Can't use this symbol in expression.");
        }
        if(get_token() == lparentsym){
            if(kind != procsym){
                print_error("Can only call procedures.");
            }
            int result = 0;
            while(get_token() != rparentsym){
                if(kind != varsym){
                    print_error("Can only pass variables as arguments.");
                }
                int index = code_index-2;
                while(index >= 0 && symbol_table[index].kind != procsym){
                    if(symbol_table[index].kind == identsym && 
                       strncmp(symbol_table[index].name, source_code+code_index, MAX_TOKEN_LENGTH-1) == 0){
                        break;
                    }
                    index--;
                }
                if(index < 0){
                    print_error("Can't find procedure to call.");
                }
                result = symbol_table[index].val;
            }
            return result;
        }
        code_index--;
        return symbol_table[code_index].val;
    }
    else if(token == plussym || token == minussym){
        if(token == minussym){
            return -parse_factor();
        }
        return parse_factor();
    }
    else{
        print_error("Invalid factor.");
    }
    return -1;
}

int main(){
    printf("Enter source code:\n");
    fgets(source_code, MAX_TOKEN_LENGTH, stdin);
    remove_comments();
    while(get_token()){
        if(get_token() != constsym && get_token() != varsym && get_token() != procsym){
            print_error("Expected const, var, or procedure.");
        }
        int kind = get_token();
        if(kind == procsym){
            add_symbol(kind, NULL, -1);
            continue;
        }
        do {
            if(get_token() != identsym){
                print_error("Expected identifier.");
            }
            char name[MAX_TOKEN_LENGTH];
            strncpy(name, symbol_table[code_index-1].name, MAX_TOKEN_LENGTH - 1);
            int value = 0;
            if(get_token() == eqlsym){
                value = parse_expression();
            }
            else{
                code_index--;
            }
            add_symbol(kind, name, value);
        } while(get_token() == commasym);
        if(get_token() != semicolonsym){
            print_error("Expected semicolon.");
        }
    }
}
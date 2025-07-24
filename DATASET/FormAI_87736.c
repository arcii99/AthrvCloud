//FormAI DATASET v1.0 Category: Arithmetic ; Style: introspective
#include<stdio.h>
int main() {
    /* Introspective C Program: "The Self-Assessing Calculator" */
    
    printf("Hey there! I am a self-assessing calculator.\n");
    printf("I can perform arithmetic operations like addition, subtraction, multiplication and division.\n");
    printf("I can also evaluate some expressions containing parenthesis.\n");
    printf("So, let's get started!\n");
    
    char choice;
    float num1, num2;
    
    while(1) {
        printf("\nEnter 'Q' to quit.\n");
        printf("Enter '+' for addition.\n");
        printf("Enter '-' for subtraction.\n");
        printf("Enter '*' for multiplication.\n");
        printf("Enter '/' for division.\n");
        printf("Enter 'E' for expression evaluation.\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        if(choice == 'Q') {
            printf("Goodbye!\n");
            break;
        }
        
        switch(choice) {
            
            case '+':
                printf("\nEnter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
                break;
                
            case '-':
                printf("\nEnter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
                break;
                
            case '*':
                printf("\nEnter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
                break;
                
            case '/':
                printf("\nEnter two numbers separated by a space: ");
                scanf("%f %f", &num1, &num2);
                
                if(num2 != 0) {
                    printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
                } else {
                    printf("Cannot divide by zero!\n");
                }
                break;
                
            case 'E':
                printf("\nEnter an expression containing parenthesis: ");
                char exp[50];
                scanf(" %[^\n]", exp);
                
                float res = 0;
                char op = '+';
                
                for(int i=0; exp[i]!='\0'; i++) {
                    
                    if(exp[i] == '(') {
                        
                        int j = i+1, count = 1;
                        
                        while(exp[j]!='\0') {
                            if(exp[j] == '(') count++;
                            if(exp[j] == ')') count--;
                            if(count == 0) break;
                            j++;
                        }
                        
                        char subexp[50];
                        int k = 0;
                        
                        for(int l=i+1; l<j; l++) {
                            subexp[k++] = exp[l];
                        }
                        subexp[k] = '\0';
                        
                        float subres = 0;
                        
                        for(int l=0; subexp[l]!='\0'; l++) {
                            
                            if(subexp[l] == '(') {
                                
                                int m = l+1, count = 1;
                                
                                while(subexp[m]!='\0') {
                                    if(subexp[m] == '(') count++;
                                    if(subexp[m] == ')') count--;
                                    if(count == 0) break;
                                    m++;
                                }
                                
                                char subsubexp[50];
                                int n = 0;
                                
                                for(int o=l+1; o<m; o++) {
                                    subsubexp[n++] = subexp[o];
                                }
                                subsubexp[n] = '\0';
                                
                                float subsubres = 0;
                                
                                for(int o=0; subsubexp[o]!='\0'; o++) {
                                    
                                    if(subsubexp[o]>='0' && subsubexp[o]<='9') {
                                        int p = o+1;
                                        while(subsubexp[p]>='0' && subsubexp[p]<='9') {
                                            p++;
                                        }
                                        char subsubnum[10];
                                        int q = 0;
                                        for(int r=o; r<p; r++) {
                                            subsubnum[q++] = subsubexp[r];
                                        }
                                        subsubnum[q] = '\0';
                                        float subsubnumval = atof(subsubnum);
                                        if(op == '+') {
                                            subsubres += subsubnumval;
                                        } else if(op == '-') {
                                            subsubres -= subsubnumval;
                                        } else if(op == '*') {
                                            subsubres *= subsubnumval;
                                        } else if(op == '/') {
                                            subsubres /= subsubnumval;
                                        }
                                        o = p-1;
                                    } else if(subsubexp[o] == '+' || subsubexp[o] == '-' || subsubexp[o] == '*' || subsubexp[o] == '/') {
                                        op = subsubexp[o];
                                    }
                                }
                                
                                if(op == '+') {
                                    subres += subsubres;
                                } else if(op == '-') {
                                    subres -= subsubres;
                                } else if(op == '*') {
                                    subres *= subsubres;
                                } else if(op == '/') {
                                    subres /= subsubres;
                                }
                                l = m-1;
                                
                            } else if(subexp[l]>='0' && subexp[l]<='9') {
                                int p = l+1;
                                while(subexp[p]>='0' && subexp[p]<='9') {
                                    p++;
                                }
                                char subnum[10];
                                int q = 0;
                                for(int r=l; r<p; r++) {
                                    subnum[q++] = subexp[r];
                                }
                                subnum[q] = '\0';
                                float subnumval = atof(subnum);
                                if(op == '+') {
                                    subres += subnumval;
                                } else if(op == '-') {
                                    subres -= subnumval;
                                } else if(op == '*') {
                                    subres *= subnumval;
                                } else if(op == '/') {
                                    subres /= subnumval;
                                }
                                l = p-1;
                            } else if(subexp[l] == '+' || subexp[l] == '-' || subexp[l] == '*' || subexp[l] == '/') {
                                op = subexp[l];
                            }
                        }
                        if(op == '+') {
                            res += subres;
                        } else if(op == '-') {
                            res -= subres;
                        } else if(op == '*') {
                            res *= subres;
                        } else if(op == '/') {
                            res /= subres;
                        }
                        i = j;
                        
                    } else if(exp[i]>='0' && exp[i]<='9') {
                        int p = i+1;
                        while(exp[p]>='0' && exp[p]<='9') {
                            p++;
                        }
                        char num[10];
                        int q = 0;
                        for(int r=i; r<p; r++) {
                            num[q++] = exp[r];
                        }
                        num[q] = '\0';
                        float numval = atof(num);
                        if(op == '+') {
                            res += numval;
                        } else if(op == '-') {
                            res -= numval;
                        } else if(op == '*') {
                            res *= numval;
                        } else if(op == '/') {
                            res /= numval;
                        }
                        i = p-1;
                    } else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                        op = exp[i];
                    }
                }
                printf("%.2f\n", res);
                break;
                
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}
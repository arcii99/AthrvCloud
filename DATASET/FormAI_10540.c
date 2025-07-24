//FormAI DATASET v1.0 Category: Banking Record System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ACCOUNTS 1000
#define MAX_TRANSACTIONS 10000

typedef struct {
    int from_acc;
    int to_acc;
    double amount;
    char* description;
    char timestamp[30];
}Transaction;

typedef struct {
    int acc_num;
    char* name;
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int tr_count;
}Account;

typedef struct {
    Account accounts[MAX_ACCOUNTS];
    int acc_count;
}Bank;

void createAccount(Bank* bank, int acc_num, char* name, double balance){
    if(bank->acc_count == MAX_ACCOUNTS){
        printf("Max limit reached! Cannot create more accounts.\n");
        return;
    }
    bank->accounts[bank->acc_count].acc_num = acc_num;
    bank->accounts[bank->acc_count].name = (char*) malloc(sizeof(char) * strlen(name));
    strcpy(bank->accounts[bank->acc_count].name, name);
    bank->accounts[bank->acc_count].balance = balance;
    bank->accounts[bank->acc_count].tr_count = 0;
    bank->acc_count++;
    printf("Account created successfully!\n");
}

Account* getAccount(Bank* bank, int acc_num){
    int i;
    for(i=0;i<bank->acc_count;i++){
        if(bank->accounts[i].acc_num == acc_num){
            return &bank->accounts[i];
        }
    }
    return NULL;
}

void deposit(Bank* bank, int acc_num, double amount, char* desc){
    Account* acc = getAccount(bank, acc_num);
    if(acc == NULL){
        printf("Account does not exist!\n");
        return;
    }
    acc->balance += amount;
    Transaction t = {0};
    t.from_acc = -1;
    t.to_acc = acc_num;
    t.amount = amount;
    t.description = (char*) malloc(sizeof(char) * strlen(desc));
    strcpy(t.description, desc);
    time_t now = time(NULL);
    strcpy(t.timestamp, ctime(&now));
    acc->transactions[acc->tr_count++] = t;
    printf("Amount deposited successfully!\n");
}

void withdraw(Bank* bank, int acc_num, double amount, char* desc){
    Account* acc = getAccount(bank, acc_num);
    if(acc == NULL){
        printf("Account does not exist!\n");
        return;
    }
    if(acc->balance < amount){
        printf("Insufficient balance!\n");
        return;
    }
    acc->balance -= amount;
    Transaction t = {0};
    t.from_acc = acc_num;
    t.to_acc = -1;
    t.amount = amount;
    t.description = (char*) malloc(sizeof(char) * strlen(desc));
    strcpy(t.description, desc);
    time_t now = time(NULL);
    strcpy(t.timestamp, ctime(&now));
    acc->transactions[acc->tr_count++] = t;
    printf("Amount withdrawn successfully!\n");
}

void transfer(Bank* bank, int from_acc_num, int to_acc_num, double amount, char* desc){
    Account* from_acc = getAccount(bank, from_acc_num);
    if(from_acc == NULL){
        printf("From account does not exist!\n");
        return;
    }
    Account* to_acc = getAccount(bank, to_acc_num);
    if(to_acc == NULL){
        printf("To account does not exist!\n");
        return;
    }
    if(from_acc->balance < amount){
        printf("Insufficient balance!\n");
        return;
    }
    from_acc->balance -= amount;
    to_acc->balance += amount;
    Transaction t1 = {0};
    t1.from_acc = from_acc_num;
    t1.to_acc = to_acc_num;
    t1.amount = amount;
    t1.description = (char*) malloc(sizeof(char) * strlen(desc));
    strcpy(t1.description, desc);
    time_t now = time(NULL);
    strcpy(t1.timestamp, ctime(&now));
    from_acc->transactions[from_acc->tr_count++] = t1;
    Transaction t2 = {0};
    t2.from_acc = from_acc_num;
    t2.to_acc = to_acc_num;
    t2.amount = amount;
    t2.description = (char*) malloc(sizeof(char) * strlen(desc));
    strcpy(t2.description, desc);
    strcpy(t2.timestamp, t1.timestamp);
    to_acc->transactions[to_acc->tr_count++] = t2;
    printf("Amount transferred successfully!\n");
}

void showAccountDetails(Account* acc){
    printf("Account Number: %d\n", acc->acc_num);
    printf("Account Holder Name: %s\n", acc->name);
    printf("Account Balance: %.2f\n", acc->balance);
    if(acc->tr_count > 0){
        printf("Transaction History:\n");
        int i;
        for(i=0;i<acc->tr_count;i++){
            printf("Transaction %d:\n", i+1);
            Transaction t = acc->transactions[i];
            printf("Timestamp: %s", t.timestamp);
            printf("Description: %s\n", t.description);
            if(t.from_acc == -1){
                printf("Credited Amount: %.2f\n", t.amount);
            }
            else if(t.to_acc == -1){
                printf("Debited Amount: %.2f\n", t.amount);
            }
            else{
                printf("Transfer Amount: %.2f\n", t.amount);
            }
            printf("\n");
        }
    }
}

void showAllAccounts(Bank* bank){
    int i;
    for(i=0;i<bank->acc_count;i++){
        printf("Account %d:\n", i+1);
        showAccountDetails(&bank->accounts[i]);
    }
}

int main(){
    Bank myBank = {0};
    int choice = 0;
    do{
        printf("Select an option:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Transfer Amount\n");
        printf("5. Show Account Details\n");
        printf("6. Show All Account Details\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                {
                    int acc_num;
                    char name[50];
                    double balance;
                    printf("Enter Account Number: ");
                    scanf("%d", &acc_num);
                    printf("Enter Account Holder Name: ");
                    scanf(" %[^\n]", name);
                    printf("Enter Initial Balance: ");
                    scanf("%lf", &balance);
                    createAccount(&myBank, acc_num, name, balance);
                    break;
                }
            case 2:
                {
                    int acc_num;
                    double amount;
                    char desc[100];
                    printf("Enter Account Number: ");
                    scanf("%d", &acc_num);
                    printf("Enter Deposit Amount: ");
                    scanf("%lf", &amount);
                    printf("Enter Description: ");
                    scanf(" %[^\n]", desc);
                    deposit(&myBank, acc_num, amount, desc);
                    break;
                }
            case 3:
                {
                    int acc_num;
                    double amount;
                    char desc[100];
                    printf("Enter Account Number: ");
                    scanf("%d", &acc_num);
                    printf("Enter Withdraw Amount: ");
                    scanf("%lf", &amount);
                    printf("Enter Description: ");
                    scanf(" %[^\n]", desc);
                    withdraw(&myBank, acc_num, amount, desc);
                    break;
                }
            case 4:
                {
                    int from_acc_num, to_acc_num;
                    double amount;
                    char desc[100];
                    printf("Enter From Account Number: ");
                    scanf("%d", &from_acc_num);
                    printf("Enter To Account Number: ");
                    scanf("%d", &to_acc_num);
                    printf("Enter Transfer Amount: ");
                    scanf("%lf", &amount);
                    printf("Enter Description: ");
                    scanf(" %[^\n]", desc);
                    transfer(&myBank, from_acc_num, to_acc_num, amount, desc);
                    break;
                }
            case 5:
                {
                    int acc_num;
                    printf("Enter Account Number: ");
                    scanf("%d", &acc_num);
                    Account* acc = getAccount(&myBank, acc_num);
                    if(acc == NULL){
                        printf("Account does not exist!\n");
                    }
                    else{
                        showAccountDetails(acc);
                    }
                    break;
                }
            case 6:
                {
                    showAllAccounts(&myBank);
                    break;
                }
            case 7:
                printf("Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 7);
    return 0;
}
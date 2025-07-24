//FormAI DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_accounts = 0;
    int i = 0;
    int j = 0;
    int choice = 0;
    int account_no = 0;
    float deposit = 0;
    float withdraw = 0;

    printf("Welcome to the Banking Record System! \n\n");

    printf("Please enter the number of accounts to be created: ");
    scanf("%d", &num_of_accounts);

    struct account{
        int account_no;
        float balance;
    }accounts[num_of_accounts];

    for(i=0;i<num_of_accounts;i++) {
        printf("\nEnter Account Number: ");
        scanf("%d", &accounts[i].account_no);
        printf("\nEnter Initial Deposit Amount: ");
        scanf("%f", &accounts[i].balance);

        while(accounts[i].balance < 100) {
            printf("The Minimum Balance Required is Rs.100. Please Enter a Valid Amount: ");
            scanf("%f", &accounts[i].balance);
        }
        printf("\nAccount Created Successfully!\n");
    }

    do {
        printf("\n\nMain Menu\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_no);
                for(i=0;i<num_of_accounts;i++) {
                    if(accounts[i].account_no == account_no) {
                        printf("\nEnter Amount to Deposit: ");
                        scanf("%f", &deposit);
                        accounts[i].balance += deposit;
                        printf("\nDeposit Successful!\n");
                        break;
                    } 
                }
                if(i == num_of_accounts){
                    printf("\nAccount Not Found!");
                }
                break;

            case 2:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_no);
                for(i=0;i<num_of_accounts;i++) {
                    if(accounts[i].account_no == account_no) {
                        while(1) {
                            printf("\nEnter Amount to Withdraw: ");
                            scanf("%f", &withdraw);
                            if(accounts[i].balance - withdraw < 100) {
                                printf("\nThe Minimum Balance Required is Rs.100.\n");
                                printf("\nPlease Enter a Valid Amount!\n");
                            } else {
                                accounts[i].balance -= withdraw;
                                printf("\nWithdrawal Successful!\n");
                                break;
                            }
                        }
                        break;
                    } 
                }
                if(i == num_of_accounts){
                    printf("\nAccount Not Found!");
                }
                break;

            case 3:
                printf("\nEnter Account Number: ");
                scanf("%d", &account_no);
                for(i=0;i<num_of_accounts;i++) {
                    if(accounts[i].account_no == account_no) {
                        printf("\nAccount Number: %d \n", accounts[i].account_no);
                        printf("\nAccount Balance: %f \n\n", accounts[i].balance);
                        break;
                    } 
                }
                if(i == num_of_accounts){
                    printf("\nAccount Not Found!");
                }
                break;

            case 4:
                printf("\n\nThanks for Using Our System!");
                exit(0);
                break;

            default:
                printf("\n\nInvalid Choice. Try Again!");
        }
    }while(choice!=4);

    return 0;
}
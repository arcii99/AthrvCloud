//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: puzzling
#include<stdio.h>
#include<math.h>

int main(){

    int loanAmt,rateOfInt,monthDur,payAmt,numOfPays;
    float intRate,monthIntRate,balAmt;

    printf("Enter the amount of loan: ");
    scanf("%d",&loanAmt);

    printf("Enter the interest rate: ");
    scanf("%d",&rateOfInt);

    printf("Enter the duration of loan in months: ");
    scanf("%d",&monthDur);

    intRate=rateOfInt/100.0;
    monthIntRate=intRate/12;
    balAmt=loanAmt;

    payAmt=((balAmt*monthIntRate*pow(1+monthIntRate,monthDur))/(pow(1+monthIntRate,monthDur)-1));
    printf("The monthly payment is: %d",payAmt);

    numOfPays=0;

    printf("The amortization schedule is: \n");
    printf("Payment No.\t\tInterest\t\tPrincipal\t\tBalance\n");
    while(balAmt>0){
        numOfPays+=1;
        float intPortion,balPortion;
        intPortion=(monthIntRate*balAmt);
        balPortion=payAmt-intPortion;
        balAmt-=balPortion;

        if(balAmt<0){
            balAmt=0;
        }

        printf("%d\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f\n", numOfPays,intPortion,balPortion,balAmt);
    }

    return 0;
}
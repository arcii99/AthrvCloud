//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    double loanAmount;
    double interestRate;
    int loanTerm;
} Mortgage;

typedef struct {
    Mortgage mortgage;
    double monthlyPayment;
} MortgageOutput;

typedef struct {
    double principal;
    double interest;
    double balance;
} Payment;

Payment createPayment(double principal, double interest, double balance) {
    Payment payment;
    payment.principal = principal;
    payment.interest = interest;
    payment.balance = balance;
    return payment;
}

MortgageOutput calculateMortgage(Mortgage mortgage) {
    double monthlyInterest = (mortgage.interestRate / 12) / 100;
    int totalPayments = mortgage.loanTerm * 12;

    double numerator = monthlyInterest * pow((1 + monthlyInterest), totalPayments);
    double denominator = pow((1 + monthlyInterest), totalPayments) - 1;

    double monthlyPayment = mortgage.loanAmount * (numerator / denominator);
    MortgageOutput output = {.mortgage = mortgage, .monthlyPayment = monthlyPayment};
    return output;
}

Payment* calculatePayments(Mortgage mortgage) {
    MortgageOutput output = calculateMortgage(mortgage);
    Payment* payments = malloc(sizeof(Payment) * (mortgage.loanTerm * 12));

    double balance = mortgage.loanAmount;
    for (int i = 0; i < (mortgage.loanTerm * 12); i++) {
        double previousBalance = balance;
        double interestPayment = previousBalance * ((mortgage.interestRate / 12) / 100);
        double principalPayment = output.monthlyPayment - interestPayment;
        balance -= principalPayment;

        if (i == ((mortgage.loanTerm * 12) - 1)) {
            principalPayment += balance;
            balance = 0.0;
        }

        Payment payment = createPayment(principalPayment, interestPayment, balance);
        payments[i] = payment;

        if (balance <= 0.0) {
            break;
        }
    }

    return payments;
}

void printMortgageOutput(MortgageOutput output) {
    printf("Mortgage Calculator Results:\n");
    printf("Loan Amount: $%.2f\n", output.mortgage.loanAmount);
    printf("Interest Rate: %.2f%%\n", output.mortgage.interestRate);
    printf("Loan Term: %d years\n", output.mortgage.loanTerm);
    printf("Monthly Payment: $%.2f\n\n", output.monthlyPayment);
}

void printPayments(Payment* payments, int length, Mortgage mortgage) {
    printf("Payment Schedule:\n");
    printf("%8s %10s %10s %15s\n", "Month", "Principal", "Interest", "Balance");

    for (int i = 0; i < length; i++) {
        Payment payment = payments[i];

        if (payment.balance <= 0.0) {
            break;
        }

        double totalInterest = mortgage.loanAmount * (mortgage.interestRate / 100 / 12);
        double currentBalance = payment.balance + payment.principal;
        printf("%4d %10.2f %10.2f %15.2f\n",
            i+1,
            payment.principal,
            payment.interest + totalInterest,
            currentBalance
        );
    }
}

bool isNumber(char* input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-') {
            return false;
        }

        if (input[i] == '-' && i != 0) {
            return false;
        }

        if (input[i] == '.' && i == (length - 1)) {
            return false;
        }
    }

    return true;
}

double parseDouble(char* input) {
    double output = 0.0;
    sscanf(input, "%lf", &output);
    return output;
}

int parseInt(char* input) {
    int output = 0;
    sscanf(input, "%d", &output);
    return output;
}

void getInput(char* message, char* output) {
    printf("%s", message);
    fgets(output, 256, stdin);
    output[strlen(output) - 1] = '\0';
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void printHeader() {
    printf("\n***** Mortgage Calculator *****\n\n");
}

void waitForEnter() {
    printf("\nPress enter to continue...");
    getchar();
}

void cleanUp(Payment* payments) {
    free(payments);
}

Mortgage createMortgage() {
    Mortgage mortgage;
    char input[256];
    char* message;

    getInput("Enter Loan Amount: $", input);
    while(!isNumber(input)) {
        getInput("Invalid input, please enter a valid number: $", input);
    }
    mortgage.loanAmount = parseDouble(input);

    getInput("Enter Interest Rate: ", input);
    while(!isNumber(input)) {
        getInput("Invalid input, please enter a valid number: ", input);
    }
    mortgage.interestRate = parseDouble(input);

    getInput("Enter Loan Term (in years): ", input);
    while(!isNumber(input)) {
        getInput("Invalid input, please enter a valid number: ", input);
    }
    mortgage.loanTerm = parseInt(input);

    return mortgage;
}

void outputMortgageCalculator() {
    printf("\n\n");

    Mortgage mortgage = createMortgage();
    clearScreen();

    MortgageOutput output = calculateMortgage(mortgage);
    Payment* payments = calculatePayments(mortgage);

    printHeader();
    printMortgageOutput(output);
    waitForEnter();

    clearScreen();
    printHeader();
    printPayments(payments, mortgage.loanTerm * 12, mortgage);
    waitForEnter();
    cleanUp(payments);
}

int main() {
    outputMortgageCalculator();
    return 0;
}
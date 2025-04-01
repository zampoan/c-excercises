#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct BankAccount {
    float balance;
    char firstName[10];
    char lastName[10];
};

enum TransactionType{
    WITHDRAWL,
    DEPOSIT,
    TRANSFER
};

struct Transaction{
    int id;
    enum TransactionType type;
};


void mainMenu(){
    printf("1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money\n");
    printf("4. Account Detail\n");
    printf("5. Transaction Details\n");
    printf("6. Exit\n");
}

// Helper function to convert enum to string
const char* transactionToString(enum TransactionType type){
    switch (type)
    {
    case DEPOSIT:
        return "Deposit";
    case WITHDRAWL:
        return "Withdrawal";
    case TRANSFER:
        return "Transfer";
    default:
        return "Unknown";
    }
}

bool passOptions(int *pickOption, struct BankAccount *b1, struct BankAccount *b2, bool *exitCondition, struct Transaction *transaction, int *transactionCount){
    float money;
    if (*pickOption == 1){
        printf("How much money do you wish to deposit?\n");
        scanf("%f", &money);
        b1->balance += money;
        printf("New balance: $%.2f\n", b1->balance);

        // Update the transaction table, [[0, DEPOSIT], [1, DEPOSIT]...]
        transaction[*transactionCount] = (struct Transaction){*transactionCount + 1, DEPOSIT};
        *transactionCount += 1;

    } else if (*pickOption == 2){
        printf("How much money do you wish to withdraw?\n");
        scanf("%f", &money);
        if (b1->balance > money){
            b1->balance -= money;
            printf("New balance: $%.2f\n", b1->balance);

            transaction[*transactionCount] = (struct Transaction){*transactionCount + 1, WITHDRAWL};
            *transactionCount += 1;

        } else {
            printf("Not enough funds.\n");
        }

    } else if (*pickOption == 3){
        // Assume transfer from b2 to b1
        printf("Choose how much to transfer: \n");
        scanf("%f", &money);
        if (money < b2->balance){
            b2->balance -= money;
            b1->balance += money;
            printf("New balance of b1: %f\n", b1->balance);
            printf("New balance of b2: %f\n", b2->balance);
            
            transaction[*transactionCount] = (struct Transaction){*transactionCount + 1, TRANSFER};
            *transactionCount += 1;

        } else {
            printf("Not enough balance.\n");
        }
        
    } else if (*pickOption == 4){
        printf("Account Name: %s\n", b1->firstName);
        printf("Balance: %.2f\n", b1->balance);
        *transactionCount += 1;

    } else if (*pickOption == 5){
        // Print all of the transactions
        for (int i = 0; i < *transactionCount+1; i++){
            printf("Transaction ID: %d, Type: %s\n", transaction[i].id, transactionToString(transaction[i].type));
        };
    
    } else if (*pickOption == 6){
        *exitCondition = true;
        *transactionCount += 1;
        
    } else {
        printf("Option does not exist.\n");
        *transactionCount += 1;

    }
    return *exitCondition;
}

int main(){
    int pickOption = 0;
    int transactionCount = 0;
    struct BankAccount b1 = {1000, "John", "Doe"};
    struct BankAccount b2 = {500, "John", "Doe"};
    struct Transaction transaction[10] = {0};

    bool exit = false;

    while (!exit){
        mainMenu();
        scanf("%d", &pickOption);
        passOptions(&pickOption, &b1, &b2, &exit, transaction, &transactionCount);
        
    };
}


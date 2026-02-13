#include <stdio.h>

int checkPin(int pin, int input){
    if(pin==input){
        printf("You have Logged in successfully \n");
        return 0;
    }else{
        printf("The pin is incorrect please try again \n");
        return 1;
    }
}

void checkBalance(int account_balance){
    printf("Your Balance is %f \n", account_balance);
}

float deposit(float account_balance){
    float amount;
    printf("Enter Amount to deposit \n");
    scanf("%lf", &amount);
    amount > 0  ?   account_balance += amount : printf("Enter a valid amount");
    printf("New Balance is: %f \n", account_balance);
    return account_balance;
}

float withdraw(float account_balance){
    float amount;
    printf("Enter Amount to Withdraw \n");
    scanf("%lf", &amount);
    amount > 0 & amount < account_balance ?   account_balance -= amount : printf("Enter a valid amount");
    printf("New Balance is %f \n",account_balance);
    return account_balance;
}


int main(){
    int pin = 1234;
    int input;
    double account_balance = 0.0;
    double amount;
    int loggedIn;
    int attempts = 3;
    printf("Enter PIN to log in: \n");
    scanf("%d", &input);

    loggedIn = checkPin(pin,input);

    while (loggedIn != 0 & attempts > 1){        
        printf("\nEnter PIN to log in: ");
        scanf("%d", &input);
        loggedIn = checkPin(pin, input);
        attempts --;
    }

    char option;
    while (loggedIn == 0){
        printf("\nEnter an option: \n");
        printf("1. Balance Inquiry \n2. Deposit \n3. Withdraw \n4. Exit \n\n");
        scanf(" %c", &option);
        
        switch(option){
            case '1':
                checkBalance(account_balance);
                break;
            case '2':                               
                account_balance  = deposit(account_balance);                
                break;
            case '3':                
                account_balance = withdraw(account_balance);
                break;
            case '4':
                printf("You have logged out");
                loggedIn = 1;
                break;
            default:
                option = '0';
        }

    }
    return 0;
}

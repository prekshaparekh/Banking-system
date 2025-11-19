#include<stdio.h>
#include<string.h>

struct bankaccount {
    char name[30];
    int pin;
    float balance;
    int accountnum;
};

struct bankaccount account[100];
int totalaccounts=0;

void createaccount();
void accessaccount();
void deposit(int index);
void withdraw(int index);
void checkbalance(int index);
void savetofile();
void loadfromfile();
int findaccount(int accountnumber, int accountpin);

int main(){
    int choice;

    loadfromfile();

    printf("this is a multi-user bank accout \n");

    while(1){
        printf("\n----- MAIN MENU -----\n");
        printf("1. Create New Account\n");
        printf("2. Access Existing Account\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createaccount();
            break;
        case 2:
            accessaccount();
            break;
        case 3:
            printf("thank you visit again");
            return 0;
        
        default:
            printf("you did not chose anything try again");
            break;
        }
    }
    return 0;
}

void savetofile(){
    FILE *file = fopen("bank_accounts","wb");

    if(file == NULL) {
        printf("\nError: Could not save account data!\n");
        return;
    }

    fwrite(&totalaccounts,sizeof(int),1,file);
    fwrite(account,sizeof(struct bankaccount),totalaccounts,file);
    fclose(file);
}

void loadfromfile(){
    FILE *file = fopen("bank_accounts","rb");

    if(file == NULL) {
        printf("\nError: Could not save account data!\n");
        return;
    }

    fread(&totalaccounts,sizeof(int),1,file);
    fread(account,sizeof(struct bankaccount),totalaccounts,file);

    fclose(file);
    if (totalaccounts >0){
        printf("loaded the existing accounts");
    }

}

void createaccount(){
    int initial_deposite,accountpin;

    if (totalaccounts >= 100){printf("the bank in full!! Cannot create more accounts");
    return ;}

    printf("\n----- CREATE NEW ACCOUNT -----\n");

    
    printf("enter your name: ");
    scanf("%s",account[totalaccounts].name);

    printf("create your pin: ");
    scanf("%d",&account[totalaccounts].pin);

    printf("enter the initial deposite: ");
    scanf("%f",&account[totalaccounts].balance);

    if(initial_deposite<0){printf("the amount cannont be less than zero!!");return;}
    
    account[totalaccounts].accountnum = 1000+totalaccounts;
    printf("your account number is: %d\n",account[totalaccounts].accountnum);
    totalaccounts++;

    savetofile();


}

int findaccount(int accountnumber, int accountpin){
    for(int i=0; i<totalaccounts;i++){
        if(account[i].accountnum== accountnumber && account[i].pin == accountpin){
            return i;
        } 
        
    }
    return -1;
}

void accessaccount(){
    int account_number,accountpin;
    int account_index;
    int choice;

     if(totalaccounts == 0) {
        printf("\nNo accounts found! Please create an account first.\n");
        return;
    }
    printf("\n----- ACCESS ACCOUNT -----\n");
    printf("Enter your Account Number: ");
    scanf("%d",&account_number);

    printf("enter your account PIN: ");
    scanf("%d",&accountpin);
    
    account_index = findaccount(account_number,accountpin);

    if(account_index == -1){
        printf("sorry no such account existes");
        return;
    }

    while(1) {
        printf("\n----- ACCOUNT MENU -----\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                checkbalance(account_index);
                break;
            case 2:
                deposit(account_index);
                break;
            case 3:
                withdraw(account_index);
                break;
            case 4:
                printf("logged out");
                return;
            default:
                printf("\nInvalid choice! Please try again.\n");
            }
        }
}

void checkbalance(int index){
    printf("\n----- BALANCE INQUIRY -----\n");
    printf("Account Number: %d\n", account[index].accountnum);
    printf("Account Holder: %s\n", account[index].name);
    printf("Current Balance: $%.2f\n", account[index].balance);
}

void deposit(int index) {
    float amount;
    
    printf("\n----- DEPOSIT MONEY -----\n");
    printf("Current Balance: $%.2f\n", account[index].balance);
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    if(amount <= 0) {
        printf("\nInvalid amount! Please enter a positive value.\n");
        return;
    }
    
    account[index].balance += amount;
    printf("\nDeposit successful!\n");
    printf("New Balance: $%.2f\n", account[index].balance);
}

void withdraw(int index) {
    float amount;
    
    printf("\n----- WITHDRAW MONEY -----\n");
    printf("Current Balance: $%.2f\n", account[index].balance);
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    
    if(amount <= 0) {
        printf("\nInvalid amount! Please enter a positive value.\n");
        return;
    }
    
    if(amount > account[index].balance) {
        printf("\nInsufficient funds! Transaction failed.\n");
        printf("Your current balance is: $%.2f\n", account[index].balance);
        return;
    }
    
    account[index].balance -= amount;
    printf("\nWithdrawal successful!\n");
    printf("New Balance: $%.2f\n", account[index].balance);
}
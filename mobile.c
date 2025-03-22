#include <stdio.h>
#include <stdlib.h> //Memory allocation and dellocation, random number generation
#include <string.h>
#include <time.h>

// Structure that defines the user account structure
typedef struct
{
    char name[50];
    char phoneNumber[15];
    float balance;
    char pin[5]; // 4-digit PIN plus null terminator
} Account;

// Function prototypes
void displayMenu();
void checkBalance(Account *account);
int withdraw(Account *account, float amount);
int deposit(Account *account, float amount);

// main function
int main()
{
    // Initialize a sample account
    Account userAccount = {
        "Aisha",
        "0712345678",
        50000.0,
        "1234"};

    int choice;
    float amount;
    char pin[5];

    printf("===== MOBILE MONEY SYSTEM =====\n");
    printf("Welcome, %s!\n", userAccount.name);

    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Check Balance
            printf("Enter PIN: ");
            scanf("%s", pin);
            if (strcmp(pin, userAccount.pin) == 0)
            {
                checkBalance(&userAccount);
            }
            else
            {
                printf("Invalid PIN. Please try again.\n");
            }
            break;

        case 2: // Withdraw
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            printf("Enter PIN: ");
            scanf("%s", pin);

            if (strcmp(pin, userAccount.pin) == 0)
            {
                if (withdraw(&userAccount, amount))
                {
                    printf("Withdrawal successful!\n");
                    printf("New balance: %.2f\n", userAccount.balance);
                }
                else
                {
                    printf("Withdrawal failed. Insufficient balance or invalid amount.\n");
                }
            }
            else
            {
                printf("Invalid PIN. Transaction cancelled.\n");
            }
            break;

        case 3: // Deposit
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (deposit(&userAccount, amount))
            {
                printf("Deposit successful!\n");
                printf("New balance: %.2f\n", userAccount.balance);
            }
            else
            {
                printf("Deposit failed. Invalid amount.\n");
            }
            break;

        case 4: // Exit
            printf("Thank you for using Mobile Money System.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();       // Consume the newline
        getchar();       // Wait for Enter
        system("clear"); // Clear screen (use "cls" for Windows)
    }

    return 0;
}

// Assigning tasks to the function
void displayMenu()
{
    printf("\n===== MENU =====\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Exit\n");
}

void checkBalance(Account *account)
{
    printf("\n===== ACCOUNT BALANCE =====\n");
    printf("Name: %s\n", account->name);
    printf("Phone: %s\n", account->phoneNumber);
    printf("Current Balance: %.2f\n", account->balance);
}

int withdraw(Account *account, float amount)
{
    // Validate withdrawal amount
    if (amount <= 0)
    {
        return 0; // Invalid amount
    }

    // Check if there's enough balance
    if (amount > account->balance)
    {
        return 0; // Insufficient balance
    }

    // Process withdrawal
    account->balance -= amount;
    return 1; // Success
}

int deposit(Account *account, float amount)
{
    // Validate deposit amount
    if (amount <= 0)
    {
        return 0; // Invalid amount
    }

    // Process deposit
    account->balance += amount;
    return 1; // Success
}

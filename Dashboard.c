#include <stdio.h>
#include <string.h>

char addaccount[12];
int deposit;
int withdraw;

int main()
{
    int number, balance = 0;
    int accountCreated = 0;

    printf("\nBANKING MANAGEMENT SYSTEM");
    printf("\nMENU");
    printf("\nPress 1 for Add Account Number");
    printf("\nPress 2 for Deposit Money");
    printf("\nPress 3 for Withdraw Money");
    printf("\nPress 4 for Checking the Balance");
    printf("\nPress 5 for Exit the Program");

    do
    {
        printf("\nPlease enter any number: ");
        while (scanf("%d", &number) != 1) 
        {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n'); 
        }

        switch (number)
        {
        case 1: 
            printf("Please enter your account number: ");
            scanf("%s", addaccount);

            while (strlen(addaccount) == 0 || strlen(addaccount) != 11)
            {
                printf("Invalid account number. Please enter 11 characters.\n");
                printf("Please enter your account number: ");
                scanf("%s", addaccount);
            }
           
            
            printf("Please enter your initial deposit amount (minimum 500 rupees): ");
            scanf("%d", &deposit);

            while (deposit < 500 || deposit % 100 != 0)
            {
                printf("\nSORRY! Minimum initial deposit amount is 500 rupees or in round figure like 500,600.....");
                printf("\nPlease enter your initial deposit amount: ");
                scanf("%d", &deposit);
            }

            balance += deposit; 
            printf("Your amount has been successfully deposited.");
            

            accountCreated = 1; 
            printf("\nYou have successfully created an account in our bank.");
            printf("\nThe created account number is: %s\n", addaccount);
            printf("\nNew balance: %d\n", balance);

            break;

        case 2:
            if (accountCreated == 0)
            {
                printf("Please create an account first before depositing money.\n");
            }
            else
            {
                printf("Please enter your deposit amount: ");
                scanf("%d", &deposit);

                while (deposit < 500 || deposit % 100 != 0)
                {
                    printf("\nSORRY! Minimum deposit amount is 500 rupees or in round figure like 500,600.....");
                    printf("\nPlease enter your deposit amount: ");
                    scanf("%d", &deposit);
                }

                balance += deposit;
                printf("Your amount has been successfully deposited.");
                printf("\nNew balance: %d\n", balance);
            }
            break;

        case 3:
            if (accountCreated == 0)
            {
                printf("Please create an account first before withdrawing money.\n");
            }
            else
            {
                printf("Please enter your withdraw amount: ");
                scanf("%d", &withdraw);

                while (withdraw < 500 || withdraw % 100 != 0)
                {
                    printf("SORRY! Minimum withdraw amount is 500 rupees or in round-figure like 500,600.....");
                    printf("\nPlease enter your withdraw amount: ");
                    scanf("%d", &withdraw);
                }

                if (withdraw > balance)
                {
                    printf("\nInsufficient balance.\n");
                }
                else
                {
                    balance -= withdraw;
                    printf("Your amount has been successfully withdrawn.");
                    printf("\nNew balance: %d\n", balance);
                }
            }
            break;

        case 4:
            if (accountCreated == 0)
            {
                printf("Please create an account first to check your balance.\n");
            }
            else
            {
                printf("\nThe account number is: %s\n", addaccount);
                printf("Your balance is: %d\n", balance);
            }
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid number. Please try again.\n");
            break;
        }
    } while (number != 55);

    return 0;
}
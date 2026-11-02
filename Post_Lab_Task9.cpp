#include <stdio.h>
void welcome();
void displayMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);
void clearBuffer();

int main()
{
	float balance = 20000;
	int choice = 0;
	printf("This is a program written in C to practise UDFs (ATM Transaction System)");
	welcome();
	do
	{
		displayMenu();
		if (scanf("%d", &choice) != 1)
		{
			clearBuffer(); //removes wrong input such as letters
			choice = 0;
		}
		switch (choice)
		{
			case 1:
				checkBalance(balance);
				break;
			case 2:
				balance = depositMoney(balance);
				break;
			case 3:
				balance = withdrawMoney(balance);
				break;
			case 4:
				printf("\nThank you for using the ATM. Goodbye!");
				break;
			default:
				printf("\nInvalid Choice Entered, please select from 1 to 4");
		}
	} while (choice != 4);
	return 0;
}

void welcome()
{
	printf("\n\n----- Welcome to the ATM -----");
}

void displayMenu()
{
	printf("\n\n----- ATM Menu -----");
	printf("\n1. Check Balance");
	printf("\n2. Deposit Money");
	printf("\n3. Withdraw Money");
	printf("\n4. Exit");
	printf("\nEnter your choice: ");
}

void checkBalance(float balance)
{
	printf("\nYour current balance is: Rs. %.2f", balance);
}

float depositMoney(float balance)
{
	float amount;
	printf("\nEnter the amount to deposit: ");
	if (scanf("%f", &amount) != 1)
	{
		clearBuffer();
		amount = 0;
	}
	if (amount <= 0)
	{
		printf("Invalid Amount, the deposit must be positive. Transaction failed");
	}
	else
	{
		balance = balance + amount;
		printf("Deposit successful!");
		printf("\nUpdated balance: Rs. %.2f", balance);
	}
	return balance;
}

float withdrawMoney(float balance)
{
	float amount;
	printf("\nEnter the amount to withdraw: ");
	if (scanf("%f", &amount) != 1)
	{
		clearBuffer();
		amount = 0;
	}
	if (amount <= 0)
	{
		printf("Invalid Amount, the withdrawal must be positive. Transaction failed");
	}
	else if (amount > balance)
	{
		printf("Insufficient Balance. Transaction failed");
	}
	else if (amount > 10000)
	{
		printf("Withdrawal limit exceeded, maximum is Rs. 10000 per transaction. Transaction failed");
	}
	else
	{
		balance = balance - amount;
		printf("Withdrawal successful!");
		printf("\nUpdated balance: Rs. %.2f", balance);
		if (balance < 5000)
		{
			printf("\nWARNING: Your balance is low (below Rs. 5000)");
		}
	}
	return balance;
}

void clearBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
}

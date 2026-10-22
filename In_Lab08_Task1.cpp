# include <stdio.h>
void welcome();
void displayAmount(float amount);
float getWithdrawalLimit();
float calculateBalance(float balance, float amount);
int checkWithdrawal(float balance, float amount, float limit);

int main()
{
	float balance, amount, limit;
	int valid;
	printf("This is a program written in C to simulate a simple ATM system using functions");
	welcome();
	limit = getWithdrawalLimit();
	printf("\nEnter your current account balance: ");
	scanf("%f", &balance);
	printf("\nEnter the amount you want to withdraw: ");
	scanf("%f", &amount);
	displayAmount(amount);
	valid = checkWithdrawal(balance, amount, limit);
	if (valid == 1)
	{
		balance = calculateBalance(balance, amount);
		printf("\nThe withdrawal is valid");
		printf("\nYour remaining balance is: Rs. %.2f", balance);
	}
	else
	{
		printf("\nThe withdrawal is not valid, so the balance is not updated");
		printf("\nYour balance is: Rs. %.2f", balance);
	}
	return 0;
}

void welcome()
{
	printf("\n\n----- Welcome to the ATM -----");
}

void displayAmount(float amount)
{
	printf("\nThe withdrawal amount is: Rs. %.2f", amount);
}

float getWithdrawalLimit()
{
	return 50000;
}

float calculateBalance(float balance, float amount)
{
	return balance - amount;
}
int checkWithdrawal(float balance, float amount, float limit)
{
	int valid = 0;
	if (amount > 0 && amount <= balance && amount <= limit)
	{
		valid = 1;
	}
	return valid;
}


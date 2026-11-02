#include <stdio.h>
void welcome();
int getNumber();
int isEven(int number);
int isPalindrome(int number);
int isPrime(int number);
void displayResults(int number, int even, int palindrome, int prime);

int main()
{
	int number, even, palindrome, prime;
	printf("This is a program written in C to practise UDFs (Number Property Analyzer)");
	welcome();
	number = getNumber();
	even = isEven(number);
	palindrome = isPalindrome(number);
	prime = isPrime(number);
	displayResults(number, even, palindrome, prime);
	return 0;
}

void welcome()
{
	printf("\n\n----- Number Property Analyzer -----");
}

int getNumber()
{
	int number;
	do
	{
		printf("\nEnter a positive integer: ");
		scanf("%d", &number);
		if (number <= 0)
		{
			printf("Invalid Number Entered, it must be positive");
		}
	} while (number <= 0);
	return number;
}

int isEven(int number)
{
	if (number % 2 == 0)
	{
		return 1;
	}
	return 0;
}

int isPalindrome(int number)
{
	int original = number, reversed = 0, digit;
	while (number > 0)
	{
		digit = number % 10;
		reversed = reversed * 10 + digit;
		number = number / 10;
	}
	if (reversed == original)
	{
		return 1;
	}
	return 0;
}

int isPrime(int number)
{
	int i;
	if (number < 2) 
	{
		return 0;
	}
	for (i = 2; i <= number / i; i++)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void displayResults(int number, int even, int palindrome, int prime)
{
	printf("\n\n----- Results for %d -----", number);
	if (even == 1)
	{
		printf("\nThe number is EVEN");
	}
	else
	{
		printf("\nThe number is ODD");
	}
	if (palindrome == 1)
	{
		printf("\nThe number is a PALINDROME");
	}
	else
	{
		printf("\nThe number is NOT a palindrome");
	}
	if (prime == 1)
	{
		printf("\nThe number is a PRIME number");
	}
	else if (number == 1)
	{
		printf("\nThe number is NOT a prime number (1 is neither prime nor composite)");
	}
	else
	{
		printf("\nThe number is NOT a prime number");
	}
}

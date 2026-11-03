#include <stdio.h>
void welcome();
int getAge();
float getSalary();
float getExistingPayments(float salary);
float calculateRemaining(float salary, float payments);
int checkAge(int age);
int checkSalary(float salary);
int checkRemaining(float salary, float remaining);
float calculateMaxLoan(float remaining);
void displayResult(int ageOk, int salaryOk, int remainingOk, float maxLoan);

int main()
{
	int age, ageOk, salaryOk, remainingOk;
	float salary, payments, remaining, maxLoan = 0;
	printf("This is a program written in C to practise UDFs (Loan Eligibility Checker)");
	welcome();
	age = getAge();
	salary = getSalary();
	payments = getExistingPayments(salary);
	remaining = calculateRemaining(salary, payments);
	printf("\n\nRemaining monthly income: Rs. %.2f", remaining);

	ageOk = checkAge(age);
	salaryOk = checkSalary(salary);
	remainingOk = checkRemaining(salary, remaining);
	if (ageOk == 1 && salaryOk == 1 && remainingOk == 1)
	{
		maxLoan = calculateMaxLoan(remaining);
	}
	displayResult(ageOk, salaryOk, remainingOk, maxLoan);
	return 0;
}

void welcome()
{
	printf("\n\n----- Loan Eligibility Checker -----");
}

int getAge()
{
	int age;
	do
	{
		printf("\nEnter your age: ");
		scanf("%d", &age);
		if (age <= 0)
		{
			printf("Invalid Age Entered, please try again");
		}
	} while (age <= 0);
	return age;
}

float getSalary()
{
	float salary;
	do
	{
		printf("\nEnter your monthly salary: ");
		scanf("%f", &salary);
		if (salary <= 0)
		{
			printf("Invalid Salary Entered, it must be greater than 0");
		}
	} while (salary <= 0);
	return salary;
}

float getExistingPayments(float salary)
{
	float payments;
	do
	{
		printf("\nEnter your existing monthly loan payments (0 if none): ");
		scanf("%f", &payments);
		if (payments < 0)
		{
			printf("Invalid Payments Entered, they cannot be negative");
		}
	} while (payments < 0);
	return payments;
}

float calculateRemaining(float salary, float payments)
{
	return salary - payments;
}

int checkAge(int age)
{
	if (age >= 21)
	{
		return 1;
	}
	return 0;
}

int checkSalary(float salary)
{
	if (salary >= 50000)
	{
		return 1;
	}
	return 0;
}

int checkRemaining(float salary, float remaining)
{
	if (remaining >= salary * 40 / 100)
	{
		return 1;
	}
	return 0;
}

float calculateMaxLoan(float remaining)
{
	return remaining * 10;
}

void displayResult(int ageOk, int salaryOk, int remainingOk, float maxLoan)
{
	printf("\n\n----- Result -----");
	if (ageOk == 1 && salaryOk == 1 && remainingOk == 1)
	{
		printf("\nCongratulations! You are ELIGIBLE for a loan");
		printf("\nMaximum loan amount: Rs. %.2f", maxLoan);
	}
	else
	{
		printf("\nSorry, you are NOT ELIGIBLE for a loan");
		printf("\nReason(s):");
		if (ageOk == 0)
		{
			printf("\n- Age is below 21 years");
		}
		if (salaryOk == 0)
		{
			printf("\n- Monthly salary is below Rs. 50000");
		}
		if (remainingOk == 0)
		{
			printf("\n- Less than 40%% of the salary remains after existing payments");
		}
	}
}

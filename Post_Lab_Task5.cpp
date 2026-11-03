#include <stdio.h>
void welcome();
float getBasicSalary();
float getYears();
int getBonusPercent(float years);
float calculateBonus(float basicSalary, int bonusPercent);
float calculateTax(float salaryAfterBonus);
void displaySalary(float basicSalary, int bonusPercent, float bonus, float tax, float finalSalary);

int main()
{
	float basicSalary, years, bonus, salaryAfterBonus, tax, finalSalary;
	int bonusPercent;
	printf("This is a program written in C to practise UDFs (Employee Salary and Bonus)");
	welcome();
	basicSalary = getBasicSalary();
	years = getYears();
	bonusPercent = getBonusPercent(years);
	bonus = calculateBonus(basicSalary, bonusPercent);
	salaryAfterBonus = basicSalary + bonus;
	tax = calculateTax(salaryAfterBonus);
	finalSalary = salaryAfterBonus - tax;
	displaySalary(basicSalary, bonusPercent, bonus, tax, finalSalary);
	return 0;
}

void welcome()
{
	printf("\n\n----- Employee Salary Calculator -----");
}

float getBasicSalary()
{
	float salary;
	do
	{
		printf("\nEnter the basic salary: ");
		scanf("%f", &salary);
		if (salary <= 0)
		{
			printf("Invalid Salary Entered, it must be greater than 0");
		}
	} while (salary <= 0);
	return salary;
}

float getYears()
{
	float years;
	do
	{
		printf("\nEnter the years of service: ");
		scanf("%f", &years);
		if (years < 0)
		{
			printf("Invalid Years Entered, they cannot be negative");
		}
	} while (years < 0);
	return years;
}

int getBonusPercent(float years)
{
	int percent;
	if (years > 5)
	{
		percent = 15;
	}
	else if (years >= 3 && years <= 5)
	{
		percent = 10;
	}
	else 
	{
		percent = 5;
	}
	return percent;
}

float calculateBonus(float basicSalary, int bonusPercent)
{
	return basicSalary * bonusPercent / 100;
}

float calculateTax(float salaryAfterBonus)
{
	float tax = 0;
	if (salaryAfterBonus > 100000)
	{
		tax = salaryAfterBonus * 5 / 100;
	}
	return tax;
}

void displaySalary(float basicSalary, int bonusPercent, float bonus, float tax, float finalSalary)
{
	printf("\n\n----- Salary Details -----");
	printf("\nBasic salary: Rs. %.2f", basicSalary);
	printf("\nBonus (%d%%): Rs. %.2f", bonusPercent, bonus);
	printf("\nTax: Rs. %.2f", tax);
	if (tax == 0)
	{
		printf(" (Salary after bonus does not exceed Rs. 100000, so no tax)");
	}
	printf("\nFinal salary: Rs. %.2f", finalSalary);
}


#include <stdio.h>
void welcome();
int getUnits();
int getCategory();
float calculateBill(int units, int category);
float calculateSurcharge(float bill);
void displayBill(int units, int category, float bill, float surcharge, float finalAmount);

int main()
{
	int units, category;
	float bill, surcharge, finalAmount;
	printf("This is a program written in C to practise UDFs (Electricity Bill Calculator)");
	welcome();
	units = getUnits();
	category = getCategory();
	bill = calculateBill(units, category);
	surcharge = calculateSurcharge(bill);
	finalAmount = bill + surcharge;
	displayBill(units, category, bill, surcharge, finalAmount);
	return 0;
}

void welcome()
{
	printf("\n\n----- Electricity Bill Calculator -----");
}

int getUnits()
{
	int units;
	do
	{
		printf("\nEnter the units consumed: ");
		scanf("%d", &units);
		if (units < 0)
		{
			printf("Invalid Units Entered, they cannot be negative");
		}
	} while (units < 0);
	return units;
}

int getCategory()
{
	int category;
	do
	{
		printf("\nEnter customer category (1 -> Domestic, 2 -> Commercial): ");
		scanf("%d", &category);
		if (category != 1 && category != 2)
		{
			printf("Invalid Category Entered, please enter 1 or 2");
		}
	} while (category != 1 && category != 2);
	return category;
}

float calculateBill(int units, int category)
{
	float bill;
	if (category == 1)
	{
		if (units <= 100)
		{
			bill = units * 15;
		}
		else 
		{
			bill = (100 * 15) + ((units - 100) * 20);
		}
	}
	else
	{
		bill = units * 25;
	}
	return bill;
}

float calculateSurcharge(float bill)
{
	float surcharge = 0;
	if (bill > 5000)
	{
		surcharge = bill * 5 / 100;
	}
	return surcharge;
}

void displayBill(int units, int category, float bill, float surcharge, float finalAmount)
{
	printf("\n\n----- Electricity Bill -----");
	if (category == 1)
	{
		printf("\nCustomer Category: Domestic");
	}
	else
	{
		printf("\nCustomer Category: Commercial");
	}
	printf("\nUnits consumed: %d", units);
	printf("\nBill amount: Rs. %.2f", bill);
	printf("\nSurcharge: Rs. %.2f", surcharge);
	if (surcharge == 0)
	{
		printf(" (Bill does not exceed Rs. 5000, so no surcharge)");
	}
	printf("\nFinal payable amount: Rs. %.2f", finalAmount);
}

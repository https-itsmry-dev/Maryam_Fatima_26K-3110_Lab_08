#include <stdio.h>
void welcome();
float getWeight();
float getDistance();
int getMembership();
float calculateBaseCharge(float weight);
float calculateDistanceCharge(float distance);
float calculateDiscount(float totalCharges, int member);
void displayCharges(float baseCharge, float distanceCharge, float discount, float finalAmount);

int main()
{
	float weight, distance, baseCharge, distanceCharge, totalCharges, discount, finalAmount;
	int member;
	printf("This is a program written in C to practise UDFs (Delivery Charges Calculator)");
	welcome();
	weight = getWeight();
	distance = getDistance();
	member = getMembership();
	baseCharge = calculateBaseCharge(weight);
	distanceCharge = calculateDistanceCharge(distance);
	totalCharges = baseCharge + distanceCharge;
	discount = calculateDiscount(totalCharges, member);
	finalAmount = totalCharges - discount;
	displayCharges(baseCharge, distanceCharge, discount, finalAmount);
	return 0;
}

void welcome()
{
	printf("\n\n----- Delivery Charges Calculator -----");
}

float getWeight()
{
	float weight;
	do
	{
		printf("\nEnter the parcel weight in kg: ");
		scanf("%f", &weight);
		if (weight <= 0)
		{
			printf("Invalid Weight Entered, it must be greater than 0");
		}
	} while (weight <= 0);
	return weight;
}

float getDistance()
{
	float distance;
	do
	{
		printf("\nEnter the delivery distance in km: ");
		scanf("%f", &distance);
		if (distance < 0)
		{
			printf("Invalid Distance Entered, it cannot be negative");
		}
	} while (distance < 0);
	return distance;
}

int getMembership()
{
	int member;
	do
	{
		printf("\nAre you a member? (1 -> Yes, 0 -> No): ");
		scanf("%d", &member);
		if (member != 0 && member != 1)
		{
			printf("Invalid Choice Entered, please enter 1 or 0");
		}
	} while (member != 0 && member != 1);
	return member;
}

float calculateBaseCharge(float weight)
{
	float charge;
	if (weight <= 2)
	{
		charge = 200;
	}
	else if (weight <= 5) 
	{
		charge = 400;
	}
	else 
	{
		charge = 700;
	}
	return charge;
}

float calculateDistanceCharge(float distance)
{
	
	float charge = 0;
	if (distance > 10)
	{
		charge = (distance - 10) * 20;
	}
	return charge;
}

float calculateDiscount(float totalCharges, int member)
{
	float discount = 0;
	if (member == 1 && totalCharges > 1000)
	{
		discount = totalCharges * 10 / 100;
	}
	return discount;
}

void displayCharges(float baseCharge, float distanceCharge, float discount, float finalAmount)
{
	printf("\n\n----- Delivery Charges -----");
	printf("\nBase charges: Rs. %.2f", baseCharge);
	printf("\nDistance charges: Rs. %.2f", distanceCharge);
	printf("\nDiscount: Rs. %.2f", discount);
	if (discount == 0)
	{
		printf(" (No discount applied)");
	}
	printf("\nFinal amount: Rs. %.2f", finalAmount);
}

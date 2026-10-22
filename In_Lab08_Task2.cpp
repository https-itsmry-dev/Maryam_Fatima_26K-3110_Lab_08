# include <stdio.h>
void welcome();
void showMenu(float prices[]);
float getPrice(float prices[], int choice);
float ItemPrice(float price, int quantity);
float Subtotal(float subtotal, float itemTotal);
float Discount(float subtotal);
float FinalBill(float subtotal, float discount);
void displayReceipt(float prices[], int quantities[], float subtotal, float discount, float finalBill);
int askContinue();
int main()
{
	float prices[5] = {250, 120, 400, 180, 100};
	int quantities[5] = {0, 0, 0, 0, 0};
	int choice, quantity, again = 1;
	float price, itemTotal, subtotal = 0, discount, finalBill;
	printf("This is a program written in C to simulate a shopping management system using functions");
	welcome();
	while (again == 1)
	{
		showMenu(prices);
		printf("\nEnter the product number: ");
		scanf("%d", &choice);
		printf("\nEnter the quantity: ");
		scanf("%d", &quantity);
		if (choice >= 1 && choice <= 5 && quantity > 0)
		{
			price = getPrice(prices, choice);
			itemTotal = ItemPrice(price, quantity);
			quantities[choice - 1] = quantities[choice - 1] + quantity;
			subtotal = Subtotal(subtotal, itemTotal);
			printf("\nProduct %d added: %d x Rs. %.2f = Rs. %.2f", choice, quantity, price, itemTotal);
		}
		else
		{
			printf("\nInvalid product number or quantity, nothing was added");
		}
		again = askContinue();
	}
	discount = Discount(subtotal);
	finalBill = FinalBill(subtotal, discount);
	displayReceipt(prices, quantities, subtotal, discount, finalBill);
	return 0;
}

void welcome()
{
	printf("\n\n----- Welcome to the Shopping Store -----");
}

void showMenu(float prices[])
{
	int i;
	printf("\n\n----- Product Menu -----");
	for (i = 0; i < 5; i++)
	{
		printf("\nProduct %d - Rs. %.2f", i + 1, prices[i]);
	}
}

float getPrice(float prices[], int choice)
{
	return prices[choice - 1];
}
float ItemPrice(float price, int quantity)
{
	return price * quantity;
}

float Subtotal(float subtotal, float itemTotal)
{
	return subtotal + itemTotal;
}

float Discount(float subtotal)
{
	float discount = 0;
	if (subtotal >= 2000)
	{
		discount = subtotal * 10 / 100;
	}
	return discount;
}

float FinalBill(float subtotal, float discount)
{
	return subtotal - discount;
}

void displayReceipt(float prices[], int quantities[], float subtotal, float discount, float finalBill)
{
	int i;
	printf("\n\n----- Shopping Receipt -----");
	for (i = 0; i < 5; i++)
	{
		if (quantities[i] > 0)
		{
			printf("\nProduct %d | Quantity: %d | Price: Rs. %.2f | Total: Rs. %.2f", i + 1, quantities[i], prices[i], ItemPrice(prices[i], quantities[i]));
		}
	}
	printf("\nSubtotal: Rs. %.2f", subtotal);
	printf("\nDiscount: Rs. %.2f", discount);
	printf("\nFinal payable amount: Rs. %.2f", finalBill);
}

int askContinue()
{
	int again;
	printf("\n\nDo you want to continue shopping? Enter 1-->Yes and 0--> No");
	printf("\nEnter the number: ");
	scanf("%d", &again);
	return again;
}


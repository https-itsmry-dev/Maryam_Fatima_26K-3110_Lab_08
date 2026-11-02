#include <stdio.h>
#define BRANCHES 2
#define PRODUCTS 3
#define WEEKS 4
int main()
{
	int sales[BRANCHES][PRODUCTS][WEEKS];
	int productTotal[BRANCHES][PRODUCTS];
	int branchTotal[BRANCHES];
	int weekTotal[WEEKS];
	int b, p, w, highest, tieCount;

	printf("This is a program written in C to practise 3D arrays (Monthly Sales Analysis)");


	for (b = 0; b < BRANCHES; b++)
	{
		for (p = 0; p < PRODUCTS; p++)
		{
			for (w = 0; w < WEEKS; w++)
			{
				do
				{
					printf("\nEnter quantity sold - Branch %d, Product %d, Week %d: ", b + 1, p + 1, w + 1);
					scanf("%d", &sales[b][p][w]);
					if (sales[b][p][w] < 0)
					{
						printf("Invalid Quantity Entered, it cannot be negative");
					}
				} while (sales[b][p][w] < 0);
			}
		}
	}


	for (b = 0; b < BRANCHES; b++)
	{
		branchTotal[b] = 0;
	}
	for (w = 0; w < WEEKS; w++)
	{
		weekTotal[w] = 0;
	}


	for (b = 0; b < BRANCHES; b++)
	{
		for (p = 0; p < PRODUCTS; p++)
		{
			productTotal[b][p] = 0;
			for (w = 0; w < WEEKS; w++)
			{
				productTotal[b][p] = productTotal[b][p] + sales[b][p][w];
				branchTotal[b] = branchTotal[b] + sales[b][p][w];
				weekTotal[w] = weekTotal[w] + sales[b][p][w];
			}
		}
	}

	//Total quantity of each product in each branch
	printf("\n\n----- Total Quantity Sold for Each Product in Each Branch -----");
	for (b = 0; b < BRANCHES; b++)
	{
		for (p = 0; p < PRODUCTS; p++)
		{
			printf("\nBranch %d - Product %d: %d units", b + 1, p + 1, productTotal[b][p]);
		}
	}

	printf("\n\n----- Highest Selling Product in Each Branch -----");
	for (b = 0; b < BRANCHES; b++)
	{
		highest = productTotal[b][0];
		for (p = 1; p < PRODUCTS; p++)
		{
			if (productTotal[b][p] > highest)
			{
				highest = productTotal[b][p];
			}
		}
		if (highest == 0)
		{
			printf("\nBranch %d: No product was sold", b + 1);
		}
		else
		{
			tieCount = 0;
			for (p = 0; p < PRODUCTS; p++)
			{
				if (productTotal[b][p] == highest)
				{
					tieCount++;
					printf("\nBranch %d: Product %d with %d units", b + 1, p + 1, highest);
				}
			}
			if (tieCount > 1)
			{
				printf("\n(There is a tie in Branch %d)", b + 1);
			}
		}
	}

	printf("\n\n----- Overall Sales of Each Week -----");
	for (w = 0; w < WEEKS; w++)
	{
		printf("\nWeek %d: %d units", w + 1, weekTotal[w]);
	}
	highest = weekTotal[0];
	for (w = 1; w < WEEKS; w++)
	{
		if (weekTotal[w] > highest)
		{
			highest = weekTotal[w];
		}
	}
	printf("\n\nWeek(s) with the highest overall sales (%d units):", highest);
	for (w = 0; w < WEEKS; w++)
	{
		if (weekTotal[w] == highest)
		{
			printf(" Week %d", w + 1);
		}
	}

	
	printf("\n\n----- Total Quantity Sold by Each Branch -----");
	for (b = 0; b < BRANCHES; b++)
	{
		printf("\nBranch %d: %d units", b + 1, branchTotal[b]);
	}
	if (branchTotal[0] > branchTotal[1])
	{
		printf("\n\nBranch 1 sold the greatest quantity of products");
	}
	else if (branchTotal[1] > branchTotal[0])
	{
		printf("\n\nBranch 2 sold the greatest quantity of products");
	}
	else
	{
		printf("\n\nBoth branches sold the same quantity of products");
	}
	return 0;
}

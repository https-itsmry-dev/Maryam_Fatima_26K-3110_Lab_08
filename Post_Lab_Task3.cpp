#include <stdio.h>
#define WARDS 2
#define PATIENTS 3
#define READINGS 4
int main()
{
	float temp[WARDS][PATIENTS][READINGS];
	float average[WARDS][PATIENTS];
	int countAbove[WARDS][PATIENTS];
	float highest;
	int w, p, r, hw, hp, hr, totalAbove = 0, highFeverFound = 0;

	printf("This is a program written in C to practise 3D arrays (Hospital Temperature Monitoring)");

	//Taking input (with validation)
	for (w = 0; w < WARDS; w++)
	{
		for (p = 0; p < PATIENTS; p++)
		{
			printf("\n\nWard %d - Patient %d", w + 1, p + 1);
			for (r = 0; r < READINGS; r++)
			{
				do
				{
					printf("\nEnter temperature reading %d (30 to 45 C): ", r + 1);
					scanf("%f", &temp[w][p][r]);
					if (temp[w][p][r] < 30 || temp[w][p][r] > 45)
					{
						printf("Invalid Temperature Entered, please try again");
					}
				} while (temp[w][p][r] < 30 || temp[w][p][r] > 45);
			}
		}
	}

	//Average temperature and count of readings above 37.5
	printf("\n\n----- Average Temperature of Each Patient -----");
	for (w = 0; w < WARDS; w++)
	{
		for (p = 0; p < PATIENTS; p++)
		{
			float sum = 0;
			countAbove[w][p] = 0;
			for (r = 0; r < READINGS; r++)
			{
				sum = sum + temp[w][p][r];
				if (temp[w][p][r] > 37.5)
				{
					countAbove[w][p]++;
					totalAbove++;
				}
			}
			average[w][p] = sum / READINGS;
			printf("\nWard %d - Patient %d: Average = %.2f C", w + 1, p + 1, average[w][p]);
		}
	}

	//Readings above 37.5
	printf("\n\n----- Readings Above 37.5 C -----");
	for (w = 0; w < WARDS; w++)
	{
		for (p = 0; p < PATIENTS; p++)
		{
			printf("\nWard %d - Patient %d: %d reading(s)", w + 1, p + 1, countAbove[w][p]);
		}
	}
	printf("\n\nTotal readings above 37.5 C in the hospital: %d", totalAbove);
	if (totalAbove == 0)
	{
		printf("\nNo reading was above 37.5 C");
	}

	//Highest temperature in each ward
	printf("\n\n----- Highest Temperature in Each Ward -----");
	for (w = 0; w < WARDS; w++)
	{
		highest = temp[w][0][0];
		hp = 0;
		hr = 0;
		for (p = 0; p < PATIENTS; p++)
		{
			for (r = 0; r < READINGS; r++)
			{
				if (temp[w][p][r] > highest)
				{
					highest = temp[w][p][r];
					hp = p;
					hr = r;
				}
			}
		}
		hw = w;
		printf("\nWard %d: %.2f C (Patient %d, Reading %d)", hw + 1, highest, hp + 1, hr + 1);
	}

	//Patients whose average exceeds 38
	printf("\n\n----- Patients with Average Temperature Above 38 C -----");
	for (w = 0; w < WARDS; w++)
	{
		for (p = 0; p < PATIENTS; p++)
		{
			if (average[w][p] > 38)
			{
				highFeverFound = 1;
				printf("\nWard %d - Patient %d (Average: %.2f C)", w + 1, p + 1, average[w][p]);
			}
		}
	}
	if (highFeverFound == 0)
	{
		printf("\nNo patient has an average temperature above 38 C");
	}
	return 0;
}

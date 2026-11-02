#include <stdio.h>
#define SECTIONS 2
#define STUDENTS 3
#define SUBJECTS 4
int main()
{
	int marks[SECTIONS][STUDENTS][SUBJECTS];
	int total[SECTIONS][STUDENTS];
	float average[SECTIONS][STUDENTS];
	int sectionTotal[SECTIONS];
	float sectionAverage[SECTIONS];
	int s, st, sub, highestTotal, tieCount, passCount = 0;

	printf("This is a program written in C to practise 3D arrays (Student Result Analysis)");


	for (s = 0; s < SECTIONS; s++)
	{
		for (st = 0; st < STUDENTS; st++)
		{
			printf("\n\nSection %d - Student %d", s + 1, st + 1);
			for (sub = 0; sub < SUBJECTS; sub++)
			{
				do
				{
					printf("\nEnter marks of Subject %d (0 to 100): ", sub + 1);
					scanf("%d", &marks[s][st][sub]);
					if (marks[s][st][sub] < 0 || marks[s][st][sub] > 100)
					{
						printf("Invalid Marks Entered, please try again");
					}
				} while (marks[s][st][sub] < 0 || marks[s][st][sub] > 100);
			}
		}
	}


	for (s = 0; s < SECTIONS; s++)
	{
		sectionTotal[s] = 0;
		for (st = 0; st < STUDENTS; st++)
		{
			total[s][st] = 0;
			for (sub = 0; sub < SUBJECTS; sub++)
			{
				total[s][st] = total[s][st] + marks[s][st][sub];
			}
			average[s][st] = (float)total[s][st] / SUBJECTS;
			sectionTotal[s] = sectionTotal[s] + total[s][st];
		}
		sectionAverage[s] = (float)sectionTotal[s] / (STUDENTS * SUBJECTS);
	}

	printf("\n\n----- Total and Average Marks of Each Student -----");
	for (s = 0; s < SECTIONS; s++)
	{
		for (st = 0; st < STUDENTS; st++)
		{
			printf("\nSection %d - Student %d | Total: %d | Average: %.2f", s + 1, st + 1, total[s][st], average[s][st]);
		}
	}

	
	printf("\n\n----- Highest Scoring Student in Each Section -----");
	for (s = 0; s < SECTIONS; s++)
	{
		highestTotal = total[s][0];
		for (st = 1; st < STUDENTS; st++)
		{
			if (total[s][st] > highestTotal)
			{
				highestTotal = total[s][st];
			}
		}
		tieCount = 0;
		for (st = 0; st < STUDENTS; st++)
		{
			if (total[s][st] == highestTotal)
			{
				tieCount++;
				printf("\nSection %d: Student %d with total marks %d", s + 1, st + 1, highestTotal);
			}
		}
		if (tieCount > 1)
		{
			printf("\n(There is a tie in Section %d)", s + 1);
		}
	}


	for (s = 0; s < SECTIONS; s++)
	{
		for (st = 0; st < STUDENTS; st++)
		{
			if (average[s][st] >= 50)
			{
				passCount++;
			}
		}
	}
	printf("\n\nNumber of students whose average is at least 50: %d", passCount);
	if (passCount == 0)
	{
		printf("\nNo student has an average of 50 or more");
	}
	else if (passCount == SECTIONS * STUDENTS)
	{
		printf("\nAll students have an average of 50 or more");
	}


	printf("\n\n----- Overall Average of Each Section -----");
	for (s = 0; s < SECTIONS; s++)
	{
		printf("\nSection %d overall average: %.2f", s + 1, sectionAverage[s]);
	}
	if (sectionTotal[0] > sectionTotal[1])
	{
		printf("\n\nSection 1 has the highest overall average");
	}
	else if (sectionTotal[1] > sectionTotal[0])
	{
		printf("\n\nSection 2 has the highest overall average");
	}
	else
	{
		printf("\n\nBoth sections have the same overall average");
	}
	return 0;
}

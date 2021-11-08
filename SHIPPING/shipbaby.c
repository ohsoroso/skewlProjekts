/*
	Author: Zakary Smith
	Date: 10/24/2021

	Create a program that calculates shipping charge based on miles shipped and 
	package weight with a flat fee of $10 if the package travels over 1,000 miles
	while not allowing packages over 50lbs. to be shipped at all.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double packageWeight, packageDist, shipRate;

	// User enters the weight
	printf("Enter the weight of the package:");
	scanf("%lf", &packageWeight);

	// User enters the mileage
	printf("Enter the amount of miles it would take:");
	scanf("%lf", &packageDist);

	// When weight is greater than 50
	if (packageWeight > 50.0) {
		printf("Sorry, we only ship packages of 50 pounds or less.");
		system("pause");
		return 0;
	}

	// When weight is less than or equal 10
	if (packageWeight <= 10.0)
		shipRate = 3.00;

	// When weight is greater than 10
	else
		shipRate = 5.00;

	// Calculate and display the result
	if (packageDist > 1000.0)
	{
		printf("Shipping charge is $%.2lf \n", (int)((packageDist + 499.0) / 500.0) * shipRate +10);
	}

	else
		printf("Shipping charge is $%.2lf \n", (int)((packageDist + 499.0) / 500.0) * shipRate);

	system("pause");
}
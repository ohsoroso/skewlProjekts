//Program that lets user enter grades and calculate how many passed/failed
//and showing the percentage of grades that were passing
#include <stdio.h>
#include <stdlib.h>

int main () 
{
//Initializing variables and asking for input
int grades = 0, passingGrades = 0, failingGrades = 0, totalGrades = 0;
do {
printf ("Enter some grades !");
scanf ("%i", &grades);
//Setting up what constitutes a passing or failing grade/valid grade 
if (grades < 70 && grades >= 0)
{
++failingGrades;
}
if (grades >= 70 && grades <= 100)
{
++passingGrades;
}
if (grades > 100)
{
printf ("Not a valid grade ya dork ! \n");
}
}
while (grades != -1);
//Calculating percentage of grades and printing how many failed/passed
totalGrades = failingGrades + passingGrades;
printf ("%i passed\n", passingGrades);
printf ("%i failed\n", failingGrades);
printf ("%i percent passed\n", 100 * passingGrades / totalGrades);
system("pause");
}
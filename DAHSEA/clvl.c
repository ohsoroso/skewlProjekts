#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  printf("Sea Level calculator for 2020 - 2050\n");
  printf("This program uses data from NASA to calculate sea levels.\n");

  int x;
  double test;
  double newAvrg;
  double futureSeaLevel [6];
  double avrg [28];
  double seaLevelChange;
  double seaLevels [28] = {-38.56, -31.19, -26.02, -27.71, -26.29, -20.28, -25.26, -16.76, -14.69, -10.38, -5.12, -1.60,
   0.75, 3.61, 5.33, 5.08, 8.75, 15.10, 10.07, 18.74, 28.57, 27.70, 33.37, 44.15, 42.16, 47.52, 51.60, 54.67};

  for (x = 0; x < 28; x++) //Calculates difference of all years of sea level rise.
  {
    avrg[x] = seaLevels[x] - seaLevels[x+1];
  }
  
  for (x = 0; x < 28; x++) //Adds the differences up so they can be averaged out.
  {
    seaLevelChange = seaLevelChange += avrg[x];
  }
  
  newAvrg = seaLevelChange / 28;
  
  for (x = 0; x < 6; x++) //Incrementing for 2025 - 2050 sea levels.
  {
    futureSeaLevel[x] = seaLevels[27] + newAvrg * 5;
    futureSeaLevel[1] = futureSeaLevel[x] + newAvrg * 5;
    futureSeaLevel[2] = futureSeaLevel[1] + newAvrg * 5;
    futureSeaLevel[3] = futureSeaLevel[2] + newAvrg * 5;
    futureSeaLevel[4] = futureSeaLevel[3] + newAvrg * 5;
    futureSeaLevel[5] = futureSeaLevel[4] + newAvrg * 5;
  }
  //Printing results.
  printf("2020 Sea Levels are:%.2lf\n", seaLevels[27]);
  printf("2025 Sea Levels are:%.2lf\n", futureSeaLevel[0]);
  printf("2030 Sea Levels are:%.2lf\n", futureSeaLevel[1]);
  printf("2035 Sea levels are:%.2lf\n", futureSeaLevel[2]);
  printf("2040 Sea Levels are:%.2lf\n", futureSeaLevel[3]);
  printf("2045 Sea Levels are:%.2lf\n", futureSeaLevel[4]);
  printf("2050 Sea Levels are:%.2lf\n", futureSeaLevel[5]);
  printf("GSFC. 2021. Global Mean Sea Level Trend from Integrated Multi-Mission Ocean Altimeters TOPEX/Poseidon, Jason-1, OSTM/Jason-2, and Jason-3 Version 5.1. Ver. 5.1 PO.DAAC, CA, USA. Dataset accessed [2021-11-28] at https://doi.org/10.5067/GMSLM-TJ151.");

  system ("pause");
}
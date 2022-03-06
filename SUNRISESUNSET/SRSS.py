import matplotlib.pyplot as plt
import csv

from matplotlib import markers

x = []
y = []
y2 = []

suns = r'C:\Users\notfu\Documents\GitHub\SkewlProjekts\SUNRISESUNSET\sr_ss_clean.csv'
with open(suns, 'r') as File:
  lines = csv.reader(File, delimiter=',')
  for row in lines:
    x.append(row[0])
    y.append(float(row[1]))
    y2.append(float(row[2]))

plt.plot(x, y, y2)
plt.xticks(x[::31],  rotation='vertical')
plt.xlabel('Dates')
plt.ylabel('Time')
plt.title('Sunrise and Sunset Data 2022')
plt.grid('major', 'both')
plt.show()
import matplotlib.pyplot as plt
import csv

from matplotlib import markers

x = []
y = []
hurri = r'C:\Users\notfu\Documents\GitHub\SkewlProjekts\INFOGRAPH\hurricanes.csv'
with open(hurri, 'r') as File:
  lines = csv.reader(File, delimiter=',')
  for row in lines:
    x.append(row[3])
    y.append(row[1])
plt.pie(x, labels = y)

plt.title('Hurricane Test')
plt.show()
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import numpy as np
import sys
import re

#Text and arguments processing to retrieve data from C++ script
x_coordinates = []
y_coordinates = []
pt_x = []
pt_y = []
for arg in sys.argv:
    if (re.search('\d+', arg)):
        points = arg.split('+')
        controlPoints = points[0].split('-')
        calculatedPoints = points[1].split('-')
        for cpt in controlPoints:
            cpt = cpt[1:-1]
            coord = cpt.split(',')
            if(len(coord) > 1):
                pt_x.append(float(coord[0]))
                pt_y.append(float(coord[1]))

        for pt in calculatedPoints:
            pt = pt[1:-1]
            coord = re.split(',', pt)
            if(len(coord) > 1):
                x_coordinates.append(float(coord[0]))
                y_coordinates.append(float(coord[1]))

fig = plt.figure()
ax = fig.add_subplot(111)
#display control points
ax.scatter(pt_x, pt_y, c='r', marker='o')
#display curve
ax.plot(x_coordinates, y_coordinates, c ='b')
ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')

plt.show() 


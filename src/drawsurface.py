import sys
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import re

#Text and arguments processing to retrieve data from C++ script
x_guide = []
y_guide = []
z_guide = []
x_gene = []
y_gene = []
z_gene = []
pt_x = []
pt_y = []
pt_z = []
row = 0
col = 0
for arg in sys.argv:
    if (re.search('\d+', arg)):
        points = arg.split('+')
        controlPoints = points[0].split('/')
        guidePoints = points[1].split('/')
        genePoints = points[2].split('/')
        row = int(points[3].split('/')[0])
        col = int(points[3].split('/')[1])
        
        for pt in controlPoints:
            pt = pt[1:-1]
            coord = pt.split(',')
            if(len(coord) > 1):
                pt_x.append(float(coord[0]))
                pt_y.append(float(coord[1]))
                pt_z.append(float(coord[2]))

        for pt in guidePoints:
            pt = pt[1:-1]
            coord = pt.split(',')
            if(len(coord) > 1):
                x_guide.append(float(coord[0]))
                y_guide.append(float(coord[1]))
                z_guide.append(float(coord[2]))

        for pt in genePoints:
            pt = pt[1:-1]
            coord = pt.split(',')
            if(len(coord) > 1):
                x_gene.append(float(coord[0]))
                y_gene.append(float(coord[1]))
                z_gene.append(float(coord[2]))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
#display generatrix points
ax.scatter(x_gene, y_gene, z_gene, marker='o', c='b')
#display control points
ax.scatter(pt_x, pt_y, pt_z, marker='o', c='r')

#display surface
nbguide = int(len(x_guide)/col)
nbgene = int(len(x_gene)/nbguide)
for i in range(nbguide):
    x = []
    y = []
    z = []
    for j in range(nbgene):
        x.append(x_gene[i*nbgene+j])
        y.append(y_gene[i*nbgene+j])
        z.append(z_gene[i*nbgene+j])
        ax.plot(x, y ,z, c='b')
for i in range(nbgene):
    x = []
    y = []
    z = []
    for j in range(nbguide):
        x.append(x_gene[i+nbgene*j])
        y.append(y_gene[i+nbgene*j])
        z.append(z_gene[i+nbgene*j])
        ax.plot(x, y ,z, c='b')

ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
ax.set_zlim(0, 10)
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
plt.show()
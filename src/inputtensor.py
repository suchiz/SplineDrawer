from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
x = []
y = []
z = []
points = []

def onclick(event):
    s = gety(event.xdata, event.ydata)
    s = s.replace(" ", "")
    pt = s.split(',')
    pt_x = pt[0][2:]
    pt_y = pt[1][2:]
    pt_z = pt[2][2:]
    points.append((float(pt_x), float(pt_y), float(pt_z)))
    x.append(float(pt_x))
    y.append(float(pt_y))
    z.append(float(pt_z))
    ax.scatter(x, y, z, c='r', marker='o')
    fig.canvas.draw()

def gety(x,y):
    # store the current mousebutton
    b = ax.button_pressed
    # set current mousebutton to something unreasonable
    ax.button_pressed = -1
    # get the coordinate string out
    s = ax.format_coord(x,y)
    # set the mousebutton back to its previous state
    ax.button_pressed = b
    return s

ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
ax.set_zlim(0, 10)
cid = fig.canvas.mpl_connect('button_press_event', onclick)

plt.show()
for p in points:
    print(p)
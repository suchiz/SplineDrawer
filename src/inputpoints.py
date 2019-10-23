from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()
x = []
y = []
points = []

#retrieve coordinates and display control points
def onclick(event):
    points.append((event.xdata, event.ydata))
    x.append(event.xdata)
    y.append(event.ydata)
    ax.scatter(x, y, c='r', marker='o')
    fig.canvas.draw()
    
ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
#click event
cid = fig.canvas.mpl_connect('button_press_event', onclick)
plt.show()

#send data to C++ script
for p in points:
    print(p)

import pandas as pd
import csv
import matplotlib.pyplot as plt
import numpy as np
import statistics

from matplotlib.ticker import (MultipleLocator, FormatStrFormatter,
                               AutoMinorLocator)


 


points = [10,100,1000,5000,10000]
labels = ["arraloc()","ther"]

arralloc = [0.0, 0.2, 15.3,572.2,1526.1]


arralloc = np.array(arralloc)
points  = np.array(points )

fig, ax = plt.subplots() 

plt.plot( points, arralloc,"-")



plt.legend(labels)
ax.set_xlim(left =0,right=10000)
ax.set_ylim(bottom=0.0,top=2000.0)


ax.xaxis.set_major_locator(MultipleLocator(1000))
ax.xaxis.set_minor_locator(MultipleLocator(500))

ax.yaxis.set_major_formatter(FormatStrFormatter('%.2f'))
ax.yaxis.set_major_locator(MultipleLocator(100))
ax.yaxis.set_minor_locator(MultipleLocator(10))


ax.tick_params(which='minor', length=3, color='black',width=1)
ax.tick_params(which='major', length=10, color='black',width=1.5)

plt.ylabel('Total Heap Allocation (MB)')
plt.xlabel('Grid Size (L)')

	
# Turn on the minor TICKS, which are required for the minor GRID
ax.grid(which='minor', linestyle=':', linewidth=0.2, color='black')
ax.grid(which='major', linestyle='--', linewidth=0.2, color='red')
ax.grid()

plt.show()

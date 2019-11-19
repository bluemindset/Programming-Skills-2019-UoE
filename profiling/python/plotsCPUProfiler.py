import pandas as pd
import csv
import matplotlib.pyplot as plt
import numpy as np
import statistics

from matplotlib.ticker import (MultipleLocator, FormatStrFormatter,
                               AutoMinorLocator)


 


points = [0.00001,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.999]
labels = ["map_update()","cluster_compare()","body_pgm_file()","random_uniform()"]

map_update = [99.5,99.4,99.4,99.5,99.3, 85.9, 64.2,44.2,27.6, 18.6,5.3]
cluster_compare= [0.1,0.1,0.1,0.2,0.1, 2.7, 4.5, 9.3,17.6,18.5,21.1 ]
body_pgm_file= [0.1,0.1,0.1,0.1,0.1, 0.5, 6.0, 7.0,10.3,22.7,15.8 ]
random_uniform = [0.0,0.1,0.1,0.1,0.1, 1.1 ,6.0, 11.6,13.8,9.5,15.8 ]



map_update = np.array(map_update)
points  = np.array(points )

fig, ax = plt.subplots() 

#ax.errorbar([1,2],[avg,2],range,linestyle ='-' ,elinewidth=0.5,capsize =5,capthick=0.5,ecolor= "red", c= "black", marker=".")
# #ax.errorbar([1,2],[avg,2],ste,linestyle ='-' ,elinewidth=0.5,capsize =5,capthick=0.5,ecolor= "red", c= "black", marker=".")

# #Plot the graph
plt.plot( points, map_update)
plt.plot( points, cluster_compare)
plt.plot( points, body_pgm_file)
plt.plot( points, random_uniform)

#plt.errorbar(points,gavg,gstd,fmt = "g",linestyle="dashed",linewidth = 1,elinewidth=0.5,capsize =3,capthick=1.5,ecolor= "g",marker=".")
plt.legend(labels)
# Customize the minor grid
ax.set_xlim(left =0,right=1)
ax.set_ylim(bottom=0.0,top=100.0)


ax.xaxis.set_major_locator(MultipleLocator(0.1))
ax.xaxis.set_minor_locator(MultipleLocator(0.05))

ax.yaxis.set_major_formatter(FormatStrFormatter('%.2f'))
ax.yaxis.set_major_locator(MultipleLocator(10))
ax.yaxis.set_minor_locator(MultipleLocator(1))


ax.tick_params(which='minor', length=3, color='black',width=1)
ax.tick_params(which='major', length=10, color='black',width=1.5)

plt.ylabel('Percentage of CPU profiling samples (%)')
plt.xlabel('RHO Fraction')

	
# Turn on the minor TICKS, which are required for the minor GRID
ax.grid(which='minor', linestyle=':', linewidth=0.2, color='black')
ax.grid(which='major', linestyle='--', linewidth=0.2, color='red')
ax.grid()

plt.show()

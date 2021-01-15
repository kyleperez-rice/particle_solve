import math
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

solution = pd.read_csv (r'/home/kyleperez/cppstuff/central_force/data.csv', header=0)

###ROWS AVAILIBLE by default
#time - time at which the data is taken
#
#xpos - x position of a particle
#ypos - y...
#zpos - z...
#
#xvel - x velocity of a particle
#yvel - y...
#zvel - z...
#
#xacc - x acceleration of a particle
#yacc - y...
#zacc - z...
#
#mass - mass of a particle
#charge - charge of a particle


##Sets the figure and its limits
fig = plt.figure()
plt.xlim(-1, 5)
plt.ylim(0, 2)
graph, = plt.plot([], [], 'o')


#NUMBER OF PARTICLES USED IN SIMULATION
#	-See the particle_solve.cpp program for this
num_particles = 5

#Animation function used to animate the system
def animate(i):
	#We make a numpy array from the solution, only taking the numbers within a given time
	#	A given element of time should have num_particles in it
	x = solution['xpos'][num_particles*i : num_particles*(i+1)]
	y = solution['ypos'][num_particles*i: num_particles*(i+1)]
	graph.set_data(x, y)
	return graph
	

#Animate the data
animation = FuncAnimation(fig, func=animate, repeat=True, interval=1000)
plt.show()

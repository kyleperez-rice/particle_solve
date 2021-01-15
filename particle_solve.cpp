#include <iostream>
#include <cmath>//Lets us use the abs and sqrt functions
#include <vector>//We store our data in a vector
#include <fstream>//Lets us write to a file
#include "particle.h"//Includes the 'particle' class which has all relevant particle properties
#include "particle_solve_functions.h"//Includes initial particle positions/velocities
#include "forces.h"//Includes the 'forces' class which has our internal+external forces
#include "csv_functions.h"//Lets us write data to a file

using namespace std;


int main() {

	
	//SIMULATION PROPERTIES:
	double tmax = .015;//The time at which the simulation stops running
	int tsteps = 10;//How many steps the simulation runs over
	
	int num_particles = 5;//Number of particles in simulation
	//Make sure it's compatible with your initial distribution functions
	
	double dt = tmax/(double)tsteps;//Timestep size
	
	
	//OUTPUT FILE PROPERTIES
	//Respective names of the .csv and .txt
		//Can output txt file as a .tsv if you want to; just swap file ending to tsv
	string csv_name = "data.csv";
	string txt_name = "data.txt";
	
	//Titles of the header of the files
	//We get these from the class elements of the 'particle' class.
		//Things like mass and charge many not need to be saved, so do at your own discression.
	vector<string> titles = {"time", "xpos", "ypos", "zpos", "xvel", "yvel", "zvel", "xacc", "yacc", "zacc", "mass", "charge"};
	
	
	
	
	particle d;//Generic particle element
	forces force;//Generic forces element
	
	//A list of the particles at a given time
	vector<particle> particles;
	
	//A copy of that list
	vector<particle> c_particles;
	
	//A list of the particles at each instance of time
	//Outermost vector element correspond to different times
	vector<vector<particle>> data;
	
	
	
	
	
	
	
	//Creating initial particle properties
	for (int i = 0; i < num_particles; ++i) {
	
		//Create a particle
		particles.push_back(d);
		
		//The simulation starts at t = 0
		particles[i].time = 0.;
		
		//Assign it its properties, velocity, and position
		//according to the distribution functions
		particles[i].mass = particle_mass_dist(i);
		particles[i].charge = particle_charge_dist(i);
		
		particles[i].xvel = init_xvel_dist(i);
		particles[i].yvel = init_yvel_dist(i);
		particles[i].zvel = init_zvel_dist(i);
		
		particles[i].xpos = init_xpos_dist(i);
		particles[i].ypos = init_ypos_dist(i);
		particles[i].zpos = init_zpos_dist(i);
		
	
	
	}//end for
	
	//Dictating initial accelerations
	//Needs to be done after the initializations of velocities and positions
	//since the accelerations can depend on velocities and positions of all particles.
	for (int i = 0; i < num_particles; ++i) {
	
	
		particles[i].xacc = force.net_x(i, particles)/particles[i].mass;
		particles[i].yacc = force.net_y(i, particles)/particles[i].mass;
		particles[i].zacc = force.net_z(i, particles)/particles[i].mass;
	
	
	}//end for
	
	
	//Save 'particles' to our dataset
	data.push_back(particles);
	
	
	//Starting time-simulation
	for (int t = 0; t <= tsteps; ++t) {
	
		
		//Make a copy of our previous run for computation
		c_particles = particles;
		
		for (int i = 0; i < num_particles; ++i) {
		
			//NOTE: THIS USES EULER'S METHOD TO SOLVE FOR THE UPDATED VELOCITIES
			//MAYBE SWITCH TO A MORE ACCURATE METHOD!
			particles[i].time = c_particles[i].time + dt;
			
			particles[i].xvel = c_particles[i].xvel + c_particles[i].xacc*dt;
			particles[i].yvel = c_particles[i].yvel + c_particles[i].yacc*dt;
			particles[i].zvel = c_particles[i].zvel + c_particles[i].zacc*dt;
			
			particles[i].xpos = c_particles[i].xpos + c_particles[i].xvel*dt;
			particles[i].ypos = c_particles[i].ypos + c_particles[i].yvel*dt;
			particles[i].zpos = c_particles[i].zpos + c_particles[i].zvel*dt;
			
			//Note: this assumes that a particle's mass does not change in time
			particles[i].xacc = force.net_x(i, particles)/particles[i].mass;
			particles[i].yacc = force.net_y(i, particles)/particles[i].mass;
			particles[i].zacc = force.net_z(i, particles)/particles[i].mass;
		
		
		}//end for
		
		
		//Save our simulation to our dataset
		data.push_back(particles);
	
	
	}//end for
	
	
	//Save the data
	write_class_csv(csv_name, titles, data);
	write_nice(txt_name, titles, data);
	
	
	return 0;

}//end main

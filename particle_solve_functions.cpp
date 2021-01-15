#include <iostream>
#include <cmath>//Lets us use the abs and pow functions
#include "particle.h"

using namespace std;

/*
TABLE OF CONTENTS

	1a. particle_mass_dist(): lines 121-128
	1b. particle_charge_dist() lines 134-141
	
		input:
			int i
				--i is the particle's number
				
		output: double
				--The mass/charge of the particle
				
		calls:
			NOTHING
				
		called:
			mass: particle_solve.cpp @ line 70
			charge: ^ line 71
	
	
	2a. init_xpos_dist(): lines 186-192
	2b. init_ypos_dist(): lines 198-204
	2c. init_zpos_dist(): lines 210-216
	
		input:
			int i
				--i is the particle's number
	
		output:
			double
				--The initial x/y/z position of particle i
	
		calls:
			NOTHING
			
		called:
			x: particle_solve.cpp @ line 73
			y: ^ line 74
			z: ^ line 75
	
	
	3a. init_xvel_dist(): lines 238-244
	3b. init_yvel_dist(): lines 250-256
	3c. init_zvel_dist(): lines 262-268
	
		input:
			int i
				--i is the particle's number
	
		output:
			double
				--The initial x/y/z velocity of particle i
	
		calls:
			NOTHING
			
		called:
			x: particle_solve.cpp @ line 77
			y: ^ line 78
			z: ^ line 79
	
	
	4. distance_cubed(): lines 282-288
	
		input:
			particle p1, p2
			
		output:
			double
				--The distance between p1 and p2
				
		calls:
			abs, pow functions from <cmath>
			
		called:
			forces.cpp in forces::intpart_x @ line 125
			^ in forces::intpart_y @ line 139
			^ in forces::intpart_z @ line 153
*/



/*SECTION 1:
'Immutable' properties of particles

In this code we use a uniform mass for all particles and 0 charge
	--The code is not built to handle electromagnetism
	
The particle_prop_dist() cooresponds to 'prop' being set for all particles

We can make the initialization significantly more complicated

EX: Alternating Mass
	double p_mass_1 = 1.;
	double p_mass_2 = 2.;
	
	if (i%2 == 0) {
	
		return p_mass_1;
	
	}
	else {
	
		return p_mass_2;
	
	}//end if
	
Will produce particles of alternating mass!

Things work similarly for charge initialization, but mass is used for determining accelerations.
*/

//1a. Mass initialization
double particle_mass_dist(int i) {

	double particle_mass = 1.;

	return particle_mass;


}//end particle_mass_dist




//1b. Charge initialization
double particle_charge_dist(int i) {

	double particle_charge = 0.;

	return particle_charge;


}//end particle_mass_dist




/*SECTION 2:
Initial Positions of particles

In this code we simply set the x distance between particles to be '1', and fix y = 1, and z = 0
	
init_ipos_dist() cooresponds to 'ipos' being set for a given particle with particle index i

We can make the initialization significantly more complicated
	--If we can't find a nice algorithm to generate structures, we can always
	hard-code things!

EX: Alternating Length Separations
	double length_1 = 1.;
	double length_2 = 1.5.;
	double length_3 = 2.;
	
	if (i%3 == 0) {
	
		return length_1*i;
	
	}
	else if (i%3 == 1) {
	
		return length_2*i;
	
	}
	else {
	
		return length_2*i;
	
	}//end if
	
	--If we have 11 particles, they have 'xpos' values of
	: { 0, 1.5, 4, 3, 6, 10, 6, 10.5, 16, 9, 15 }
	--MAKE SURE THAT IF PARTICLES HAVE THE SAME XPOS VALUES (similar for y/z ones)
	THAT THEY HAVE DIFFERENT YPOS or ZPOS VALUES. This prevents a singularity from producing
	NaN values.
*/

//2a. Initial x Positions
double init_xpos_dist(int i) {


	return (double)i;
	

}//end init_xpos_dist




//2b. Initial y Positions
double init_ypos_dist(int i) {


	return 1.;


}//end init_ypos_dist




//2c. Initial z Positions
double init_zpos_dist(int i) {


	return 0.;


}//end init_zpos_dist



/*SECTION 3:
Initial Velocities of particles

In this code we simply set all of the velocities to be 0
	
init_ivel_dist() cooresponds to 'ivel' being set for a given particle with particle index i

We can make the initialization significantly more complicated
	--If we can't find a nice algorithm to generate structures, we can always
	hard-code things!

EX: See previous section

--Warning: try not to make particles collide; this will produce singularities.

*/

//3a. Initial x Velocities
double init_xvel_dist(int i) {


	return 0.;


}//end init_xvel_dist




//3b. Initial y Velocities
double init_yvel_dist(int i) {


	return 0.;


}//end init_yvel_dist




//3c. Initial z Velocities
double init_zvel_dist(int i) {


	return 0.;


}//end init_zvel_dist



/*SECTION 4:
Distance between two vectors cubed

A simple utility function that takes in two particles (which should contain their positions)
and then returns the distance between these particles.
	--Serves as a way to clean up code significantly; just look at the return value

*/

//4. Shorthand for distance cubed
double distance_cubed(particle p1, particle p2) {


	return pow( pow(p1.xpos-p2.xpos, 2.) + pow(p1.ypos-p2.ypos, 2.) + pow(p1.zpos-p2.zpos, 2.), 1.5 );


}//end distance_cubed 

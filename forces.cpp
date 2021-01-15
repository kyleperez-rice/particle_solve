#include <iostream>
#include <vector>
#include "particle.h"
#include "particle_solve_functions.h"
#include "forces.h"

using namespace std;

/*
TABLE OF CONTENTS
	1a. intpart_x(): lines 120-129
	1b. intpart_y(): lines 134-143
	1c. intpart_z(): lines 148-157
	
		input:
			particle p1, p2
			
		output:
			double
				--The internal force between two atoms in x/y/z direction
		
		calls:
			x: distance_cubed in particle_solve_functions.cpp @ line 125
			y: ^ @ line 139
			z: ^ @ line 153
			
		called:
			x: line 190 in internal_x()
			y: line 215 in internal_y()
			z: line 240 in internal_z()
			
			
	2a. internal_x(): lines 178-202
	2b. internal_y(): lines 207-227
	2c. internal_z(): lines 232-252
	
		input:
			int i
			vector<particle> particles
			
		output:
			double
				--The total internal force acting on a particle 'particles[i]'
				in x/y/z direction from all particles in 'particles'
				(except 'particles[i]')
		
		calls:
			x: intpart_x() @ line 190
			y: intpart_y() @ line 215
			z: intpart_z() @ line 240
		
		called:
			x: net_x() @ line 325
			y: ney_y() @ line 336
			z: net_z() @ line 347
		
			
	3a. external_x(): lines 280-286
	3b. external_y(): lines 291-297
	3c. external_z(): lines 302-308
	
		input:
			particle p
				--This includes information about x/y/z positions, velocities,
				etc, so it contains all the relevant grid information.
			
		output:
			double
				--The external force in the x/y/z direction acting on a particle
				(likely position/velocity dependent)
			
		calls:
			x: NOTHING
			y: NOTHING
			z: NOTHING
			
		called:
			x: net_x() @ line 325
			y: net_y() @ line 336
			z: net_z() @ line 347
			
			
	4a. net_x(): lines 324-330
	4b. net_y(): lines 335-341
	4c. net_z(): lines 346-352
	
		input:
			int i
			vector<particle> particles
			
		output:
			double
				--The total force in the x/y/z direction
				Is the sum of the external and internal force in a given direction
		
		calls:
			x: internal_x(), external_x() @ line 325
			y: internal_y(), external_y() @ line 336
			z: internal_z(), external_z() @ line 347
			
		called:
			x: particle_solve.cpp @ lines 91, 125
			y: ^ lines 92, 126
			z: ^ line 93, 127

*/



/*SECTION 1:
Internal forces between particles

In this inline code, we use gravity as the internal force
Gravity scales as G m1 m2 / |r1-r2|**3 * vec(r1-r2)

Each intpart_i() corresponds to the force between particles.
*/

//1a.
double forces::intpart_x(particle p1, particle p2) {


	//Gravitational constant
	double G = 1000.;
	
	return -(G*p1.mass*p2.mass/distance_cubed(p1,p2))*(p1.xpos-p2.xpos);
	

}//end intpart_x



//1b.
double forces::intpart_y(particle p1, particle p2) {


	//Gravitational constant
	double G = 1000.;
	
	return -(G*p1.mass*p2.mass/distance_cubed(p1,p2))*(p1.ypos-p2.ypos);


}//end intpart_y




double forces::intpart_z(particle p1, particle p2) {


	//Gravitational constant
	double G = 1000.;
	
	return -(G*p1.mass*p2.mass/distance_cubed(p1,p2))*(p1.zpos-p2.zpos);


}//end intpart_z



		
/*SECTION 2:
Net internal force on a particle

In this inline code, we use gravity as the internal force
Gravity scales as G m1 m2 / |r1-r2|**3 * vec(r1-r2) and sum over all particles
	ie: fix r1 and sum over all r2 such that r2 != r1

Each internal_i() corresponds to the net internal force on a particle

HOW IT WORKS:
	1. Initialize net internal force to 0.
	2. For every particle in 'particles', calculate intpart_i() for those two particles
		2a. The particles must be different, or else we get a singularity
	3. Add intpart_i to the net internal force
	4. Return the net force
*/
double forces::internal_x(int i, vector<particle> particles) {


	//Internal force starts at  for a given particle particles[i]
	double f = 0;
	
	//For every particle
	for (int j = 0; j < particles.size(); ++j) {
	
	
		//So long as i != j, the field is well defined
		if (i != j) {
		
			//The net internal force is just the sum of all internal forces
			f = f + intpart_x(particles[i], particles[j]);
		
		}//end if
	
	
	}//end for
	
	return f;


}//end internal_x




double forces::internal_y(int i, vector<particle> particles) {


	double f = 0;
	
	for (int j = 0; j < particles.size(); ++j) {
	
	
		if (i != j) {
		
			f = f + intpart_y(particles[i], particles[j]);
		
		}//end if
	
	
	}//end for
	
	return f;


}//end internal_y




double forces::internal_z(int i, vector<particle> particles) {


	double f = 0;
	
	for (int j = 0; j < particles.size(); ++j) {
	
	
		if (i != j) {
		
			f = f + intpart_z(particles[i], particles[j]);
		
		}//end if
	
	
	}//end for
	
	return f;


}//end internal_z




/*SECTION 3:
External force on a particle

In this inline code, we don't have an external force

But, we can build an external force using only properties of the 'particle' class.
	This means that we can have forces that depend on velocity, position, etc.
	
EX: harmonic force in x direction:
	Analytic: F_ext = -k*x
	In code:
		double k = num;
		
		return -k*p.xpos;

EX: Magnetic Force in x direction
	Analytic: F_ext = v_x*B_y - v_y*B_x
	In code:
		double Bx = num1;
		double By = num2;
		
		return p.xvel*By - p.yvel*Bx;
*/
double forces::external_x(particle p) {


	return 0.;


}//end external_x




double forces::external_y(particle p) {


	return 0.;


}//end external_y




double forces::external_z(particle p) {


	return 0.;


}//end external_z




/*SECTION 4:
Total force on a particle

In this inline code, we don't have an external force

We simply take the sum of the internal and external force
	internal_i() is evaluated over all particles
	external_i() is evaluated for a single particle

The function inherits the dependencites of both the internal and external force functions.
*/
double forces::net_x(int i, vector<particle> particles) {


	return internal_x(i, particles) + external_x(particles[i]);


}//end net_x




double forces::net_y(int i, vector<particle> particles) {


	return internal_y(i, particles) + external_y(particles[i]);


}//end net_y




double forces::net_z(int i, vector<particle> particles) {


	return internal_z(i, particles) + external_z(particles[i]);


}//end net_z

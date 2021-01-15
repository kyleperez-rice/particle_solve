#ifndef FORCES_H
#define FORCES_H

#include <iostream>
#include <vector>
#include "particle.h"
#include "particle_solve_functions.h"

using namespace std;


class forces {


	public:
		//Interparticle forces:
		//Forces between 2 given particles
		double intpart_x(particle p1, particle p2);
		double intpart_y(particle p1, particle p2);
		double intpart_z(particle p1, particle p2);
		
		//Total internal forces:
		//Sum of all the interparticle forces in a direction
		//Requires all particles
		double internal_x(int i, vector<particle> particles);
		double internal_y(int i, vector<particle> particles);
		double internal_z(int i, vector<particle> particles);
		
		//External forces:
		//Only requires 1 particle
		double external_x(particle p);
		double external_y(particle p);
		double external_z(particle p);
		
		//Net forces:
		//Sum of internal and external forces
		double net_x(int i, vector<particle> particles);
		double net_y(int i, vector<particle> particles);
		double net_z(int i, vector<particle> particles);
	

};//end force

#endif

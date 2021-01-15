#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>

using namespace std;

//Class that contains the necessary parameters
//to describe the motion of a particle, or several
class particle {


	public:
	
		//Time the particle is at (in its current configuration)
		double time;
		
		// x/y/z postition of the particle
		double xpos;
		double ypos;
		double zpos;
		
		// x/y/z velocity of the particle
		double xvel;
		double yvel;
		double zvel;
		
		// x/y/z acceleration of the particle
		double xacc;
		double yacc;
		double zacc;
		
		// Intrinsic particle properties
		double mass;
		double charge;
		

};//end class
#endif

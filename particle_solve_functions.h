#ifndef PARTICLE_SOLVE_FUNCTIONS_H
#define PARTICLE_SOLVE_FUNCTIONS_H

#include <iostream>
#include <vector>
#include "particle.h"

using namespace std;

//Function that tells us about how the mass of the particles is distributed per index
double particle_mass_dist(int i);

//Tells us about how the particle charges are distributed per index
double particle_charge_dist(int i);

//Tells us about the initial positions of the particles
double init_xpos_dist(int i);
double init_ypos_dist(int j);
double init_zpos_dist(int k);

//Tells us about the initial velocities of the particles
double init_xvel_dist(int i);
double init_yvel_dist(int j);
double init_zvel_dist(int k);

//Shorthand for calculating ((x1-x2)**2+(y1-y2)**2+(z1-z2)**2)**(3/2)
double distance_cubed(particle p1, particle p2);

#endif

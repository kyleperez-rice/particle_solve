#ifndef CSV_FUNCTIONS_H
#define CSV_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "particle.h"

using namespace std;

void write_class_csv(
		string filename,
			//Name of the file
		vector<string> my_titles,
			//Vector that contains the titles of the csv
		vector<vector<particle>> my_data
			//Vector of vectors that contains the data
			/*STRUCTURE:
			vector<particle> represents a grouping of particles
				Each element of vector<particle> is a particle with
				various measurements.
				See the code for the elements of
				the class.
			the outer vector<> represents these groupings at different
			units of time.
			*/
);



void write_nice(
		string filename,
			//Name of the file
		vector<string> my_titles,
			//Vector that contains the titles of the csv
		vector<vector<particle>> my_data
			//Does the same as write_class_csv
			//Except makes it in a more human-readable format
);

#endif

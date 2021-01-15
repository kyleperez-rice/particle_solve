#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "particle.h"
#include "csv_functions.h"

using namespace std;

/*
CSV CREATION FUNCTIONS

Table of Contents:
	1. write_class_csv(): lines 45 - 134
	
		input:
			string filename
			vector<string> my_titles
			vector<vector<particle>> my_data
			
		output:
			a csv with name 'filename'
			
		calls:
			functions from <fstream>
			
		called:
			particle_solve.cpp: line 141
			
			
	2. write_nice(): lines 138 - 216
	
		input:
			string filename
			vector<string> my_titles
			vector<vector<particle>> my_data
			
		output:
			a tsv with name 'filename'
			
		called:
			particle_solve.cpp: line 142
*/

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
) {


	//Creates file 'filename'
	ofstream myFile(filename);
	
	
	// Making the CSV titles
	for (int i = 0; i < my_titles.size(); ++i) {
	
	
		myFile << my_titles[i];
		
		if (i != my_titles.size() - 1) {
		
			myFile << ",";
			
		}//end if
	
	
	}//end for
	
	
	myFile << "\n";
	
	
	//Printing data
	
	//FOR ALL TIMES
	for (int i = 0; i < my_data.size(); ++i) {
	
	
		for (int j = 0; j < my_data[i].size(); ++j) {
		
		
			//Write all the class elements to the file
			myFile << my_data[i][j].time;
			myFile << ",";
			myFile << my_data[i][j].xpos;
			myFile << ",";
			myFile << my_data[i][j].ypos;
			myFile << ",";
			myFile << my_data[i][j].zpos;
			myFile << ",";
			myFile << my_data[i][j].xvel;
			myFile << ",";
			myFile << my_data[i][j].yvel;
			myFile << ",";
			myFile << my_data[i][j].zvel;
			myFile << ",";
			myFile << my_data[i][j].xacc;
			myFile << ",";
			myFile << my_data[i][j].yacc;
			myFile << ",";
			myFile << my_data[i][j].zacc;
			myFile << ",";
			myFile << my_data[i][j].mass;
			myFile << ",";
			myFile << my_data[i][j].charge;
			myFile << '\n';
		
		
		}//end for
	
	
	}//end for
	
	
	myFile.close();
	
	return;
	

}//end write_class_csv



void write_nice(
		string filename,
			//Name of the file
		vector<string> my_titles,
			//Vector that contains the titles of the csv
		vector<vector<particle>> my_data
) {


	//Make a file filename
	ofstream myFile(filename);
	
	
	// Making the titles
	for (int i = 0; i < my_titles.size(); ++i) {
	
	
		myFile << my_titles[i];
		
		if (i != my_titles.size() - 1) {
		
			myFile << "\t\t";
			
		}//end if
		
	
	}//end for
	
	
	myFile << "\n";
	
	
	//Printing data
	
	//FOR ALL TIMES
	for (int i = 0; i < my_data.size(); ++i) {
	
	
		for (int j = 0; j < my_data[i].size(); ++j) {
		
			//Write class data
			myFile << my_data[i][j].time;
			myFile << "\t";
			myFile << my_data[i][j].xpos;
			myFile << "\t";
			myFile << my_data[i][j].ypos;
			myFile << "\t";
			myFile << my_data[i][j].zpos;
			myFile << "\t";
			myFile << my_data[i][j].xvel;
			myFile << "\t";
			myFile << my_data[i][j].yvel;
			myFile << "\t";
			myFile << my_data[i][j].zvel;
			myFile << "\t";
			myFile << my_data[i][j].xacc;
			myFile << "\t";
			myFile << my_data[i][j].yacc;
			myFile << "\t";
			myFile << my_data[i][j].zacc;
			myFile << "\t";
			myFile << my_data[i][j].mass;
			myFile << "\t";
			myFile << my_data[i][j].charge;
			myFile << '\n';
		
		
		}//end for
	
	
	}//end for

	
	myFile.close();
	
	return;
	

}//end write_class_csv

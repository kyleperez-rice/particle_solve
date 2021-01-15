# Executable name and filename
EXECUTABLE = particle_solve
EXECUTABLE_FILE = $(EXECUTABLE).cpp

# Functions that the executable and classes depend on
EXEC_FUNCTIONS = particle_solve_functions.cpp

# Particle class importation
CLASS1 = particle.cpp

# Forces class importation
CLASS2 = forces.cpp

# CSV creation functions
CSV_FUNCTIONS = csv_functions.cpp

# All dependencies
DEPENDS = $(EXECUTABLE_FILE) $(CLASS1) $(CLASS2) $(CSV_FUNCTIONS) $(EXEC_FUNCTIONS)

# Compilation command: uses g++
$(EXECUTABLE): $(DEPENDS)
	g++ \
	-o $(EXECUTABLE) \
	$(DEPENDS)
	
# make clean command
clean:
	rm $(EXECUTABLE)

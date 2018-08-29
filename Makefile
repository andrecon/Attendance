
#INCLUDES_FOLDER... folder that includes all .h files
#SOURCES_FOLDER... folder that includes all .cpp files
#OBJECTS_FOLDER... After compiling, creates a folder name "objects" and puts .o files there

INCLUDES_FOLDER = ./includes
SOURCES_FOLDER = ./sources
OBJECTS_FOLDER = ./objects

# CXX = g++ -std=c++11
CXX = g++
AR = ar

# Debug
# CXXFLAGS = -g3 -O0 -Wall -pedantic
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic

ARFLAGS = rcs
INC = -I$(INCLUDES_FOLDER)

LDFLAGS = -pthread
LDLIBS = 

RM = rm -f

# ADD .cpp FILES HERE
SOURCES = attendance.cpp

OBJECTS = $(patsubst %.cpp, $(OBJECTS_FOLDER)/%.o, $(SOURCES))

LIBRARY = libfoobar.a
EXECUTABLE = out

all: $(LIBRARY) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $(LIBRARY) $(OBJECTS)

$(OBJECTS_FOLDER)/%.o: $(SOURCES_FOLDER)/%.cpp | $(OBJECTS_FOLDER)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $< 

$(OBJECTS_FOLDER): 
	mkdir -p $(OBJECTS_FOLDER)

clean:
	$(RM) $(OBJECTS_FOLDER)/*.o $(LIBRARY) $(EXECUTABLE)

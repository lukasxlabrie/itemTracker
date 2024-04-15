# Simple Makefile for the ItemTracker C++ project

# This is the name of the executable to create
TARGET = ItemTrackerProgram

# Here we define the compiler to use
CXX = g++

# Compilation flags to use (just one for now)
CXXFLAGS = -std=c++11

# The default target is all, it compiles the entire program
all: $(TARGET)

# This target describes how to link the program
$(TARGET): main.o ItemTracker.o
	$(CXX) -o $(TARGET) main.o ItemTracker.o

# This rule explains how to compile main.cpp to main.o
main.o: main.cpp ItemTracker.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# This rule explains how to compile ItemTracker.cpp to ItemTracker.o
ItemTracker.o: ItemTracker.cpp ItemTracker.h
	$(CXX) $(CXXFLAGS) -c ItemTracker.cpp

# Clean target to clean up the compiled files
clean:
	rm -f $(TARGET) main.o ItemTracker.o

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -pedantic

FILE1 = nearestneighbor.cpp
FILE2 = 2opt.cpp
FILE3 = travelingSalesman.cpp
FILE4 = main.cpp
FILE5 = 2-opt-double.cpp
FILES = ${FILE1} ${FILE2} ${FILE3} ${FILE4}

FH1 = nearestneighbor.hpp
FH2 = 2opt.hpp
FH3 = travelingSalesman.hpp

PROGRAM = tsp

default:
	${CXX} ${CXXFLAGS} ${FILES} -o ${PROGRAM}

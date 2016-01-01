#########################################################
# File: makefile
# Author: Jason Goldfine-Middleton
# Description: Builds the Bag data structure.
#########################################################

# C Compiler
CXX = gcc

# Compile Flags
CXXFLAGS = -std=c11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic
CXXFLAGS += -g

####################
### USER SECTION ###
####################

# Source Files
SRC1 = bag.c
SRC2 = main.c
SRCS = ${SRC1} ${SRC2}

# Header Files
HEADER1 = bag.h
HEADERS = ${HEADER1}

# Executables
PROG1 = main
PROGS = ${PROG1}

# Documents
DOC = 

# Archive
ZIP = dsc_bag.zip

# Extras
FILES = 

#####################
### BUILD SECTION ###
#####################

all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

zip:
	zip ${ZIP} ${SRCS} ${HEADERS} ${DOC} ${FILES}  makefile

clean: 
	rm -f ${PROGS} *.o *~


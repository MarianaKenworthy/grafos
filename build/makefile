# Set project directory one level above of Makefile directory. $(CURDIR) is a GNU make variable containing the path to the current working directory
PROJDIR := ..
SOURCEDIR := $(PROJDIR)/source
BUILDDIR := $(PROJDIR)/build
DATADIR := $(PROJDIR)/source

OBJECTS =  $(PROJDIR)/main.c  $(SOURCEDIR)/*.c
DATA = $(DATADIR)/*.bin

RESULT = $(BUILDDIR)/main.out

COMPILER = gcc

all:
	$(COMPILER) -g $(OBJECTS) -o $(RESULT)


clean:
	-rm $(DATA) $(RESULT) 
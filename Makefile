CC=g++
INCLUDEDIR=./include
SOURCEDIR=./src
GRAPHDIR=./graphs
TESTSDIR=./tests
CFLAGS=-I$(INCLUDEDIR) -std=c++11

OBJFILES= $(patsubst ($SOURCEDIR)/%.cpp, $(SOURCEDIR)/%.o, $(wildcard $(SOURCEDIR)/*.cpp))
DEPS= $(wildcard $(INCLUDEDIR)/*.h)
TESTFILE= $(TESTSDIR)/mainTest.cpp

$(SOURCEDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJFILES) $(TESTFILE)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	-rm $(GRAPHDIR)/*.gv

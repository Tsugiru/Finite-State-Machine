ifndef TEST
$(error NO TEST WAS SPECIFIED)
endif

CC=g++
INCLUDEDIR=./include
SOURCEDIR=./src
GRAPHDIR=./graphs
TESTSDIR=./tests
BINDIR=./bin
CFLAGS=-I$(INCLUDEDIR) -std=c++11

OBJFILES= $(patsubst ($SOURCEDIR)/%.cpp, $(SOURCEDIR)/%.o, $(wildcard $(SOURCEDIR)/*.cpp))
DEPS= $(wildcard $(INCLUDEDIR)/*.h)

$(SOURCEDIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJFILES) $(TESTSDIR)/$(TEST).cpp
	$(CC) -o $(BINDIR)/$(TEST) $^ $(CFLAGS)

run: build
	$(BINDIR)/$(TEST)

.PHONY: clean
clean:
	-rm $(GRAPHDIR)/*.gv

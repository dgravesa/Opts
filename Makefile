# Daniel Graves
# test_opts makefile

CXX = c++
CXXFLAGS = -std=c++11 -O2

all: test_opts

test_opts: test_opts.cpp Opts.hpp
	$(CXX) $(CXXFLAGS) test_opts.cpp -o test_opts

clean:
	rm -f test_opts


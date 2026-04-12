CXX := g++ -std=c++17 -INumerical_methods
src := $(wildcard *.cpp)
target := test

$(target): $(src)
	$(CXX) $(src) -o $(target)

clean:
	rm -f $(target)

.PHONY: clean
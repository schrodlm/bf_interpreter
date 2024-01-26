
COMPILER = g++
FLAGS = -std=c++17 -Wall -pedantic

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, build/%.o, ${SOURCES})


.PHONY: compile valgrind clean

bf_int : ${OBJECTS}
	@mkdir -p build/
	${COMPILER} ${FLAGS} $^ -o $@

build/%.o : src/%.cpp
	@mkdir -p build/
	${COMPILER} ${FLAGS} -c $< -o $@

clean: 
	rm -rf build
	rm -f bf_int
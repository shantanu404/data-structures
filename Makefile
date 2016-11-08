CXX=g++
CXXFLAGS=-Wall -Wextra -g -Iinclude

SRC=$(wildcard src/*.cpp)
OBJ=$(patsubst %.cpp, %.o, $(SRC))
TARGET=build/libdatastruct.a

TEST_SRC=$(wildcard tests/*_test.cpp)
TESTS=$(patsubst %.cpp, %.out, $(TEST_SRC))

all: clean build tests
	@echo '------------'
	@sh tests/runtests.sh

build: $(OBJ)
	@mkdir -p build/
	ar rcs $(TARGET) $(OBJ)
	ranlib $(TARGET)

OBJ: $(SRC)

tests: LDLIBS+=$(TARGET)
tests: $(TEST_SRC) $(TESTS)
tests/%.out: tests/%.cpp
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

.PHONY: clean

clean:
	rm -f $(TESTS) $(OBJ) $(TARGET)

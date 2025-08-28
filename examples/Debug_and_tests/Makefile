CXX := g++
CXXFLAGS := -I../../src/public_headers
LDFLAGS := -L../../src -cppvoxelraster
SRC := main.cpp
BIN := Debug_and_tests

all: $(BIN)

$(BIN): $(SRC)
	 $(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

run: $(BIN)
	 ./$(BIN)

clean:
	 rm -f $(BIN)

.PHONY: all run clean
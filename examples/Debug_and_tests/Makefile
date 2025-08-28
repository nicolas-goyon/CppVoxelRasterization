CXX := g++
CXXFLAGS := -I../../src/public_headers
LIBDIR := ../../src
LIB := $(LIBDIR)/libcpp_voxel_raster.a
LDFLAGS := -L$(LIBDIR) -lcpp_voxel_raster
SRC := main.cpp
BIN := Debug_and_tests

all: $(BIN)

$(BIN): $(SRC) $(LIB)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@ $(LDFLAGS)

$(LIB):
	$(MAKE) -C $(LIBDIR)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: all run clean
CXX := g++
CXXFLAGS := -O2 -Ipublic_headers
SRCS := $(wildcard Core/*.cpp)
OBJS := $(SRCS:.cpp=.o)
LIB := libcpp_voxel_raster.a

all: $(LIB)

$(LIB): $(OBJS)
	 ar rcs $@ $^

Core/%.o: Core/%.cpp
	 $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	 rm -f $(OBJS) $(LIB)

.PHONY: all clean
CXX = g++
CXXFLAGS = -std=c++20 -fmodules-ts

TARGET = main
OBJS = main.o TwoDArray.o

all: $(TARGET)

TwoDArray.o: TwoDArray.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp TwoDArray.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
	rm -rf gcm.cache

.PHONY: all run clean


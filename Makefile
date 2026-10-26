CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = store

SOURCES = main.cpp address.cpp credit_card.cpp person.cpp product.cpp transaction.cpp store.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

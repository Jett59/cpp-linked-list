OBJS=list.o
OUTPUT=list

all: $(OUTPUT)

list: $(OBJS)
	$(CXX) $(OBJS) -o list

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

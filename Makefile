EXEC = battle.out
DIRS = tiiv .

CXX = g++
CXXFLAGS_OPT = -O
CXXFLAGS_DEBUG = -g

#Goes through directories to gather a list of .cpp files
SOURCE := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

#Ignores the folowing targets
.PHONY: debug opt clean test main.h

#Creates .o files from .cpp files
#$@ refers to the target, $< refers to the first file in the dependency list
%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Decides whether to build optimized or debug
ifeq "$(MAKECMDGOALS)" "opt"
CXXFLAGS = $(CXXFLAGS_OPT)
else
CXXFLAGS = $(CXXFLAGS_DEBUG)
endif

debug: $(EXEC)

opt: $(EXEC)
	
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) battle.out

//Instant running for quick testing
test: $(EXEC)
	@./$(EXEC) -p -s Fighter 6 -p -s Cruiser 3

EXEC = battle.out
DIRS = tiiv .

CXX = g++
CXXFLAGS_OPT = -O
CXXFLAGS_DEBUG = -g
SOURCE := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

.PHONY: debug opt clean test

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

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

test: $(EXEC)
	@./$(EXEC) -p -s Fighter 6 -p -s Cruiser 3
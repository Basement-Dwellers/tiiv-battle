CXX = g++
SOURCE = ./tiiv/shipType.cpp ./tiiv/buildData.cpp ./tiiv/ship.cpp ./tiiv/fleet.cpp ./tiiv/engine.cpp main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

%.o : %.cpp
	$(CXX) -c $< -o $@

battle.out: $(OBJ)
	$(CXX) -o $@ $^

clean:
	rm -f $(OBJ) battle.out
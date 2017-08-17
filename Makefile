OBJS1 = LiftCalc.cpp
OBJS2 = AscentRateCalc.cpp
CC = g++
DEBUG_FLAGS = -O0 -g3
RELEASE_FLAGS = -O3
FLAGS = -std=c++14 -Wall -Wextra -Werror

make: release

debug: $(OBJS)
	$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS1) -o lift_debug.out
	$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS2) -o ascent_debug.out

release: $(OBJS)
	$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS1) -o lift_calculator.out
	$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS2) -o ascent_calculator.out

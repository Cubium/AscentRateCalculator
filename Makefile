OBJS1 = LiftCalc.cpp
OBJS2 = AscentRateCalc.cpp
CC = g++
DEBUG_FLAGS = -O0 -g3
RELEASE_FLAGS = -O3 -g0
FLAGS = -std=c++11 -Wall -Wextra -Werror

make: release

release: $(OBJS) $(OBJS2)
	$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS1) -o lift_calculator.out
	$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS2) -o ascent_calculator.out

debug: $(OBJS1) $(OBJS2)
	$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS1) -o lift_debug.out
	$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS2) -o ascent_debug.out

clean:
	rm lift_calculator.out ascent_calculator.out lift_debug.out ascent_debug.out

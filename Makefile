OBJS = AscentRate.cpp
CC = g++
DEBUG_FLAGS = -O0 -g3
RELEASE_FLAGS = -O3
FLAGS = -std=c++17 -Wall -Wextra -Werror

debug: $(OBJS)
	$(CC) $(DEBUG_FLAGS) $(FLAGS) $(OBJS) -o debug.out

release: $(OBJS)
	$(CC) $(RELEASE_FLAGS) $(FLAGS) $(OBJS) -o release.out

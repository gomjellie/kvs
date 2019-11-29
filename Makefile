
SRCS = put.cpp get.cpp open.cpp close.cpp main.cpp
TARG = main
CC   = g++
OPTS = -Wall -O
LIBS = -lm

OBJS = $(SRCS:.cpp=.o)

all: $(TARG)


$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS)

%.o: %.cpp
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARG)



SRCS = put.cpp get.cpp open.cpp close.cpp main.cpp
TARG = main
CC   = g++
OPTS = -std=c++11 -Wall -O
OBJS = $(SRCS:.cpp=.o)

STATIC_LIBS = -L. -lkvs
STATIC_TARG = test_static

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS)

%.o: %.cpp
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARG) $(STATIC_TARG)

libkvs.a: $(OBJS)
	ar rc libkvs.a $(OBJS)

static: libkvs.a
	$(CC) -o $(STATIC_TARG) $(STATIC_LIBS)

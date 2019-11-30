
SRCS = put.cpp get.cpp open.cpp close.cpp
CC   = g++
OPTS = -std=c++11 -Wall -O
OBJS = $(SRCS:.cpp=.o)

STATIC_LIBS = -L./ -lkvs
STATIC_TARG = test_static
STATIC_OBJS = $(SRCS:.cpp=.o) $(STATIC_TARG:=.o)

DYNAMIC_OPTS = -shared
DYNAMIC_TARG = test_dll
DYNAMIC_OBJS = $(SRCS:.cpp=.o) $(DYNAMIC_TARG:=.o)

%.o: %.cpp
	$(CC) $(OPTS) -c $< -o $@

clean:
	ls -1 |grep -v "Makefile" |grep -v "\." |xargs rm

libkvs.a: $(STATIC_OBJS)
	ar rc libkvs.a $(STATIC_OBJS)

static: libkvs.a
	$(CC) -o $(STATIC_TARG) $(STATIC_LIBS)

libkvs.so.0.0.0: $(OBJS)
	$(CC) $(DYNAMIC_OPTS) -o libkvs.so $(OBJS)

dll: libkvs.so.0.0.0
	$(CC) -o $(DYNAMIC_TARG) $()


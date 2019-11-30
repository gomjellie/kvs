
SRCS = put.cpp get.cpp open.cpp close.cpp
CC   = g++
OPTS = -std=c++11 -Wall -O
OBJS = $(SRCS:.cpp=.o)

STATIC_LIBS = -L./ -lkvs
STATIC_TARG = test_static
STATIC_OBJS = $(OBJS) $(STATIC_TARG:=.o)

DYNAMIC_OPTS = -shared
DYNAMIC_TARG = test_dll
DYNAMIC_OBJS = $(OBJS) $(DYNAMIC_TARG:=.o)
DYNAMIC_LIBS =

%.o: %.cpp
	$(CC) $(OPTS) -c $< -o $@

clean:
	ls -1 |grep "\.o" |xargs rm
	ls -1 |grep "\.a" |xargs rm
	ls -1 |grep "\.so" |xargs rm
	ls -1 |grep -v "\." |grep -v "Makefile" |xargs rm

libkvs.a: $(OBJS)
	ar rc libkvs.a $(OBJS)

static: libkvs.a
	$(CC) -o $(STATIC_TARG) $(STATIC_TARG:=.cpp) $(STATIC_LIBS)

libkvs.so.0.0.0: $(OBJS)
	$(CC) $(DYNAMIC_OPTS) -o libkvs.so.0.0.0 $(OBJS)

dll: libkvs.so.0.0.0
	ln -s libkvs.so.0.0.0 libkvs.so
	$(CC) -o $(DYNAMIC_TARG) $(DYNAMIC_TARG:=.o) $(DYNAMIC_LIBS)


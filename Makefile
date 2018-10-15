DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS =-g3 -DDEBUG
else
    CFLAGS=-DNDEBUG
endif

OBJS = vel_dist.o file_io.o driver.o 
CXX = g++ -O3

all:	vel_dist

vel_dist:	$(OBJS)
	$(CXX) -o $@ $^

%.o:	%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr vel_dist $(OBJS) *.out

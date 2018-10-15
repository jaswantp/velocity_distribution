OBJS = vel_dist.o file_io.o driver.o 
CXX = g++ -O3

all:	vel_dist

vel_dist:	$(OBJS)
	$(CXX) -o $@ $^

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr vel_dist $(OBJS) $(PROJECT_ROOT)*.out

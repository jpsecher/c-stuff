OBJS := test.o netmask-test.o
BINS := test

all: test

CPPFLAGS += -I$(CPPUTEST_HOME)/include
LDFLAGS = -L$(CPPUTEST_HOME)/lib -lCppUTest
#LDFLAGS = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

test: test.o netmask-test.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) -o $@ $<

clean:
	-$(RM) $(OBJS) $(BINS)

.PHONY: all clean

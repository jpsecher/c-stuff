OBJS := test.o netmask.o netmask-test.o
BINS := test

all: test

ifeq ($(UNAME_S),Darwin)
	CPPFLAGS += -I$(shell brew --prefix cpputest)/include
	LDFLAGS += -L$(shell brew --prefix cpputest)/lib
endif
LDFLAGS += -lCppUTest
#LDFLAGS += -lCppUTestExt

test: test.o netmask.o netmask-test.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) -c $(CPPFLAGS) -o $@ $<

clean:
	-$(RM) $(OBJS) $(BINS)

.PHONY: all clean

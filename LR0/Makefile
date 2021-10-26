CXX=g++
EXE=LR0
CXXDEBUG= -g -Wall
CXXSTD=-std=c++17
CXXFLAGS= -Wno-deprecated-register -O0 $(CXXDEBUG) $(CXXSTD)

CPPOBJ= main LR0 Symbol Production Grammar

FILES= $(addsuffix .cpp, $(CPPOBJ))
OBJS = $(addsuffix .o, $(CPPOBJ))
SOBJS = lexer

CLEANLIST = $(addsuffix .o, $(OBJS))


.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(SOBJS)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) lexer.o

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)

lexer: lexer.ll
	flex $<
	$(CXX) $(CXXFLAGS) -c Lexer.cpp -o lexer.o
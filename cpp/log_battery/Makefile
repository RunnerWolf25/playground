VPATH   = ./src/
CC=clang
# nocona core2 nehalem corei7 westmere sandybridge corei7-avx ivybridge core-avx-i haswell core-avx2 broadwell skylake skylake-avx512 cannonlake icelake-client icelake-server cascadelake tigerlake cooperlake bonnell atom silvermont slm goldmont goldmont-plus tremont knl knm x86-64 eden-x2 nano nano-1000 nano-2000 nano-3000 nano-x2 eden-x4 nano-x4 k8 k8-sse3 opteron opteron-sse3 athlon64 athlon64-sse3 athlon-fx amdfam10 barcelona bdver1 bdver2 bdver3 bdver4 znver1 znver2 btver1 btver2 native
# -march not used for portability
OPTFLAGS = -march=skylake -Ofast -flto
LIBFLAGS = -lstdc++
CFLAGS   = -Wall -Wpedantic -Werror $(OPTFLAGS)
CXXFLAGS = $(CFLAGS) -x c++ 
#csrc    = $(wildcard *.c)
cppsrc   = $(wildcard ./src/*.cpp)
objs     = $(notdir $(cppsrc:.cpp=.o))

all: mk_dirs link

link: $(objs)
	$(CC) $(CFLAGS) -o ./bin/main $(wildcard ./obj/*) $(LIBFLAGS)

%.o :: %.c
	$(CC) $(CFLAGS)   -c -o ./obj/$@ $<

%.o :: %.cpp
	$(CC) $(CXXFLAGS) -c -o ./obj/$@ $<

mk_dirs:
	mkdir obj  2>/dev/null ; sleep 0
	mkdir bin  2>/dev/null ; sleep 0

clean:
	rm -rf bin 2>/dev/null ; sleep 0
	rm -rf obj 2>/dev/null ; sleep 0

# ================================
# Competitive Programming Makefile
# Usage:
#   make A        # builds A.cpp (release mode)
#   make A DB=1   # builds A.cpp with -DLOCAL debug flag
# ================================

CXX := g++
CXXFLAGS := -std=gnu++17 -O2 -Wall -Wextra
LDFLAGS := 

# Debug flag toggle
ifeq ($(DB),1)
	CXXFLAGS += -g -DLOCAL
else
	CXXFLAGS += -DNDEBUG
endif

# Rule: make <file-without-ext>
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f *.o *.out A B C D E F G H I J K L

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

UNAME_S := $(shell uname -s)
# Include bits/stdc++.h path on macos
# For no syntax errors in editor use clangd with bear make
ifeq ($(UNAME_S),Darwin)
	CXXFLAGS += -I/usr/local/bin/include
endif

# Rule: make <file-without-ext>
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

# all binaries with capital alpha names or A_somelabel ie E_1 E_2
BINS := $(shell ls | grep -E '^[A-Z]$$|^[A-Z]_\w+$$')

clean:
	rm -f *.o *.out $(BINS)
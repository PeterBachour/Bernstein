
# CFLAGS=$(HDR_PATHS) -Wno-deprecated

# CC=g++ 
# #CC=gcc

# ok : projetMathbernstein 

# .cc.o:
# 	$(CC) -c -O3 $(CFLAGS) $<

# OBJECTS_main = projetMathbernstein.o

# projetMathbernstein:  $(OBJECTS_main)
# 	$(CC) $(OBJECTS_main) -o projetMathbernstein $(LIB_PATHS) $(LIBS)

	
# indenter :
# 	for i in *.h *.cpp do sed -i~ -f sed.sed  $i done
# 	indent  *.h *.cpp

# clean :
# 	rm -fr *.o
# #	touch *.cpp *.h

# delete :
# 	rm -f *.h~
# 	rm -f *.cc~
# 	rm -f *.txt

# Generic Makefile with automatic dependencies management

# Choose your compiler g++/clang++
CXX        = g++
CXXFLAGS   = -Wall -Wextra -std=c++11
DEPFLAGS   = -MMD
LDFLAGS    = 
# Replace your_files.cpp with the list of cpp files that need to be compiled
# Ex: file1.cpp file2.cpp file3.cpp
SRCS       = Polynome.cpp Bernstein.cpp main.cpp
OBJS       = $(SRCS:.cpp=.o)
# Replace your_app with the name you want to give to your executable file
TARGET     = main 
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

clean:
	rm -f *.o *.d

mrproper: clean
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)
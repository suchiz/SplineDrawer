CC = g++
CFLAGS = -std=c++11

SRC = src/

all: bspline tensorproductspline
	
bspline: $(SRC)mainspline.cpp $(SRC)bspline.cpp $(SRC)functionmain.cpp
	$(CC) $(SRC)mainspline.cpp $(SRC)bspline.cpp $(SRC)functionmain.cpp -o bspline $(CFLAGS)
	
tensorproductspline: $(SRC)maintensor.cpp $(SRC)bspline.cpp $(SRC)tensorproduct.cpp $(SRC)functionmain.cpp
	$(CC) $(SRC)maintensor.cpp $(SRC)bspline.cpp $(SRC)functionmain.cpp $(SRC)tensorproduct.cpp -o tensorproduct $(CFLAGS)

clean:
	rm -rf bspline tensorproduct
	


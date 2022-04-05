CC=g++

CFLAGS=-Ofast -march=native -mtune=native -std=c++14

LDFLAGS=

EXEC=main

SRC=./src/Format/CBitmap.cpp \
	./src/Image/CImage.cpp   \
    ./src/Image/CLigne.cpp   \
    ./src/Image/Couleur.cpp  \
    ./src/Image/CPixel.cpp   \
	./src/Formes/Forme.cpp   \
    ./src/Formes/Point.cpp   \
	./src/Formes/Ligne.cpp   \
    ./src/Formes/Rectangle.cpp   \
	./src/Formes/Carre.cpp   \
    ./src/Formes/RectangleS.cpp   \
	./src/Formes/CarreS.cpp  \
	./src/Formes/Cercle.cpp  \
	./src/Formes/CercleS.cpp  \
	./src/main.cpp



OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

main: $(OBJ)
	$(CC) $(CFLAGS) -o ./bin/$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean mrproper

clean:
	find ./bin -name main -exec rm {} \;
	find ./src -name *.o  -exec rm {} \;

mrproper: clean
	rm $(EXEC)

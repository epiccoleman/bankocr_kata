all: bankocr

bankocr: main.o OCRHandler.o
	g++ main.o OCRHandler.o -o bankocr

main.o: main.cc
	g++ -c main.cc

OCRHandler.o: 
	g++ -c OCRHandler.cc

clean:
	rm -rf *o bankocr
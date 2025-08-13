.PHONY: clean all build run
.SILENT: clean build run

all:
	mkdir -p build && cd build && \
	cmake .. && \
	cmake --build .

build: 
	cd src && \
	g++ cube.cpp moves.cpp -o a.exe

run: build
	cd src && ./a.exe

clean:
	rm -rf build
	rm -f src/a.exe

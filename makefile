.PHONY: clean all run
.SILENT: clean all run

all:
	mkdir -p build && cd build && \
	cmake .. && \
	cmake --build .

	cp build/Debug/_cubix_python.pyd build/_cubix_python.pyd

run:
	cd build/Debug && ./cubix.exe

clean:
	rm -rf build
	rm -f src/a.exe

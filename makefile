##############################################################################
# Makefile
##############################################################################

BUILD_DIR := build
RELEASE_DIR := release

THREADS := 1

.PHONY: clean clean-all all run
.SILENT: clean clean-all all run

all:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && \
	cmake .. && \
	cmake --build . --parallel $(THREADS)

	cp $(BUILD_DIR)/Debug/_cubix_python.pyd $(BUILD_DIR)/_cubix_python.pyd

	cp dummy.toml $(BUILD_DIR)/Debug/dummy.toml
	cp -r tests/solutions $(BUILD_DIR)/tests/Debug

release:
	mkdir -p $(RELEASE_DIR) && cd $(RELEASE_DIR) && \
	cmake -DCMAKE_BUILD_TYPE=Release .. && \
	cmake --build . --parallel $(THREADS)

run:
	cd $(BUILD_DIR)/Debug && ./cubix.exe

test:
	cd build/tests/Debug && ./cubix_tests.exe

clean:
	rm -f src/a.exe
	mv $(BUILD_DIR)/_deps _deps
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	mv _deps $(BUILD_DIR)/_deps

	rm -rf $(RELEASE_DIR)

clean-all:
	rm -rf $(BUILD_DIR)
	rm -rf $(RELEASE_DIR)

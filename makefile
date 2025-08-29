##############################################################################
# Makefile
##############################################################################

BUILD_DIR := build

.PHONY: clean clean-all all run
.SILENT: clean clean-all all run

all:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && \
	cmake .. && \
	cmake --$(BUILD_DIR) .

	cp $(BUILD_DIR)/Debug/_cubix_python.pyd $(BUILD_DIR)/_cubix_python.pyd

run:
	cd $(BUILD_DIR)/Debug && ./cubix.exe

test:
	cd build && ctest

clean:
	rm -f src/a.exe
	mv $(BUILD_DIR)/_deps _deps
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
	mv _deps $(BUILD_DIR)/_deps

clean-all:
	rm -rf $(BUILD_DIR)

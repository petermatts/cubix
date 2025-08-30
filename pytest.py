from build import cubix
import pytest
# ? use unittest library instead

cube = cubix.Cube()

cubeU = cube.U()

cubeR = cube.R()

# these should be different
print(cube)
print(cubeU)
print(cubeR)

assert (cubeU == cube.U())

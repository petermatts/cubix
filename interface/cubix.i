%module cubix

%include <std_string.i>
%include <std_vector.i>

%{
#include "../src/common.hpp"
#include "../src/cube.hpp"
%}

%include "../src/cube.hpp"
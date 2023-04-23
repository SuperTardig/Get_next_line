# get_next_line
The goal of this 42 school project is to create a funtion that will read and return a line from a the given file descriptor. A buffer size, which is the size of the read that will be effectuate, is given at compile time. A static variable had to be used to hold the characther that were read beyond the end of the `'\n'`.
# Bonus
The bonus part of this project had the following requirement:
  - Only one static variable can be used. This didn't require any change to the code due to it already using only one static.
  - Multiple file descriptor can be used at the same without having mixed output or losing part of the old line. This was handled by changing my static variable from a char* to char*[OPEN_MAX], which represent the maximum amout of file descriptor that can be open at the same on the machine
  # Usage
  To use this function, you need to:
    
    1. Clone this repository into your project
    2. include `"get_next_line.h"` or `"get_next_line_bonus.h"` in your project
    3. Either define `BUFFER_SIZE <value>` in your header or include `-D BUFFER_SIZE=<value>` in your compilation line
    4. Compile your file and add `"get_next_line.c"` or `"get_next_line_bonus.c"` and `"get_next_line_utils.c"` or `"get_next_line_utils_bonus.c"`

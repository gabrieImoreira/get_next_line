![](https://www.nicolamanzini.com/wp-content/uploads/2018/01/get_next_line-cover.png)

This projects is about creating a function that, allows to read a line ending with a newline character ('\n') from a file descriptor, without knowing its size beforehand. One of the goal of this project is to learn a highly interesting new concept in C programming: static variables, and to gain a deeper understanding of allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.

## Compile:
> gcc -D BUFFER_SIZE=**XX** **your_program.c** get_next_line.c get_next_line_utils.c get_next_line.h

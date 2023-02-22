#ifndef SLIDE_H
#define SLIDE_H

#include <stdio.h>
#include <stddef.h>

# define SLIDE_LEFT 0
# define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void slide_number_left(int *line, size_t size);
void slide_number_right(int *line, size_t size);
void merge_number(int *line, size_t size, int direction);

#endif /* SLIDE_H */

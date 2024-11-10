#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

/* Macros for slide directions */
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/* Function prototype */
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */

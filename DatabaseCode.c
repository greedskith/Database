#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// checking source control
//comment 1
//comment 2
//  A simple wrapper for getline() input
typedef struct {
  char *line;           // dynamically allocated string
  size_t line_capacity; // allocated size (needed by getline)
  ssize_t line_length;  // length of input (excluding null terminator)
} InputBuffer;
// hey hey
//  Allocate a new InputBuffer on the heap
InputBuffer *new_input_buffer() {
  InputBuffer *ib = malloc(sizeof(InputBuffer));
  ib->line = NULL;
  ib->line_capacity = 0;
  ib->line_length = 0;
  return ib;
}

int main() {
  InputBuffer *input = new_input_buffer();
  printf("Size of InputBuffer: %zu bytes\n", sizeof(InputBuffer));

  for (;;) {
    printf("db > ");

    ssize_t bytes_read = getline(&input->line, &input->line_capacity, stdin);

    if (bytes_read <= 0) {
      printf("Error reading input!\n");
      exit(1);
    }

    // Remove trailing newline
    input->line_length = bytes_read - 1;
    input->line[bytes_read - 1] = '\0';

    if (input->line[0] == '.') {
      // handle exit
      if (strcmp(input->line, ".exit") == 0) {
        return 0;
      }
      printf("sahi command likh '%s' kuch ni hota\n", input->line);
      continue;
    }
    if (strncmp(input->line, "insert", 6) ==
        0) { // string-compare-up-to-n-characters
      printf("Do and insertion right now ");
      continue;
    }
    if (strcmp(input->line, "select") == 0) {
      printf("Do and selection right now ");
      continue;
    }
    printf("Unrecognized keyword at start of '%s'\n", input->line);
  }
  return 0;
}

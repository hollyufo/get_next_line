# Get Next Line (GNL)

## Project Description

Get Next Line is a C programming project that implements a function to read lines from a file descriptor. This project introduces the concept of static variables and provides a robust solution for reading text files line by line.

## Project Goals

- Learn about static variables in C
- Implement a function that reads lines from different file descriptors
- Practice memory management and file handling in C

## Requirements

- C programming language (C99 standard)
- File descriptors handling
- Dynamic memory allocation (`malloc`, `free`)
- String manipulation functions
- Compilation using a C compiler (e.g., `gcc`)

---

## File Structure

- **get_next_line.c**: The main function implementation.
- **get_next_line.h**: Header file that contains the function prototype and necessary includes.
- **libft**: A utility library that contains helper functions like `ft_strlen`, `ft_strdup`, `ft_strjoin`, etc.
- **tests**: A folder containing test files to check different use cases of the `get_next_line` function.

---

## Function Prototype

```c
char    *get_next_line(int fd);
```

- **Parameters**:
  - `fd`: The file descriptor to read from.
- **Return Value**:
  - The next line read from the file descriptor `fd`.
  - `NULL` if an error occurs or the end of the file is reached.

## How it Works

- 1. **Memory Allocation**: The function allocates a buffer to store the read characters.
- 2. **Buffer Management**: A static buffer is used to read chunks of data. When a newline character is encountered, the line is returned.
- 3. **End of File**: When the end of the file is reached, NULL is returned, signaling that no more lines are available.
- 4. **Multiple File Descriptors**: The function handles multiple file descriptors by storing static variables to keep track of the reading progress for each file.

## Compilation

To compile the `get_next_line` function, you can use the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c libft/*.c tests/test_gnl.c -o test_gnl
```

## Usage

- A simple example of using the `get_next_line` function:

```c
#include "get_next_line.h"

int main() {
    int fd = open("sample.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);  // Don't forget to free the memory!
    }
    close(fd);
    return 0;
}
```
- This will read sample.txt line by line and print each line to the console.

## Testing

- The tests folder contains various test files for different scenarios:

    - Files with multiple lines
    - Empty files
    - Files with no newline characters
    - Large files
- You can test your implementation by running the following:  
    
    ```bash
    gcc -Wall -Wextra -Werror -o test_get_next_line get_next_line.c libft/*.c tests/test_program.c ./test_get_next_line
    ```
- This will compile the main program and run it with the test files.

## Limitations

- The function assumes that each line will be terminated by a newline character (\n).
- The function does not handle multi-character delimiters or file types other than text files.
- Memory leaks could occur if the user forgets to free() the returned line after use.





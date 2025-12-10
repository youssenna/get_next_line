# This project has been created as part of the 42 curriculum by <[yousenna](https://github.com/youssenna)>

## Description

This project implements a `get_next_line()` function that reads and returns **one line at a time** from a file descriptor. This is particularly useful for reading files line-by-line without loading the entire file into memory.

### Learning Goals

- Understand and implement **static variables** in C
- Master **file descriptor** manipulation
- Practice **memory management** and **buffer handling**
- Learn efficient text parsing techniques

## Features

- ✅ Reads one line per function call
- ✅ Works with files, stdin, and network sockets
- ✅ Configurable buffer size
- ✅ Bonus: Handles multiple file descriptors simultaneously
- ✅ Memory-efficient implementation

## Installation

Clone the repository into your project directory:

```bash
git clone https://github.com/youssenna/get_next_line.git
```

## Usage

### Basic Usage (Single File Descriptor)

1. Include the header in your code:
```c
#include "get_next_line.h"
```

2. Create a simple test program:
```c
#include 
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

3. Compile:
```bash
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
```

### Bonus (Multiple File Descriptors)

For reading from multiple files simultaneously:

```bash
cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Custom Buffer Size

You can customize the buffer size at compile time:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

**Note**: Larger buffer sizes generally improve performance but use more memory.

## Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: File descriptor to read from

**Return Value:**
- The line that was read (including the `\n` if present)
- `NULL` if there's nothing left to read or an error occurred

**Important:** The caller is responsible for freeing the returned string.

## How It Works

The function uses a **static variable** to preserve data between function calls:

1. **Buffer Allocation**: Allocates `BUFFER_SIZE + 1` bytes to store data read from the file
2. **Static Storage**: Maintains leftover data from previous reads in a static variable
3. **Newline Detection**: Searches for `\n` in the accumulated data
4. **Line Extraction**: When a newline is found, extracts and returns the line
5. **Data Preservation**: Stores remaining data in the static variable for the next call
6. **EOF Handling**: Returns remaining data when end-of-file is reached

### Algorithm Flow

```
┌─────────────────────────────────────┐
│ Check static variable for newline   │
│ If found, extract and return line   │
└──────────────┬──────────────────────┘
               │ No newline found
               ↓
┌─────────────────────────────────────┐
│ Read BUFFER_SIZE bytes from fd      │
└──────────────┬──────────────────────┘
               │
               ↓
┌─────────────────────────────────────┐
│ Join with static variable content   │
└──────────────┬──────────────────────┘
               │
               ↓
┌─────────────────────────────────────┐
│ Check for newline in joined string  │
│ - Found: Extract line, save rest    │
│ - Not found: Save all, continue     │
│ - EOF: Return remaining data        │
└─────────────────────────────────────┘
```

## Project Structure

```
get_next_line/
├── get_next_line.h           # Header file
├── get_next_line.c           # Main function
├── get_next_line_utils.c     # Helper functions
├── get_next_line_bonus.h     # Bonus header (multiple FDs)
├── get_next_line_bonus.c     # Bonus implementation
└── get_next_line_utils_bonus.c
```

## Testing

Test with different buffer sizes and edge cases:

```bash
# Small buffer
cc -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c

# Large buffer
cc -D BUFFER_SIZE=9999 main.c get_next_line.c get_next_line_utils.c

# Test with stdin
./a.out < test.txt

# Test with multiple files (bonus)
./a.out file1.txt file2.txt file3.txt
```

## Resources

- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File Descriptors in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Understanding read() System Call](https://man7.org/linux/man-pages/man2/read.2.html)

## Common Pitfalls

⚠️ **Memory Leaks**: Always free the returned line after use
⚠️ **Invalid FD**: Check if file descriptor is valid before calling
⚠️ **Buffer Size**: Setting `BUFFER_SIZE` to 0 or negative values will cause errors
⚠️ **Multiple Calls**: Don't mix calls to the same FD from different contexts

## AI Usage.

This project was developed as part of the 42 School curriculum with assistance from AI tools. Here's how AI was used:

### Code Development

- ✅ **Bug Fixing**: AI (Claude) helped identify and fix logic errors, particularly:
  - Memory management issues in `ft_get_line()`
- ✅ **Code Review**: AI assisted in reviewing code for memory leaks and potential issues

### Documentation
- ✅ **README File**: AI helped improve grammar, structure, and clarity of documentation
- ✅ **Code Comments**: Original comments were written by me; AI helped refine technical explanations
- ✅ **Algorithm Flowchart**: Visual representation created with AI assistance

### What AI Did NOT Do
- ❌ Write the core `get_next_line()` implementation from scratch
- ❌ Complete the project requirements
- ❌ Design the overall architecture and data structures

### Learning Outcome
Using AI as a debugging and documentation tool enhanced my understanding of:
- Static variables and their behavior
- Memory management best practices
- Edge case handling in file I/O operations
- Professional documentation standards

I believe AI tools, when used responsibly, can accelerate learning by providing immediate feedback and explanations, similar to pair programming or code review sessions.

## Author

**Youssef Ennajar** - [LinkedIn](https://www.linkedin.com/in/youssef-ennajar-213985253/) | [GitHub](https://github.com/youssenna)

---
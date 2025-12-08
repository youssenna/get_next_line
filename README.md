# This project has been created as part of the 42 curriculum by [yousenna](https://github.com/youssenna)

## Description:

### This project it's allow  me to creat a get_next_line() function, that you can use it in your code to read **one line** in a file discriptor **at a time**.

>### Goal:


>This activity will not only allow me to add a highly useful function to my collection,
but it will also teach me an important concept in C programming: static variables.

## How to use it

### 1. open your terminal and on the root of your project run this command

```bash
git clone https://github.com/youssenna/get_next_line.git
```

### 2. Make sure you have an int main function in your project and you call my `get_next_line(fd)` function and change fd to a file discriptor that you want to read from it.


### 3. Compile your code: 
```bash
cc your_file.c get_next_line.c get_next_line_utils.c 
```
#### or
```bash
cc your_file.c get_next_line_bonus.c get_next_line_utils_bonus.c 
```
#### if you want to read from multiple files, and change `your_file.c` to all files that is have on your code.
### 4. BOOM now your code will work using my get_next_line function to read from  one or multiple file discriptors
### 5. you can change the buffer size that I used ion my code using `-D` flag and assign the value that you want to BUFFER_SIZE.

```bash
cc your_file.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=1337
```
## Resources:

- [static variable](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [file discriptor](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
## Detailed explanation and justification of the algorithm selected for this project

> ## 1. I alloc the `BUFFER_SIZE` bytes + 1 in the beguin to store the store in it the what i read in the file descriptor and null terminat it.

> ## 2. set `read_nb` variable to 1 and whie loop that's will work until `read_nb` variable less than 0.

>> ## 3. inside this loop if i found `read_nb` variable less than or equal 0 i will break the while cause I will use `read_nb` variable to store the return value of `read` function.
>> ## 4. I check the static variable `str` if I found in it `\n` I will print the string str while i foun `\n` and i will set `\0` to the caracter after `\n` using `ft_while_n_line()` function.
>> ## 5.  If I don't found `\n` I will read new `BUFFER_SIZE` caracters and put it in the `buffer` variable. Then I will to store the output of `ft_get_line` function in the `var.tmp` pointer.
```c
char	*ft_get_line(char *buffer, char **static_var, int read_nb);
```
>>> ## 6. `ft_get_line` function take a static variable `str` and `var.buffer` then join them, then put the output in `tmp`, after that I check if I foun `\n` I return the string until `\n`,
>>> ## 7. If I found `read_nb < BUFFER_SIZE` I put the static variable in `tmp` variable and return it if the that static variable not `NULL` or empty.

>> ## 8. then if `var,tmp` not null I return it else the loop will retray the operation on the step `2.`.

>> ## 9. if an error I return NULL. 


#### [EDITOR: yousenna](https://www.linkedin.com/in/youssef-ennajar-213985253/)
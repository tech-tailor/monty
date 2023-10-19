<div align="center">
  <img width="700" height="245" src="assets/montylogo_wide.png">
</div>

# Monty
This is an interpreter for Monty bytecodes files. Through the esoteric [Monty](http://montyscoconut.github.io/) is addressed Linked lists, Stacks, Queues - LIFO, FIFO concepts. Developed on Ubuntu Linux using C language. __Bonus track - Brainf\*ck__ 

![OS Linux](https://img.shields.io/badge/OS-Linux-blue.svg)
![distro Ubuntu](https://img.shields.io/badge/distro-Ubuntu-orange.svg)
![tecnology C](https://img.shields.io/badge/technology-C-green.svg)

The concepts covered here are:
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## Requirements
- Linux Ubuntu 14.04 LTS
- gcc (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4
- C language understanding

## Installation
1. Clone the repo in your local machine:  
**Example:**
```bash
vagrant@~$
vagrant@~$ git clone https://github.com/gogomillan/monty.git
vagrant@~$
```
2. Go to the directory and compile the task you want:  
**Example:**
```bash
vagrant@~$
vagrant@~$ cd monty
vagrant@~$ ls
_add.c  bytecodes        freestack.c  _mod.c   _nop.c    _pint.c  _push.c     README.md  set_number.c  _swap.c
assets  check_command.c  LICENSE      monty.h  _pall.c   _pop.c   _queue.c    _rotl.c    _stack.c
bf      _div.c           main.c       _mul.c   _pchar.c  _pstr.c  readfile.c  _rotr.c    _sub.c
vagrant@~$
```
3. Complile the project: 
**Example**
```bash 
vagrant@~$
vagrant@~$ gcc -Wall -Werror -Wextra -pedantic \*.c -o monty
vagrant@~$
```
## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python).
It relies on a unique stack, with specific instructions to manipulate it. The goal of this project
is to create an interpreter for Monty ByteCodes files.

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this
standard but it is not required by the specification of the language. There is not more than one
instruction per line. There can be any number of spaces before or after the opcode and its argument.
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional
text after the opcode or its required argument is not taken into account:
```bash
vagrant@~$ cat -e bytecodes/000.m
push 0$
push 1$
$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
vagrant@~$
```
### Usage
Usage: monty file  
- where file is the path to the file containing Monty byte code

- If the user does not give any file or more than one argument to your program, print
  the error message USAGE: monty file, followed by a new line, and exit with the
  status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message
  Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
  - where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown
  instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
  - where is the line number where the instruction appears.
    Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured

## Cases

### Case: push, pall 
The opcode push pushes an element to the stack.  
- Usage: push <int>  
  where <int> is an integer  
The opcode pall prints all the values on the stack, starting from the top of the stack.  
- Usage pall  

```bash
vagrant@~$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vagrant@~$ ./monty bytecodes/00.m
3
2
1
vagrant@~$
```

### Case: pint  
The opcode pint prints the value at the top of the stack, followed by a new line.  
- Usage: pint  
  If the stack is empty, print the error message L<line_number>: can't pint, stack empty,
  followed by a new line, and exit with the status EXIT_FAILURE

```bash
vagrant@~$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vagrant@~$ ./monty bytecodes/00.m
3
2
1
vagrant@~$
```

### Case: pop
The opcode pop removes the top element of the stack.  
- Usage: pop  
  If the stack is empty, print the error message L<line_number>: can't pop an empty stack,
  followed by a new line, and exit with the status EXIT_FAILURE

```bash
vagrant@~$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
vagrant@~$ ./monty bytecodes/07.m 
3
2
1
2
1
1
vagrant@~$ 
```

### Case: swap  
The opcode swap swaps the top two elements of the stack.  
- Usage: swap  
  If the stack contains less than two elements, print the error message ```L<line_number>: can't swap, stack too short```,
  followed by a new line, and exit with the status EXIT_FAILURE

```bash
vagrant@~$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
vagrant@~$ ./monty bytecodes/09.m 
3
2
1
2
3
1
vagrant@~$ 
```

### Case: add
The opcode add adds the top two elements of the stack.  
- Usage: add  
  - If the stack contains less than two elements, print the error message ```L<line_number>: can't add, stack too short```,
    followed by a new line, and exit with the status EXIT_FAILURE
  - The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    - The top element of the stack contains the result
    - The stack is one element shorter

```bash
vagrant@~$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

vagrant@~$ ./monty bytecodes/12.m 
3
2
1
5
1
vagrant@~$
```

### Case: nop
The opcode nop doesn’t do anything.  
- Usage: nop

### Case: sub
The opcode sub subtracts the top element of the stack from the second top element of the stack.  
- Usage: sub  
  If the stack contains less than two elements, print the error message ```L<line_number>: can't sub, stack too short```,
  followed by a new line, and exit with the status EXIT_FAILURE
  The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

```bash
vagrant@~$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
vagrant@~$ ./monty bytecodes/19.m 
7
2
1
vagrant@~$
```

### Case: div
The opcode div divides the second top element of the stack by the top element of the stack.
- Usage: div  
  - If the stack contains less than two elements, print the error message ```L<line_number>: can't div, stack too short```,
    followed by a new line, and exit with the status EXIT_FAILURE
  - The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    - The top element of the stack contains the result
    - The stack is one element shorter
  - If the top element of the stack is 0, print the error message ```L<line_number>: division by zero, followed by a new line```,
    and exit with the status EXIT_FAILURE

```bash
vagrant@~$ cat bytecodes/20.m 
push 3
push 10
push 2
pall
div
pall
vagrant@~$ ./monty bytecodes/20.m 
2
10
3
5
3
vagrant@~$
```

### Case: mul
The opcode mul multiplies the second top element of the stack with the top element of the stack.
- Usage: mul  
  - If the stack contains less than two elements, print the error message ```L<line_number>: can't mul, stack too short```,
    followed by a new line, and exit with the status EXIT_FAILURE
  - The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    - The top element of the stack contains the result
    - The stack is one element shorter  
**Try it out ;-)**
  
### Case: mod
The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.
- Usage: mod  
  - If the stack contains less than two elements, print the error message ```L<line_number>: can't mod, stack too short, followed by a new line```,
    and exit with the status EXIT_FAILURE
  - The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    - The top element of the stack contains the result
    - The stack is one element shorter
  - If the top element of the stack is 0, print the error message ```L<line_number>: division by zero, followed by a new line```,
    and exit with the status EXIT_FAILURE  

**Try it out ;-)**
  
### Case: comments
Every good language comes with the capability of commenting. When the first non-space character of
a line is ```#```, treat this line as a comment (don’t do anything).  
**Try it out ;-)**
  
### Case: pchar
The opcode pchar prints the char at the top of the stack, followed by a new line.
- Usage: pchar
  - The integer stored at the top of the stack is treated as the ascii value of the character to be printed
  - If the value is not in the ascii table (man ascii) print the error message ```L<line_number>: can't pchar, value out of range```,
    followed by a new line, and exit with the status EXIT_FAILURE
  - If the stack is empty, print the error message ```L<line_number>: can't pchar, stack empty```,
    followed by a new line, and exit with the status EXIT_FAILURE

```bash
vagrant@~$ cat bytecodes/28.m 
push 72
pchar
vagrant@~$ ./monty bytecodes/28.m 
H
vagrant@~$
```

### Case: pstr
The opcode pstr prints the string starting at the top of the stack, followed by a new line.
- Usage: pstr  
  - The integer stored in each element of the stack is treated as the ascii value of the character to be printed
  - The string stops when either:
    - the stack is over
    - the value of the element is 0
    - the value of the element is not in the ascii table
  - If the stack is empty, print only a new line

```bash
vagrant@~$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 110
push 111
push 116
push 114
push 101
push 98
push 108
push 111
push 72
pstr
vagrant@~$ ./monty bytecodes/31.m 
Holberton
vagrant@~$ 
```

### Case: rotl
The opcode rotl rotates the stack to the top.
- Usage: rotl  
  - The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
  - rotl never fails

```bash
vagrant@~$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
vagrant@~$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
vagrant@~$ 
```

### Case: rotr
The opcode rotr rotates the stack to the bottom.
- Usage: rotr
  - The last element of the stack becomes the top element of the stack
  - rotr never fails  

**Try it out ;-)**

### Case: stack, queue
The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- Usage: stack  

The opcode queue sets the format of the data to a queue (FIFO).
- Usage: queue  

When switching mode:
- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack

```bash
vagrant@~$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
vagrant@~$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
vagrant@~$ 
```

**NOTE:** There is bonuses for Brainf**k language that is based un Turin machine
find it or contact us ;-)
  
## Authors

* **Juan Marcos Cabezas** - *Initial work* - [PurpleBoothJMC](https://github.com/juanmarcoscabezas)
* **Gonzalo Gomez Millan** - *Initial work* - [PurpleBoothGGM](https://github.com/gogomillan)

## License

This project is licensed under the GNU License - see the [LICENSE](LICENSE) file for details

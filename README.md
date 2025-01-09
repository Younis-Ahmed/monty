# Monty

## Description
The Monty project is a simple interpreter for Monty ByteCodes files. Monty ByteCodes files have a specific syntax and are used to perform operations on a stack data structure. This interpreter is implemented in C.

## Features
- Supports basic stack operations such as push, pop, and pall.
- Implements additional operations like pint, swap, add, nop, and more.
- Handles errors gracefully and provides informative error messages.

## Installation
To compile the Monty interpreter, you need to have GCC installed. Use the following command to compile the project:

```sh
gcc -o monty *.c
```
## Usage
To run the Monty interpreter, provide the path to a Monty ByteCode file as an argument:

```sh
./monty <file.m>
```
## Example
Create a file named example.m with the following content:

```Code
push 1
push 2
push 3
pall
```

Run the interpreter with this file:

```sh
./monty example.m
```

The output will be:

```Code
3
2
1
```

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Authors
Younis Ahmed

# HW08 Program Instructions

Python is an interpreted language which means when you run it, the interpreter must read each line of code, decipher what it means and then execute the operations. 

In contrast, C is a compiled language.  This means that the program is read by the compiler and converted into an executable file filled with machine code.  "Machine code" is the actual binary representation of the operations to be performed and the computer loads them directly into memory and executes them directly.  This results in much faster execution since the computer no longer has to interpret the program as it runs.  The compilation is only done once and it also allows you to distribute your program without revealing your actual program to to the users.

Also C is a strongly typed language.  You must specify exactly what type each variable is (float, int, char, etc.)

Compilation Instructions:

to compile a single program on the command line type
gcc <c code filename> -o <compiled filename>
gcc -g -Wall -Wextra hw08a.c -ohw08a
If you do not provide a compiled filename, then it will default to "a.out"
then you can execute the program by typing "./<compiled filename>
you do not need to chmod it, it will be executable by default.
to compile it for testing, create the build directory and run make test there.  This will compile and test your code.
vi has built in support for compiling.
:make -C ../build
this will run the make command from in the build directory and allow you to navigate directly to the errors in vi
after running it, vi will move the cursor to the first error.
the :cnext or :cprevious will move to the next or previous errors.
debugging with gdb
Assignment:

hw08a.c
create a program hw08a.c which prints "Hello world from C\n" to the screen.
hw08b.c
write a program hw08b.c which uses a for loop, a while loop and do while loop to print the numbers from 1 to 5 on the screen
hw08c.c
Print the numbers from one to 20 along with whether each number is even or odd and prime or composite. 
Use a function bool isEven(int x) which returns true if a number is even and false otherwise.
Use a function bool isPrime(int x) which returns true if a number is prime and false otherwise.
Determine if a number is prime using a loop.
Write a main function that loops through the numbers 1 to 20 and for each number print:
<number>\t<"even" or "odd">\t<"prime" or "composite">\n

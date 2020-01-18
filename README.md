# PSU_strace_2018
Second year mini project in C in which the goal is to trace a binary in real time and displays all of the system calls it executes in their order of appearance.

USAGE :

    Make.

    ./strace [-s] [-p <pid>|<command>].

    • -p: force a specific PID instead of executing a command.

    • -s: display integers in decimal form, pointers on a character string in the form of a character string, detailed structures (value for each field).

    By default strace only display arguments and return values in hexadecimal form.

EXEMPLE :

    > ./strace strace

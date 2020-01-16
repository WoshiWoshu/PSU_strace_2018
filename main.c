/*
** EPITECH PROJECT, 2019
** PSU_strace_2018
** File description:
** main.c
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "s_trace.h"

static void display_no_arg(int ac)
{
    if (ac <= 1) {
        write(1, "strace: must have PROG [ARGS] or -p PID\n", 40);
        write(1, "Try 'strace -h' for more information.\n", 38);
        exit(84);
    }
}

static void p_strace(char **av)
{
    if (av[2] != NULL)
        exit(0);
    write(1, "strace: option requires an argument -- 'p'\n", 43);
    write(1, "Try 'strace -h' for more information.\n", 38);
    exit(84);
}

int main(int ac, char **av)
{
    display_no_arg(ac);
    if (!strcmp(av[1], "--help")) {
        write(0, "USAGE: ./strace [-s] [-p <pid>|<command>]\n", 42);
        return (0);
    }
    if (av[1][0] == '-') {
        switch (av[1][1]) {
            case 'p':
                p_strace(av);
                break;
            case 's':
                return (0);
            default:
                printf("strace: invalid option -- '%c'\n", av[1][1]);
                printf("Try 'strace -h' for more information.\n");
                return (84);
        }
    }
    if (run_strace(av) == false)
        return (84);
}

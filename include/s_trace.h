/*
** EPITECH PROJECT, 2019
** strace
** File description:
** s_trace.h
*/

#ifndef _S_TRACE_H_
#define _S_TRACE_H_

#include <sys/wait.h>
#include <sys/user.h>
#include <stdbool.h>

enum regs {
    RDI = 0,
    RSI,
    RDX,
    R10,
    R8,
    R9,
    REGS_SIZE
};

typedef struct child_data_s {
    pid_t child;
    struct user_regs_struct regs;
} child_data_t;

typedef struct trace_process_s trace_process_t;

struct trace_process_s {
    int status;
    bool in_out_syscall;
    long long int tab_regs[REGS_SIZE];
};

extern void print_syscalls_few_params(trace_process_t print_regs,
       struct user_regs_struct return_reg);
extern void print_syscalls_regular_params(trace_process_t print_regs,
       struct user_regs_struct return_reg);
extern void print_syscalls_great_params(trace_process_t print_regs,
       struct user_regs_struct return_reg);
extern bool run_strace(char **av);

#endif /* S_TRACE_H_ */

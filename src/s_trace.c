/*
** EPITECH PROJECT, 2019
** s_trace
** File description:
** s_trace.c
*/

#include <sys/ptrace.h>
#include <unistd.h>
#include <stdlib.h>
#include "s_trace.h"
#include "syscalls.h"

static pid_t create_child(void)
{
    pid_t new_child = fork();

    return (new_child);
}

static bool wait_child(int status)
{
    wait(&status);
    if (WIFEXITED(status))
        return (true);
    return (false);
}

static bool get_child_data(bool syscall_state,
       struct user_regs_struct get_regs, trace_process_t *put_regs)
{
    if (syscall_state == false) {
        put_regs->tab_regs[RDI] = get_regs.rdi;
        put_regs->tab_regs[RSI] = get_regs.rsi;
        put_regs->tab_regs[RDX] = get_regs.rdx;
        put_regs->tab_regs[R10] = get_regs.r10;
        put_regs->tab_regs[R8] = get_regs.r8;
        put_regs->tab_regs[R9] = get_regs.r9;
        return (true);
    } else {
        print_syscalls_few_params(*put_regs, get_regs);
        print_syscalls_regular_params(*put_regs, get_regs);
        print_syscalls_great_params(*put_regs, get_regs);
        return (false);
    }
}

static void trace_child(trace_process_t *gb_info, child_data_t *child_info)
{
    while (42) {
        if (wait_child(gb_info->status) == true)
            break;
        ptrace(PTRACE_GETREGS, child_info->child, NULL, &(child_info->regs));
        if (child_info->regs.orig_rax <= 58) {
            (get_child_data(gb_info->in_out_syscall,
            child_info->regs, gb_info) == true) ?
            gb_info->in_out_syscall = true : (gb_info->in_out_syscall = false);
        }
        ptrace(PTRACE_SYSCALL, child_info->child, NULL, NULL);
    }
}

bool run_strace(char **av)
{
    trace_process_t trace_process;
    child_data_t child_data;

    child_data.child = create_child();
    trace_process.in_out_syscall = false;
    if (child_data.child == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        if (execvp(av[1], av + 1) == -1)
            return (false);
    } else
        trace_child(&trace_process, &child_data);
    return (true);
}

/*
** EPITECH PROJECT, 2019
** strace
** File description:
** main.c
*/

#include <stdio.h>
#include "syscalls.h"
#include "s_trace.h"

void print_syscalls_few_params(trace_process_t print_regs,
     struct user_regs_struct return_reg)
{
    switch(TAB_SYSCALLS[return_reg.orig_rax].nb_params) {
    case 1:
        printf("%s(0x%llx) = 0x%llx\n",
        TAB_SYSCALLS[return_reg.orig_rax].name,
        print_regs.tab_regs[RDI], return_reg.rax);
        break;
    case 2:
        printf("%s(0x%llx, 0x%llx) = 0x%llx\n",
        TAB_SYSCALLS[return_reg.orig_rax].name,
        print_regs.tab_regs[RDI], print_regs.tab_regs[RSI], return_reg.rax);
        break;
    case 3:
        printf("%s(0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
        TAB_SYSCALLS[return_reg.orig_rax].name, print_regs.tab_regs[RDI],
        print_regs.tab_regs[RSI], print_regs.tab_regs[RDX],
        return_reg.rax);
        break;
    }
}

void print_syscalls_regular_params(trace_process_t print_regs,
     struct user_regs_struct return_reg)
{
    switch(TAB_SYSCALLS[return_reg.orig_rax].nb_params) {
    case 4:
        printf("%s(0x%llx, 0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
        TAB_SYSCALLS[return_reg.orig_rax].name, print_regs.tab_regs[RDI],
        print_regs.tab_regs[RSI], print_regs.tab_regs[RDX],
        print_regs.tab_regs[R10], return_reg.rax);
        break;
    }
}

void print_syscalls_great_params(trace_process_t print_regs,
     struct user_regs_struct return_reg)
{
    switch(TAB_SYSCALLS[return_reg.orig_rax].nb_params) {
    case 5:
        printf("%s(0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
        TAB_SYSCALLS[return_reg.orig_rax].name, print_regs.tab_regs[RDI],
        print_regs.tab_regs[RSI], print_regs.tab_regs[RDX],
        print_regs.tab_regs[R10], print_regs.tab_regs[R8],
        return_reg.rax);
        break;
    case 6:
        printf("%s(0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx) = 0x%llx\n",
        TAB_SYSCALLS[return_reg.orig_rax].name, print_regs.tab_regs[RDI],
        print_regs.tab_regs[RSI], print_regs.tab_regs[RDX],
        print_regs.tab_regs[R10], print_regs.tab_regs[R8],
        print_regs.tab_regs[R9], return_reg.rax);
        break;
    }
}

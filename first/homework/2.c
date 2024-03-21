#include<inttypes.h>
#include<stdint.h>
#include<stdio.h>
#define UNW_LOCAL_ONLY
#include <libunwind.h>

void print_stack_trace_fp_chain() 
{
    printf("Stack trace from fp chain");
    unw_cursor_t cursor;
    unw_context_t uc;
    unw_word_t pc,sp;

    unw_getcontext(&uc);
    unw_init_local(&cursor,&uc);

    while(unw_step(&cursor) > 0)
    {
        unw_get_reg(&cursor, UNW_REG_IP, &pc);
        unw_get_reg(&cursor, UNW_REG_SP, &sp);

        printf("Return address: 0x%016" PRIxPTR "\n", pc);
        printf("Old stack pointer: 0x%016" PRIxPTR "\n", sp);
        printf("\n");
    }
    printf("END\n");
}
//还是极少数为C语言安装外部库，本来都准备使用backtrace函数了
int main()
{
    print_stack_trace_fp_chain();
    return 0;
}
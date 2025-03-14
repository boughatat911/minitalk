#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include "ft_printf.h"
int main()
{
    int x = ft_printf("%c%jm9%m\n",'\0');
    int q =    printf("%c%jm9%m\n",'\0');
    printf("{%d}\n{%d}\n",x,q);
}
#ifndef TEST_H
# define TEST_H

#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "./libft/includes/libft.h"

typedef struct s_color
{
	char	code[500];
	float	red;
	float	green;
	float	blue;
}	t_color;

typedef struct ListNode
{
	int				num;
	struct ListNode	*next;

}	t_ln;

#endif
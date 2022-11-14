//Rodar através de ./03
//Funções ft_* foram desenvolvidas por mim durante o currículo da 42
//elas se encontram na biblioteca libft usada
#include "test.h"

static void	std_error(int nbr)
{
	if (nbr == 1)
	{
		ft_printf("Invalid Syntax\nTry using 0xRRGGBB\n");
		exit(nbr);
	}
}

static void	check_color(t_color *color)
{
	int	len;
	int	i;

	len = ft_strlen(color->code);
	i = 2;
	if (len > 8 || len < 3 || len == 5 || len == 7)
		std_error(1);
	else if (color->code[0] != '0' || color->code[1] != 'x')
		std_error(1);
	else if (len == 3 && color->code[i] != 0)//exceção do preto 0x0
		std_error(1);
	else
	{
		i = 2;
		while (color->code[i])
		{
			if (!ft_isdigit(color->code[i]) && (color->code[i] < 'A' || color->code[i] > 'F' ))
				std_error(1);
			i++;
		}
	}
}

int	main(void)
{
	t_color	color_start;
	t_color	color_end;
	int		steps;

	ft_printf("cor_inicial:");
	scanf("%s", color_start.code);
	check_color(&color_start);
	ft_printf("cor_final:");
	scanf("%s", color_end.code);
	check_color(&color_end);
	ft_printf("steps:");
	scanf("%d", &steps);
	return (0);
}
//Rodar através de ./03
//Funções ft_* foram desenvolvidas por mim durante o currículo da 42
//elas se encontram na biblioteca libft usada
#include "test.h"

//saida de erro padrão
static void	std_error(int nbr)
{
	if (nbr == 1)
	{
		ft_printf("Invalid Syntax\nTry using 0xRRGGBB\n");
		exit(nbr);
	}
	return ;
}

//inciar as variaveis
static void	init_color(t_color *color)
{
	int	i;

	i = 0;
	scanf("%s", color->code);
	while (color->code[i]) //uppercase
	{
		if (color->code[i] >= 'a' && color->code[i] <= 'f')
			color->code[i] -= 32;
		i++;
	}
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	return ;
}

//transforma hexadecimal em int
static void	htoi(t_color *color, int i, char local)
{
	if (local == 'r')
	{
		if (color->code[i] >= '0' && color->code[i] <= '9')
			color->red = color->red * 16 + color->code[i] - '0';
		else if (color->code[i] >= 'A' && color->code[i] <= 'F')
			color->red = color->red * 16 + color->code[i] - 'A' + 10;
	}
	else if (local == 'g')
	{
		if (color->code[i] >= '0' && color->code[i] <= '9')
			color->green = color->green * 16 + color->code[i] - '0';
		else if (color->code[i] >= 'A' && color->code[i] <= 'F')
			color->green = color->green * 16 + color->code[i] - 'A' + 10;
	}
	else if (local == 'b')
	{
		if (color->code[i] >= '0' && color->code[i] <= '9')
			color->blue = color->blue * 16 + color->code[i] - '0';
		else if (color->code[i] >= 'A' && color->code[i] <= 'F')
			color->blue = color->blue * 16 + color->code[i] - 'A' + 10;
	}
	return ;
}

//determina onde vao ser adicionados os valores
static void	convert(t_color *color, int len, int i)
{
	if (len == 3)
		return ;
	else if (len == 4) //0xBB
	{
		if (i == 2 || i == 3)
			htoi(color, i, 'b');
	}
	else if (len == 6) //0xGGBB
	{
		if (i == 2 || i == 3)
			htoi(color, i, 'g');
		else if (i == 4 || i == 5)
			htoi(color, i, 'b');
	}
	else //0xRRGGBB
	{
		if (i == 2 || i == 3)
			htoi(color, i, 'r');
		else if (i == 4 || i == 5)
			htoi(color, i, 'g');
		else if (i == 6 || i == 7)
			htoi(color, i, 'b');
	}
	return ;
}

//checa a entrada
static void	check_color(t_color *color)
{
	int	len;
	int	i;

	len = ft_strlen(color->code);
	i = 2;
	if (len > 8 || len < 3 || len == 5 || len == 7) // exceção 0x 0xGGB 0xRRGGB
		std_error(1);
	else if (color->code[0] != '0' || color->code[1] != 'x') // exceção 0x1
		std_error(1);
	else if (len == 3 && color->code[2] != '0') //exceção do preto 0x0
		std_error(1);
	else
	{
		i = 2;
		while (color->code[i])
		{
			if (!ft_isdigit(color->code[i]) && (color->code[i] < 'A'
					|| color->code[i] > 'F' ))
				std_error(1);
			else
				convert(color, len, i);
			i++;
		}
	}
	return ;
}

static void	manual_write(int i)
{
	if (i == 0)
		write(1, "00", 2);
	else if (i == 1)
		write(1, "01", 2);
	else if (i == 2)
		write(1, "02", 2);
	else if (i == 3)
		write(1, "03", 2);
	else if (i == 4)
		write(1, "04", 2);
	else if (i == 5)
		write(1, "05", 2);
	else if (i == 6)
		write(1, "06", 2);
	else if (i == 7)
		write(1, "07", 2);
	else if (i == 8)
		write(1, "08", 2);
	else if (i == 9)
		write(1, "09", 2);
	else if (i == 10)
		write(1, "0A", 2);
	else if (i == 11)
		write(1, "0B", 2);
	else if (i == 12)
		write(1, "0C", 2);
	else if (i == 13)
		write(1, "0D", 2);
	else if (i == 14)
		write(1, "0E", 2);
	else if (i == 15)
		write(1, "0F", 2);
}

static void	print_color(t_color *color)
{
	write(1, "0x", 2);
	if (color->red > 15)
		ft_putbase(color->red, HEXA_UPPER);
	else
		manual_write(color->red);
	if (color->green > 15)
		ft_putbase(color->green, HEXA_UPPER);
	else
		manual_write(color->green);
	if (color->blue > 15)
		ft_putbase(color->red, HEXA_UPPER);
	else
		manual_write(color->green);
	write(1, "\n", 1);
}

//calcula e imprime os resultados dos passos
static void	print_steps(t_color *start, t_color *end, int steps)
{
	int	dr;
	int	dg;
	int	db;

	dr = (end->red - start->red);
	dg = (end->green - start->green);
	db = (end->blue - start->blue);
	if (abs(dr) < steps)
		steps = abs(dr);
	if (abs(dg) < steps)
		steps = abs(dg);
	if (abs(db) < steps)
		steps = abs(db);
	dr = dr / steps;
	dg = dg / steps;
	db = db / steps;
	ft_printf("output_esperado:\n");
	while (steps)
	{
		start->red += dr;
		start->green += dg;
		start->blue += db;
		if (steps != 1)
			print_color(start);
		else
			print_color(end);
		steps--;
	}
}

int	main(void)
{
	t_color	start;
	t_color	end;
	int		steps;

	ft_printf("cor_inicial:");
	init_color(&start);
	check_color(&start);
	ft_printf("cor_final:");
	init_color(&end);
	check_color(&end);
	ft_printf("steps:");
	scanf("%d", &steps);
	if (steps > 255)
		steps = 255;
	else if (steps < 0)
		steps *= -1;
	print_steps(&start, &end, steps);
	return (0);
}

//Rodar através de ./02
//Funções ft_* foram desenvolvidas por mim durante o currículo da 42
//elas se encontram na biblioteca libft usada
#include "test.h"

//standard error returns
static void	std_error(int nbr)
{
	if (nbr == 1)
	{
		ft_printf("Invalid Syntax\n");
		exit(nbr);
	}
	else if (nbr == 2)
	{
		ft_printf("Invalid roman character.\nPlease use only I V X L C D M\n");
		exit(nbr);
	}
}

//convert each char to an int
static int	roman(char c)
{
	if (c == 'I')
		return (1);
	else if (c == 'V')
		return (5);
	else if (c == 'X')
		return (10);
	else if (c == 'L')
		return (50);
	else if (c == 'C')
		return (100);
	else if (c == 'D')
		return (500);
	else if (c == 'M')
		return (1000);
	return (0);
}

//checa a necessidade de um caracter especifico quando for subtrair
static int	check_previous(char *str, int i)
{
	if (str[i + 1] == 'V' && str[i] != 'I')
		return (1);
	else if (str[i + 1] == 'X' && str[i] != 'I')
		return (1);
	else if (str[i + 1] == 'L' && str[i] != 'X')
		return (1);
	else if (str[i + 1] == 'C' && str[i] != 'X')
		return (1);
	else if (str[i + 1] == 'D' && str[i] != 'C')
		return (1);
	else if (str[i + 1] == 'M' && str[i] != 'C')
		return (1);
	return (0);
}

//checa se o caracter é V L ou D
static int	check_five(char c)
{
	if (c == 'V' || c == 'L' || c == 'D')
		return (1);
	return (0);
}

//checa a ordem da string
static void	check_order(char *str, int i)
{
	int	len;

	len = ft_strlen(str);
	if ((len - i) > 2)
	{
		if (roman(str[i]) < roman(str[i + 2])) //checando a ordem dos caracteres
			std_error(1);
	}
}

//validaçào da string
static void	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == str[i + 1] && str[i] == str[i + 2]
			&& str[i] == str[i + 3]) //checando se há 4 caracteres repetidos
			std_error(1);
		else if (roman(str[i]) == 0) //checando as entradas válidas
			std_error(2);
		else if (roman(str[i]) < roman(str[i + 1]))
		{
			if (str[i] == str[i + 2]) // checando ixii
				std_error(1);
			else if (check_previous(str, i)) // checando mvm
				std_error(1);
		}
		else if (str[i] == str[i + 1] && check_five(str[i])) // checando vvv
			std_error(1);
		check_order(str, i); //checa ixv ixl
		i++;
	}
}

//faz a conversão romano para inteiro
static int	rtoi(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (roman(str[i]) >= roman(str[i + 1]))
			ret += roman(str[i]);
		else
		{
			ret = ret + (roman(str[i + 1]) - roman(str[i]));
			i++;
		}
		i++;
	}
	return (ret);
}

int	main(void)
{
	char	str[1000];
	int		i;

	i = 0;
	ft_printf("Input roman number:\n");
	scanf("%s", str);
	while (str[i]) //normalizando a linha para letras maiúsculas
	{
		if (str[i] > 'a' && str[i] < 'z')
		str[i] = str[i] - 32;
		i++;
	}
	check_string(str);
	ft_printf("%s = %d\n", str, rtoi(str));
	return (0);
}

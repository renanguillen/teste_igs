//Rodar através de ./01 FILE_NAME
//Funções ft_* foram desenvolvidas por mim durante o currículo da 42
//elas se encontram na biblioteca libft usada
#include "test.h"

//checagem de entrada
static int	check_args(int argc, char **argv)
{
	int	len;
	int	fd;

	len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		ft_printf("Invalid syntax\nPlease run with ./01 FILENAME.txt\n");
		exit (1);
	}
	else if (argv[1][len - 4] != '.' || argv[1][len - 3] != 't' ||
		argv[1][len - 2] != 'x' || argv[1][len - 1] != 't')
	{
		ft_printf("Invalid file type\n");
		exit (2);
	}
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file\n");
		exit (3);
	}
	return (fd);
}

//considerando um palindromo de caracteres pares
static int	check_even(char *line, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (line[i] == line[i + 1])
	{
		while (line[i - j] == line[i + 1 + j])
		{
			count += 2;
			j++;
			if (((i - j) < 0) || !line[i + 1 + j])
				break ;
		}
	}
	return (count);
}

//considerando um palindromo de caracteres impares
static int	check_odd(char *line, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (line[i] == line[i + 2])
	{
		while (line[i - j] == line[i + 2 + j])
		{
			count += 2;
			j++;
			if (((i - j) < 0) || !line[i + 2 + j])
				break ;
		}
		count += 1;
	}
	return (count);
}

//checa os palindromos por linha
static int	check_line(char *line)
{
	int	even;
	int	odd;
	int	greater;
	int	i;

	i = 0;
	greater = 0;
	while (line[i])//normalizando a linha para letras minúsculas
	{
		if (line[i] > 'A' && line[i] < 'Z')
		line[i] = line[i] + 32;
		i++;
	}
	i = 0;
	while (line[i])//checando por palindromos impares e pares
	{
		even = check_even(line, i);
		odd = check_odd(line, i);
		i++;
		if (even > greater)
			greater = even;
		if (odd > greater)
			greater = odd;
	}
	return (greater);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		linenbr;
	char	*str;
	int		ret;

	ret = 0;
	linenbr = 1;
	fd = check_args(argc, argv);
	str = ft_get_next_line(fd);//Armazena em str uma linha do arquivo
	while (str)
	{
		ret = check_line(str);
		ft_printf("Linha %d: %d\n", linenbr++, ret);
		ft_pointerfree (str);//Free com checagem para não dar free duplo
		str = ft_get_next_line(fd);
	}
	ft_pointerfree(str);
	return (ret);
}

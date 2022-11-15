//Rodar através de ./04
//Funções ft_* foram desenvolvidas por mim durante o currículo da 42
//elas se encontram na biblioteca libft usada
//a ordem inicial das listas não foi tratada, pois o problema
//assume que elas estariam em ordem
#include "test.h"

//saida de erro padrão
static void	std_error(int nbr)
{
	if (nbr == 1)
	{
		ft_printf("Invalid Syntax\nTry using [[1,2,3],[3,4,5],[4,5,6]]\n");
		exit(nbr);
	}
	return ;
}

//cria novo nó com valor num
static t_ln	*new_node(int num)
{
	t_ln	*new;

	new = (t_ln *)malloc(sizeof(t_ln));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

//encontra a ultima posicao da stack
static t_ln	*last_pos(t_ln *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

//adiciona o nó na ultima posição
static void	add_last(t_ln **list, t_ln *new)
{
	t_ln	*last;

	if (!list || !new)
		return ;
	last = last_pos(*list);
	if (last != NULL)
		last->next = new;
	else
		*list = new;
}

//transforma a str em um nó de lista
static int	get_nbr(char *str, int i, t_ln **list)
{
	int		j;
	char	*sub;

	j = 0;
	while (str[i + j] != ',' && str[i + j] != ']')
		j++;
	sub = ft_substr(str, i, j);
	if (!list)
		*list = new_node(atoi(sub));
	else
		add_last(list, new_node(atoi(sub)));
	free(sub);
	return (i + j);
}

//gera as listas
static void	create_lists(char *str, t_ln **list)
{
	int		i;
	int		len;
	int		ret;

	i = 0;
	ret = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[0] != '[' || str[len - 1] != ']')
			std_error(1);
		else if (str[i] != '[' && str[i] != ']'
			&& str[i] != ',' && (str[i] < '0' || str[i] > '9'))
			std_error(1);
		if (str[i] == ']' && str[i + 1] != ',' && str[i + 1] != 0)
			std_error(1);
		else if (str[i] == '[')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				ret++;
			else if (str[i + 1] != '[')
				std_error(1);
		}
		else if (str[i] == ',')
		{
			if (str[i + 1] != '[' && (str[i + 1] < '0' || str[i + 1] > '9'))
				std_error(1);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			i = get_nbr(str, i, list);
		i++;
	}
	return ;
}

//coloca as listas em sequência
static void	merge(t_ln **list)
{
	int		i;
	t_ln	*temp;
	t_ln	*aux;

	aux = *list;
	while (aux)
	{
		temp = aux;
		while (temp->next)
		{
			if (temp->num > temp->next->num)
			{
				i = temp->num;
				temp->num = temp->next->num;
				temp->next->num = i;
			}
			temp = temp->next;
		}
		aux = aux->next;
	}
}

int	main(void)
{
	t_ln	*list;
	t_ln	*aux;
	char	str[1000];

	list = NULL;
	ft_printf("listas = ");
	scanf("%s", str);
	create_lists(str, &list);
	merge(&list);
	aux = list;
	ft_printf("output = [%d", aux->num);
	aux = aux->next;
	while (aux)
	{
		ft_printf(",%d", aux->num);
		aux = aux->next;
	}
	ft_printf("]");
	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
	list = NULL;
	aux = NULL;
}

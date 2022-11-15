//Rodar através de ./05
#include <stdio.h>
#include <stdlib.h>

#define LIN_MAX 3
#define COL_MAX 5

//livra o conteudo do slot
static void	free_slot(int **slot)
{
	int	i;

	i = 0;
	if (slot)
	{
		while (i < 3)
			free(slot[i++]);
		free(slot);
	}
	return ;
}

//cria um slot novo
static int	**slot_in(void)
{
	int	i;
	int	j;
	int	**slot;

	i = 0;
	slot = malloc(sizeof(int *) * LIN_MAX);
	while (i < LIN_MAX)
		slot[i++] = malloc(sizeof(int) * COL_MAX);
	i = 0;
	while (i < LIN_MAX)
	{
		j = 0;
		printf("Insira os valores da linha %d:\n", (i + 1));
		while (j < COL_MAX)
			scanf("%d", &slot[i][j++]);
		i++;
	}
	return (slot);
}

//checa se o slot inserido é o premiado
static int	check(int **slot, int prize[LIN_MAX][COL_MAX])
{
	int	counter;
	int	j;
	int	i;

	i = 0;
	counter = 0;
	while (i < LIN_MAX)
	{
		j = 0;
		while (j < COL_MAX)
		{
			if (slot[i][j] == prize[i][j])
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	main(void)
{
	int	prize[LIN_MAX][COL_MAX] = {{1, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}};
	int	**slot;

	slot = NULL;
	while (1)
	{
		free_slot(slot);
		slot = slot_in();
		if (check(slot, prize) == (LIN_MAX * COL_MAX))
		{
			printf("Ganhou!\n");
			break ;
		}
		else
			printf("Tente Novamente\n");
	}
	return (0);
}

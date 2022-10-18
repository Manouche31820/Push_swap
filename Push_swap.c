#include "Push_swap.h"

void	rrr(piles *AB)
{
	rra(AB);
	rrb(AB);
	printf("----------------rrr-------------------\n");
	//ft_print_pile(AB);
}

void	rrb(piles *AB)
{
	pile *B = AB->Pile_B;
	pile *tmp = AB->Pile_B;

	if (B == NULL || B->suivant == NULL)
		return;
	while (B->suivant && B->suivant->suivant)
		B = B->suivant;
	AB->Pile_B = B->suivant;
	B->suivant->suivant = tmp;
	B->suivant = NULL;
	printf("----------------rrb-------------------\n");
	//ft_print_pile(AB);
}

void	rra(piles *AB)
{
	pile *A = AB->Pile_A;
	pile *tmp = AB->Pile_A;

	if (A == NULL || A->suivant == NULL)
		return;
	while (A->suivant && A->suivant->suivant)
		A = A->suivant;
	AB->Pile_A = A->suivant;
	A->suivant->suivant = tmp;
	A->suivant = NULL;
	printf("----------------rra-------------------\n");
	//ft_print_pile(AB);
}

void	rr(piles *AB)
{
	ra(AB);
	rb(AB);
	printf("----------------rr-------------------\n");
	//ft_print_pile(AB);
}

void	rb(piles *AB)
{

	pile *B = AB->Pile_B;
	pile *tmp = AB->Pile_B;
	if (B == NULL)
		return;
	AB->Pile_B = B->suivant;
	while (B->suivant)
		B = B->suivant;
	tmp->suivant = NULL;
	B->suivant = tmp;
	printf("----------------rb-------------------\n");
	//ft_print_pile(AB);
}

void	ra(piles *AB)
{

	pile *A = AB->Pile_A;
	pile *tmp = AB->Pile_A;
	if (A == NULL)
		return;
	AB->Pile_A = A->suivant;
	while (A->suivant)
		A = A->suivant;
	tmp->suivant = NULL;
	A->suivant = tmp;
	printf("----------------ra-------------------\n");
	//ft_print_pile(AB);
}

void	pa(piles *AB)
{
	pile *A = AB->Pile_A;
	pile *B = AB->Pile_B;
	if (A == NULL)
		return;
	AB->Pile_A = AB->Pile_B;
	AB->Pile_B = B->suivant;
	AB->Pile_A->suivant = A;
	printf("----------------pa-------------------\n");
	//ft_print_pile(AB);
}
void	pb(piles *AB)
{
	pile *A = AB->Pile_A;
	pile *B = AB->Pile_B;
	if (A == NULL)
		return;
	AB->Pile_B = AB->Pile_A;
	AB->Pile_A = A->suivant;
	AB->Pile_B->suivant = B;
	printf("----------------pb-------------------\n");
	//ft_print_pile(AB);
}

void	ft_print_pile(piles *AB)
{
	pile *A = AB->Pile_A;
	pile *B = AB->Pile_B;
	printf("PILE A : ");
	while (A != NULL)
	{
			printf("[%i] ", A->nbr);
			printf(" <-index[%i] ", A->index_final);
			A = A->suivant;
	}
	printf("\n");
	printf("\n");
	printf("PILE B : ");
	while (B != NULL)
	{
		if(B != NULL)
		{
			printf("[%i] ", B->nbr);
			B = B->suivant;
		}
		
	}
	printf("\n");
	printf("\n");
}

int ft_atoi(char *argv)// mettre la fonction perso
{
	return (atoi(argv));
}

void	sa_sb(piles *AB)
{
	sa(AB);
	sb(AB);
	printf("----------------ss-------------------\n");
	//ft_print_pile(AB);
}

void 	sb(piles *AB)
{
	pile *B = AB->Pile_B;
	pile *tmp; 

	if (B == NULL || B->suivant == NULL)
		return ;
	tmp = B->suivant;
	B->suivant = B->suivant->suivant;
	tmp->suivant = B;
	AB->Pile_B = tmp;
	printf("----------------sb-------------------\n");
	//ft_print_pile(AB);
}

void 	sa(piles *AB)
{
	pile *A = AB->Pile_A;
	pile *tmp; 

	if (A == NULL || A->suivant == NULL)
		return ;
	tmp = A->suivant;
	A->suivant = A->suivant->suivant;
	tmp->suivant = A;
	AB->Pile_A = tmp;
	printf("----------------sa-------------------\n");
	//ft_print_pile(AB);
}

//------------------------------------------------------------------------------//

piles  	*ft_compare(piles *AB, int *count)
{
	while (ft_solved(AB, count) != true)
	{
		if(AB->Pile_A->suivant == NULL)
			return(AB);
		pile *tmp = AB->Pile_A;
		while (tmp->suivant != NULL)
			tmp = tmp->suivant;
		if(AB->Pile_A->suivant != NULL && AB->Pile_A->suivant->suivant != NULL && AB->Pile_A->nbr > tmp->nbr && tmp->nbr > AB->Pile_A->suivant->suivant->nbr) //checker 1 et last pile A pour RRA
		{
			printf("opti");
			rra(AB);
			(*count)++;
			sa(AB);
			(*count)++;
			ra(AB);
			(*count)++;
		}
		if(AB->Pile_A->suivant != NULL && AB->Pile_A->nbr > AB->Pile_A->suivant->nbr)	
		{
			sa(AB);
			(*count)++;
		}
		else if (AB->Pile_A->suivant != NULL && AB->Pile_A->nbr < AB->Pile_A->suivant->nbr)
		{
			pb(AB);
			(*count)++;
			if (AB->Pile_B != NULL && AB->Pile_B->suivant != NULL && AB->Pile_B->nbr < AB->Pile_B->suivant->nbr)
			{
				pile *tmp = AB->Pile_B;
				while (tmp->suivant != NULL)
					tmp = tmp->suivant;
				if (AB->Pile_B->nbr < tmp->nbr && AB->Pile_B->suivant->suivant != NULL)//inverser premier et dernier de pile B
				{
					rrb(AB);
					(*count)++;
					sb(AB);
					(*count)++;
					rb(AB);
					(*count)++;
				}
				if (AB->Pile_B->nbr < AB->Pile_B->suivant->nbr)
				{
					sb(AB);
					(*count)++;
				}
			}
		}
	}
	return(AB);
}

void	push_swap(piles *AB)
{
	int count = 0;
	while (ft_solved(AB, &count) != true)
	{
		ft_compare(AB, &count);
		while(AB->Pile_B)
		{
			pa(AB);
			count++;
		}
	}
}

int ft_check_tirage(int random_value, pile *pile_A)
{
	while (pile_A)
	{
		if (pile_A->nbr == random_value)
			return(1);
		pile_A = pile_A->suivant;
	}
	return (0);
}

int ft_tirage(pile *pile_A)
{
	int random_value;

	random_value = rand () % 2;
	if(random_value == 0)
		random_value = rand() % 100;
	else if(random_value == 1)
		random_value = rand() % 100 * (-1);
	if (ft_check_tirage(random_value, pile_A) == 0)
		return(random_value);
	ft_tirage(pile_A);
}

//int ft_parsing(char **argv)


int main (int ac,char **argv)
{
	int i;
	int j;
	piles *AB;
	int k;

	AB = malloc(sizeof(piles));
	AB->Pile_A = NULL;
	AB->Pile_B = NULL;
	AB->count = 0;

	i = 10;
	j = ac - 1;
	printf("%d\n", j);
	srand( time( NULL ) );
	if (ac > 1)
	{
		while (j >= 1)
		{
			AB->Pile_A = ft_push_pile(atoi(argv[j]), AB->Pile_A);// remplacer par Ft_atoi !!
			j--;
		}
	}
	else
	{
		while(i > 0)
		{
			AB->Pile_A = ft_push_pile(ft_tirage(AB->Pile_A), AB->Pile_A);
			i--;
		}
	}
	ft_put_index(AB);
	k = ft_index(AB);
	printf("Il y a [%d] a trier", k);
	printf("----------------LISTE ORIGINALE----------------\n");
	ft_print_pile(AB);
	push_swap(AB);
	ft_print_pile(AB);
	return(0);
}
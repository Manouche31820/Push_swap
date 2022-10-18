#include "Push_swap.h"

bool ft_solved(piles *AB, int *count)
{
	pile *tmp = AB->Pile_A;

	while (tmp->suivant)
	{
		if(tmp->nbr < tmp->suivant->nbr)
			tmp = tmp->suivant;
		else
			return(false);
	}
	if(AB->Pile_B == NULL && tmp->suivant == NULL)
	{
		printf("Probleme resolu en %d coups\n", *count);
		return (true);
	}
	else
		return (false);
}

int 	ft_pilecontient(int nbr, pile *A)
{
	pile *resultat = A;
	while (resultat != NULL)
	{
		if(resultat->nbr != nbr)
		{
			resultat = resultat->suivant;
		}
		else
		{
			printf("Error\n");
			exit (1) ;
		}
	}
	return (0);
}

pile	*ft_push_pile(int nbr, pile *A)
{
	pile *resultat = malloc(sizeof(pile));
	resultat->nbr = nbr;
	resultat->suivant = A;
	return (resultat);
}


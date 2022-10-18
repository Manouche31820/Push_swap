#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
//#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
	false,
	true
}bool;

typedef struct pile
{
	int nbr;
	int index_final;
	struct pile *suivant;
}pile;

typedef struct piles
{
	struct pile *Pile_A;
	struct pile *Pile_B;
	int    count;
}piles;

void 	sa(piles *AB);
void 	sb(piles *AB);
void	rb(piles *AB);
void	ra(piles *AB);
void	rrb(piles *AB);
void	rra(piles *AB);
void	rrr(piles *AB);
void	pa(piles *AB);
void	pb(piles *AB);
int 	ft_atoi(char *argv);// mettre la fonction perso
void	push_swap(piles *AB);
void	ft_print_pile(piles *AB);
int 	ft_index(piles *AB);
int 	ft_pilecontient(int nbr, pile *A);
pile	*ft_push_pile(int nbr, pile *A);
bool 	ft_solved(piles *AB, int *count);
piles  	*ft_compare(piles *AB, int *count);
int 	ft_check_tirage(int random_value, pile *pile_A);
int 	ft_tirage(pile *pile_A);
void 	ft_put_index(piles *AB);


#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "blackjack.h"
void initgame(card *shoe, int p, int c, int d) {
	pno = p;
	cno = c;
	dstop = d;
	shoe = (card *)malloc(sizeof(card) * cno);
	players = (hand *)malloc(sizeof(hand) * pno);
}
void initdeck(card *shoe, int cno) {
	int decks = cno / 52;
	int i, k;
	char x;
	k = 0;
	while(decks) {
		i = 1;
		x = 'c';
		while(i < 14) {
			shoe[k].suite = x;
			shoe[k].rank = i;
			sprintf(shoe[k].val, "cards_png/%c%d.png", x, i);
			k++;
			i++;
		}
		i = 1;
		x = 'd';
		while(i < 14) {
			shoe[k].suite = x;
			shoe[k].rank = i;
			sprintf(shoe[k].val, "card_png/%c%d.png", x, i);
			k++;
			i++;
		}
		i = 1;
		x = 'h';
		while(i < 14) {
			shoe[k].suite = x;
			shoe[k].rank = i;
			sprintf(shoe[k].val, "cards_png/%c%d.png", x, i);
			k++;
			i++;
		}
		i = 1;
		x = 's';
		while(i < 14) {
			shoe[k].suite = x;
			shoe[k].rank = i;
			sprintf(shoe[k].val, "cards_png/%c%d.png", x, i);
			k++;
			i++;
		}
		decks--;
	}
}
void shuffle(card *shoe) {
}
void deal(card *shoe, int pno) {
	int i, j, k;
	k = 0;
	/*First card goes to dealer*/
	dealer.a[0] = shoe[k];
	k++;
	/*Give cards to all players*/
	while(i < pno) {
		j = 0;
		while(j < 2) {
			players[i].a[j] = shoe[k];
			j++;
			k++;
		}
		i++;
	}
	/*Last card goes to dealer*/
	dealer.a[1] = shoe[k];
	return;
}
/*int main() {
	card *shoe;
	initgame(shoe, 1, 52, 0);
	initdeck(shoe, 52);
	int i, j;
	i = 0;
	while(i < 52) {
		printf("%s\n", shoe[i].val);
		i++;
	}
	i = 0;
	j = 0;
	deal(shoe, 1);
	printf("Player: ");
	while(i < pno) {
		while(j < 2) {
			printf("%s ", players[i].a[j].val);
			j++;
		}
		printf("\n");
		i++;
	}
	return 0;
}*/

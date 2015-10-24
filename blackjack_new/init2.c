#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blackjack.h"
card* initshoe(int c) {
	cno = c;
	card *s;
	s = (card *)malloc(sizeof(card) * c);
	/*now i will initialise the deck*/
	initdeck(cno, s);
	return s;
}
void initdeck(int cno, card *shoe) {
	int decks = cno;
	int i, k;
	char x;
	k = 0;
	while(decks) {
		i = 1;
		x = 'c';
		while(i < 14) {
			shoe[k].suite = x;
			shoe[k].rank = i;
			if(i < 10)
				sprintf(shoe[k].val, "%c%d", x, i);
			else
				sprintf(shoe[k].val, "%c1%d", x, (i % 10));
			i++;
			k++;
		}
		i = 1;
                x = 'd';
                while(i < 14) {
                        shoe[k].suite = x;
                        shoe[k].rank = i;
			if(i < 10)
                	        sprintf(shoe[k].val, "%c%d", x, i);
			else
				sprintf(shoe[k].val, "%c1%d", x, (i % 10));
                        i++;
                        k++;
                } 
		i = 1;
                x = 'h';
                while(i < 14) {
                        shoe[k].suite = x;
                        shoe[k].rank = i;
			if(i < 10)
                        	sprintf(shoe[k].val, "%c%d", x, i);
			else
				sprintf(shoe[k].val, "%c1%d", x, (i % 10));
                        i++;
                        k++;
                } 
		i = 1;
                x = 's';
                while(i < 14) {
                        shoe[k].suite = x;
                        shoe[k].rank = i;
			if(i < 10)
                        	sprintf(shoe[k].val, "%c%d", x, i);
			else
				sprintf(shoe[k].val, "%c1%d", x, (i % 10));
                        i++;
                        k++;
                }
		decks--;
	}
	return;
}
hand* initplayers(int p) {
	pno = p;
	hand *pl;
	pl = (hand *)malloc(sizeof(hand) * p);
	return pl;
}
int main() {
	card *shoe;
	shoe = initshoe(52);
	players = initplayers(1);
	int i = 0;
	while(i < 52) {
		printf("%c %d %s\n", shoe[i].suite, shoe[i].rank, shoe[i].val);
		i++;
	}
	return 0;
}

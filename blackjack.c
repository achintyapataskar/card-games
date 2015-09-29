#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackjack.h"
void inithand(hand *a) {
	a->ncards = 0;
	a->sum = 0;
	return;
}
void deck(card *a, int state) {
	char s[8];
	int i, k;
	switch(state) {
		case 1:
			strcpy(s, "Club");
			state++;
			i = 0;
			break;
		case 2:
			strcpy(s, "Diamond");
			state++;
			i = 13;
			break;
		case 3:	
			strcpy(s, "Spade");
			state++;
			i = 26;
			break;
		case 4:
			strcpy(s, "Heart");
			state++;
			i = 39;
			break;
		default:
			printf("Initialization Finished");	
			break;
	}
	k = i + 13;
	while(i < k) {
		strcpy(a[i].suite, s);
		a[i].rank = (i % 13) + 1;
		i++;
	}
	if(state <= 4)
		deck(a, state);
	return;
}
void printdeck(card *a) {
	int i = 0;
	while(i < 52) {
		printf("%s  %d\n", a[i].suite, a[i].rank);
		i++;
	}
	return;
}
void printhand(hand *a) {
	int i = 0;
	printf("\n");
	while(i < a->ncards) {
		printf("%s%d\n",(a->h)[i].suite, (a->h)[i].rank);
		i++;
	}
	return;
}
int additup(hand *a) {
	int i = 0;
	int s = 0;
	int acecount = 0;
	checkace k[5];
/*	while(i < a->ncards) {
		if((a->h)[i].rank == 1) {
			k[i]->n = 10;
			k[i]->ace = 1;
			acecount++;
		} else if((a->h).rank > 10) {
			k[i]->n = 10;
			k[i]->ace = 0;
		} else {
			k[i]->n = (a->h)[i].rank;
			k[i]->ace = 0;
		}
		i++;
	}
	i = 0;
	*/
	return 0;
}	
/*void shuffle(card *a) {
	time_t t;
	int i = 0, n, k;
	srandom(&t);
	while(i < 10000) {
		n = random();
		n %= 52;
		k = 0;
		while()
		i++;
	}
	return 0;
}*/
void deal(card *a, hand *player, hand *dealer) {
	int i = 0;
	player->sum = dealer->sum = 0;
	(dealer->h)[0] = a[i];
	i++;
	(dealer->h)[1] = a[i];
	dealer->ncards += 2;
	i++;
	(player->h)[0] = a[i];
	i++;
	(player->h)[1] = a[i];
	player->ncards += 2;
	i++;
	
	printf("\n");
	printf("\n");
	return;
}
	
int main() {
	int s = 1;
	char c;
	deck(shoe, s);
	//printdeck(shoe);
	/*while(1) {
		shuffle(shoe);
		printdeck(shoe);
		c = getchar();
		if(c == EOF)
			break;
	}*/
	deal(shoe, &player, &dealer);
	printf("Dealer:\n");
	printhand(&dealer);
	printf("%d\n", (additup(&dealer)));
	printf("Player\n");
	printhand(&player);
	printf("%d\n", (additup(&player)));
	return 0;
}	

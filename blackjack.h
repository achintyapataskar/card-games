typedef struct card {
	char suite[8];
	int rank;
}card;
card shoe[52];
typedef struct hand {
	card h[5];
	int sum, ncards;
}hand;
typedef struct checkace {
	int n;
	int ace;
}checkace;
hand player, dealer;
int state;
void inithand(hand *a);
void printhand(hand *a);
void deck(card *a, int state);
void shuffle(card *a);
void printdeck(card *a);
void deal(card *a, hand *player, hand *dealer);
void hit(card *a);
void stand(card *a);
int additup(hand *h);

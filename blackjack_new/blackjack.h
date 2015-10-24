static int cno, pno, dstop, pindex;
typedef struct card {
	char suite;
	int rank;
	char val[8];
	GtkWidget *image;
}card;
//static card *shoe;
typedef struct hand {
	int points, pindex;
	double money, bet;
	card a[10];
}hand;
//static hand dealer;
//static hand *players;
//hand auxiliary;
/*initialise the game*/
//void initgame(card *shoe, int pno, int cno, int dstop);
hand *initplayers(int pno);
card *initshoe(int shoe);
void initdeck(int cno, card *s);
int betcheck(hand *player);
void deal(card *shoe, hand *dealer, hand *player, int pno);
card blankcard();
void initpl(hand *players, int pno);
/*player actions*/
void hit(hand *player, card *shoe);
void stand(hand *player);
void doubledown(hand *player, card *shoe);
void split(hand *player, card *shoe);
void surrender(hand *player);
void leave(hand *player);
/*calculating and checking scores*/
int checkbust(hand *player);
int checkscore(hand *player);
/*checking the dealer*/
int checkdealer(hand *dealer);
void draw(hand *dealer);
/*printing the hands*/
void printplayer(hand *player);
void printdealer(hand *dealer);
void displayscore(hand *player, hand *dealer);
/*initialise & shuffle the cards and hands*/
hand initdealer();

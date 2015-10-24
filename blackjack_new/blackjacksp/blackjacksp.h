typedef struct card {
	char suite;
	int rank;
	GtkWidget *image;
}card;
typedef struct hand {
	card h[10];
	int pos;
}hand;
GtkWidget *result, *stand, *betamt, *mnamt;
GtkWindow *window;
GtkGrid *grid, *grid1, *grid2;
int decks, ind;
double money, bet;
card *shoe;
hand player, dealer;
/*these functions initialise the game*/
void initdeck(int decks);
void shuffle();
void initmaoney();
void cb_bet(GtkWidget *widget, gpointer data);
/*these are the player actions*/
void cb_deal(GtkWidget *widget, gpointer data);
void cb_hit(GtkWidget *widget, gpointer data);
void cb_stand(GtkWidget *widget, gpointer data);
void cb_split(GtkWidget *widget, gpointer data);
void cb_double(GtkWidget *widget, gpointer data);
void cb_surrender(GtkWidget *widget, gpointer data);
/*internally working functions*/
int countace(hand a);
int psum(hand a);
void dhit();
/*result printing functions*/
void push();
void playerwin();
void dealerwin();
void playerbust();
void dealerbust();
void printmoney();

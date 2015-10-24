#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "blackjacksp.h"
void initmoney() {
	/*gives the player Rs.3000 to start with*/
	money = 3000;
	bet = 0;
	char *s;
	s = (char *)malloc(sizeof(char) * 8);
	sprintf(s,"%.2f", money);
	gtk_label_set_text((GtkLabel *)mnamt, s);
	gtk_widget_show_all((GtkWidget *)window);
}
void cb_bet(GtkWidget *widget, gpointer data) {
	/*called when bet_button is clicked*/
	/*places bets in multiples of 100*/
	bet += 100;
	money -= 100;
	char s[8];
	sprintf(s, "%.2f", bet);
	gtk_label_set_text((GtkLabel *)betamt, s);
	sprintf(s, "%.2f", money);
	gtk_label_set_text((GtkLabel *)mnamt, s);
	gtk_widget_show_all((GtkWidget *)window);
}
void cb_phit(GtkWidget *widget, gpointer *data) {
	/*a hit is when a player draws one card from shoe*/
	/*called when Hit button is clicked*/
	int sum = psum(player);
	if(sum <= 21) {
		player.h[player.pos] = shoe[ind];
	        ind++;
	        gtk_grid_attach(grid2, player.h[player.pos].image, player.pos, 0, 1, 1);
	player.pos++;
	}
	if(sum > 21) {
		playerbust();
	}
	gtk_widget_show_all((GtkWidget *)window);
}
void playerwin() {
	gtk_label_set_text((GtkLabel *)result, "You win");
}
void dealerwin() {
	gtk_label_set_text((GtkLabel *)result, "You lose");
}
int countace(hand a) {
	/*number of aces is crucial in blackjack*/
	/*number of aces affects player scores significantly*/
	int n = 0;
	int i = 0;
	while(i < a.pos) {
		if(a.h[i].rank == 1)
			n++;
		i++;
	}
	return n;
}
void dhit() {
	/*the dealer must hit, but, as per certain rules*/
	dealer.h[dealer.pos] = shoe[ind];
	ind++;
        gtk_grid_attach(grid1, dealer.h[dealer.pos].image, dealer.pos, 0, 1, 1);
	dealer.pos++;
	gtk_widget_show_all((GtkWidget *)window);
}
int psum(hand a) {
	/*sum of all cards decides who wins*/
	/*whosoever has a higher sum, without going above 21, wins*/
	int s, i, k, n;
	s = 0;
	i = 0;
	n = countace(a);
	while(i < a.pos) {
		k = a.h[i].rank;
		/*all aces and face cards are counted as 10*/
		if(k == 1 || k > 10)
			k = 10;
		s = s + k;
		i++;
	}
	/*if sum > 21 then all aces are counted as 1*/
	if(s > 21 && n)
		s = s - (n * 10) + n;
	return s;
}
void playerbust() {
	gtk_label_set_text((GtkLabel *)result, "You Bust. You lose");
}
void cb_stand(GtkWidget *widget, gpointer data) {
	/*the hole card was placed at end of dealer's hand*/
	gtk_grid_remove_column(grid1, 0);
	int i = psum(dealer);
	/*dealer hits till he scores greater than or equal to 17*/
	/*this rule is mentioned on the table at all times*/
	while(i <= 17) {
		dhit();
		i = psum(dealer);
	}
	gtk_grid_attach(grid1, dealer.h[0].image, dealer.pos, 0, 1, 1);
	int p, d;
	p = psum(player);
	d = psum(dealer);
	if(p > 21) {
		bet = 0;
		playerbust();
		gtk_widget_show_all((GtkWidget *)window);
	}
	if(p == 21 && d != 21) {
		/*a total of 21(exactly) attracts more rewards*/
		money = money + 2.5 * bet;
		playerwin();
		bet = 0;
		gtk_widget_show_all((GtkWidget *)window);
	}
	if(d > 21) {
		money = money + 2 * bet;
		bet = 0;
		dealerbust();
		gtk_widget_show_all((GtkWidget *)window);
	}
	if(p > d) {
		money = money + 2 * bet;
		bet = 0;
		playerwin();
		gtk_widget_show_all((GtkWidget *)window);
	}
	if(d > p) {
		bet = 0;
		dealerwin();
		gtk_widget_show_all((GtkWidget *)window);
	}
	if(p == d){
		money = money + bet;
		bet = 0;
		push();
		gtk_widget_show_all((GtkWidget *)window);
	}
		printmoney();
		gtk_widget_show_all((GtkWidget *)window);
}
void printmoney() {
	/*printing the status of money after a deal*/
	char s[8];
	sprintf(s, "%.2f", money);
	gtk_label_set_text((GtkLabel *)mnamt, s);
	sprintf(s, "%.2f", bet);
	gtk_label_set_text((GtkLabel *)betamt, s);
}
void push() {
	/*push means both player and dealer have same sum*/
	gtk_label_set_text((GtkLabel *)result, "It's a push");
}
void dealerbust() {
	gtk_label_set_text((GtkLabel *)result, "Dealer Busts.You win");
}
void initdeck(int decks) {
	/*initalise decks and fetch cards' images from files*/
	int i, k;
	char x, str[8];
	k = 0;
	while(decks) {
		i = 1;
		x = 'c';
		while(i < 14) {
			shoe[k].suite = x;
			shoe[k].rank = i;
			sprintf(str, "%c%d.png", x, i);
			shoe[k].image = gtk_image_new_from_file(str);
			i++;
			k++;
		}
		i = 1;
                x = 'd';
                while(i < 14) {
                        shoe[k].suite = x;
                        shoe[k].rank = i;
			sprintf(str, "%c%d.png", x, i);
			shoe[k].image = gtk_image_new_from_file(str);
                        i++;
                        k++;
                } 
		i = 1;
                x = 'h';
                while(i < 14) {
                        shoe[k].suite = x;
                        shoe[k].rank = i;
			sprintf(str, "%c%d.png", x, i);
			shoe[k].image = gtk_image_new_from_file(str);
                        i++;
                        k++;
                } 
		i = 1;
                x = 's';
                while(i < 14) {
                        shoe[k].suite = x;
                        shoe[k].rank = i;
			sprintf(str, "%c%d.png", x, i);
			shoe[k].image = gtk_image_new_from_file(str);
                        i++;
                        k++;
                }
		decks--;
	}
	return;
}
void shuffle() {
	/*shuffles cards in random order*/
}
void cb_double(GtkWidget *widget, gpointer data) {
	/*a double is when a player doubles his/her bet and promises to hit only once after that*/
	money = money - bet;
	bet = bet * 2;
	printmoney();
	gtk_widget_show_all((GtkWidget *)window);
	player.h[player.pos] = shoe[ind];
	ind++;
	gtk_grid_attach(grid2, player.h[player.pos].image, player.pos, 0, 1, 1);
	gtk_widget_show_all((GtkWidget *)window);
	player.pos++;
}
void cb_deal(GtkWidget *widget, gpointer data) {
	/*one image for the hole card*/
	/*hole card is revealed when player stands*/
	GtkWidget *image;
	/*First card goes to dealer*/
	/*this is the hole card*/
	dealer.h[0] = shoe[0];
	/*now the player gets 2 cards*/
	player.h[0] = shoe[1];
	player.h[1] = shoe[2];
	/*Now the dealer gets his next card*/
	dealer.h[1] = shoe[3];
	ind = 4;
	int i = 0;
	while(i < 2) {
		if(i == 1)
			gtk_grid_attach(grid1, dealer.h[i].image, i, 0, 1, 1);
		gtk_grid_attach(grid2, player.h[i].image, i, 0, 1, 1);
		i++;
	}
	image = gtk_image_new_from_file("ec.png");
	gtk_grid_attach(grid1, image, 0, 0, 1, 1);
	dealer.pos = 2;
	player.pos = 2;
	gtk_widget_show_all((GtkWidget *)window);
		
}
void testprint() {
	printf("Should work");
}
void button_test(GtkWidget *widget, gpointer data) {
	testprint();
}
int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	result = gtk_label_new("Your fate");
		
	shoe = (card *)malloc(sizeof(card) * 52);
	initdeck(1);
	GtkBuilder *builder;
	GtkWidget *image;
	
	GtkWidget *deal, *hit, *bet_button, *doubledown, *surrender, *split;

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "buildfile.ui", NULL);

	grid = (GtkGrid *)gtk_builder_get_object(builder, "grid");

	grid1 = (GtkGrid *)gtk_grid_new();
	grid2 = (GtkGrid *)gtk_grid_new();
	betamt = gtk_label_new(NULL);
	gtk_grid_attach(grid, betamt, 1, 3, 1, 1);
	mnamt = gtk_label_new(NULL);
	gtk_grid_attach(grid, mnamt, 4, 3, 1, 1);
	deal = (GtkWidget *)gtk_builder_get_object(builder, "deal");
	hit = (GtkWidget *)gtk_builder_get_object(builder, "hit");
	stand = (GtkWidget *)gtk_builder_get_object(builder, "stand");
	g_signal_connect(hit, "clicked", G_CALLBACK(cb_phit), NULL);
	g_signal_connect(stand, "clicked", G_CALLBACK(cb_stand), NULL);
	g_signal_connect(deal, "clicked", G_CALLBACK(cb_deal), NULL);
	gtk_grid_attach(grid, result, 2, 9, 1, 1);
	gtk_grid_attach(grid, (GtkWidget *)grid1, 1, 0, 10, 1);
	gtk_grid_attach(grid, (GtkWidget *)grid2, 1, 1, 10, 1);
	window = (GtkWindow *)gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	bet_button = gtk_button_new_with_label("Rs.100");
	gtk_grid_attach(grid, bet_button, 0, 10, 1, 1);
	g_signal_connect(bet_button, "clicked", G_CALLBACK(cb_bet), NULL);
	doubledown = (GtkWidget *)gtk_builder_get_object(builder, "doubledown");
	g_signal_connect(doubledown, "clicked", G_CALLBACK(cb_double), NULL);
	initmoney();	
	gtk_widget_show_all((GtkWidget *) window);
	
	gtk_main();
	return 0;
}

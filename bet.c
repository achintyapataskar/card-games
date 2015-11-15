/*the game of Blackjack.This is my miniproject for 2015
*    Copyright (C) 2015  Achintya Pataskar
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*  along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
#include <gtk/gtk.h>
#include <stdlib.h>
#include "cards.h"
#include "shoe.h"
#include "dealer.h"
#include "player.h"
#include "config.h"
#include "bet.h"
void bet(int amt, player *p, GtkLabel *bamt, GtkLabel *mamt) {
	if(p->money == 0)/*game ends when player has no money left*/
		return;
	if(p->bet >= 5000)/*player cannot bet more than Rs.5000 in a single hand*/
		return;
	p->money -= amt;/*changes the amount of bet and player money*/
	p->bet += amt;
	char b[32], m[32];
	sprintf(b, "%.2lf", p->bet);/*displays tha amounts of bet and money*/
	gtk_label_set_text(bamt, b);
	sprintf(m, "%.2lf", p->money);
	gtk_label_set_text(mamt, m);
}
void cb_b50(GtkWidget *widget, gpointer data) {/*these callback functions configure buttons on GUI and call bet function for calculation and display*/
	int amt = 50;
	config *c;
	c = (config *)data;
	bet(amt, c->p, c->bamt, c->mamt);
	gtk_widget_show_all((GtkWidget *)c->window);
}
void cb_b100(GtkWidget *widget, gpointer data) {
	int amt = 100;
	config *c;
	c = (config *)data;
	bet(amt, c->p, c->bamt, c->mamt);
	gtk_widget_show_all((GtkWidget *)c->window);
}
void cb_b500(GtkWidget *widget, gpointer data) {
	int amt = 500;
	config *c;
	c = (config *)data;
	bet(amt, c->p, c->bamt, c->mamt);
	gtk_widget_show_all((GtkWidget *)c->window);
}

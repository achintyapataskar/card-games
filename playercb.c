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
#include "cards.h"
#include "shoe.h"
#include "dealer.h"
#include "player.h"
#include "config.h"
#include "bet.h"

/*the functions here perform a combination of task such as calculations, display  etc..
* and they are used to configure buttons from GUI to these combinations of tasks*/

/*on pressing Deal button this function starts the hand and displays the hands of both
*dealer and player*/
void cb_deal(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	if(c->p->money > 5000000)
		return;
	gtk_label_set_text(c->result, "");
	deal(c->p, c->d, c->s, c->grid1, c->grid2);
	dealdispplayer(c->p, c->grid2);
	dealdisplay(c->d, c->grid1);
	gtk_widget_show_all((GtkWidget *)c->window);
}
/*on pressing hit this function separaterly calls hit and display functions*/
void cb_hit(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	if(playersum(c->p) >= 21) {
		display(c->p, c->grid2);
		result(c->p, c->d, c->result, c->bamt, c->mamt);
		return;
	}
	hit(c->s, c->p);
	display(c->p, c->grid2);
	if(playersum(c->p) >= 21) {
		result(c->p, c->d, c->result, c->bamt, c->mamt);
	}
	gtk_widget_show_all((GtkWidget *)c->window);
}
/*performs stand and displays result*/
void cb_stand(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	stand(c->s, c->d, c->grid1);
	result(c->p, c->d, c->result, c->bamt, c->mamt);
	gtk_widget_show_all((GtkWidget *)c->window);
}
/*performs double and displays the result*/
void cb_doubledown(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	doubledown(c->s, c->p, c->bamt, c->mamt, c->grid2);
	dhit(c->d, c->s, c->grid1);
	result(c->p, c->d, c->result, c->bamt, c->mamt);
	gtk_widget_show_all((GtkWidget *)c->window);
}
/*calls surrender function, which also changes and displays bet amount and money*/
void cb_surrender(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	surrender(c->p, c->bamt, c->mamt);
	gtk_widget_show_all((GtkWidget *)c->window);
}
/*calls the split function, split has it's own display*/
void cb_split(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	split(c->p, c->grid2);
	gtk_widget_show_all((GtkWidget *)c->window);
}

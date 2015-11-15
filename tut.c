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
#include <stdio.h>
#include "cards.h"
#include "shoe.h"
#include "dealer.h"
#include "player.h"
#include "config.h"
#include "bet.h"
#include "playercb.h"
#include "tut.h"
/*these functions change the configuration of Tutorial Button as they are executed sequentially
* they display a list of instructions for each button and the user can try the buttons within the tutorial 
* config data type is passed to these functions to give them access to all components of the game
* functions have been named to clarify the order in which they are executed
* Each function is used for a new lesson*/
void cb_first_tut(GtkWidget *widget, gpointer data) {
	config *c;
	GtkButton *next;
	c = (config *)data;
	gtk_label_set_text(c->result, "Calculating sum:\n->all aces are 10 unless the sum is above 21\n->all face cards are 10\n->all other cards are taken at their value\n\n->So, here the sum is 21\n");
	card x1, x2, x3;
	x1.suite = 'c';
	x1.rank = 9;
	x1.image = gtk_image_new_from_file("cards_png/c9.png");
	gtk_grid_attach(c->grid2, x1.image, 1, 0, 1, 1);
	x2.suite = 'd';
	x2.rank = 1;
	x2.image = gtk_image_new_from_file("cards_png/d1.png");
	gtk_grid_attach(c->grid2, x2.image, 2, 0, 1, 1);
	x3.suite = 'h';
	x3.rank = 2;
	x3.image = gtk_image_new_from_file("cards_png/h2.png");
	gtk_grid_attach(c->grid2, x3.image, 3, 0, 1, 1);
	gtk_button_set_label(c->tut, "next");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_sec_tut), (gpointer)c);
	gtk_widget_show_all((GtkWidget *)c->window);
}
void cb_sec_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Deal:\n\n->this button starts a hand\n\n->both the player and dealer get their cards\n\n->press the deal button\n\n->then click next to continue\n\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_third_tut), (gpointer)c);
}
void cb_third_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Betting:\n\n->You must bet a certain amount\n\n->You can bet only in multiples of 50, 100, 500\n\n->You cannot bet more than Rs.5500 in a single hand\n\n->click the bet buttons to bet\n\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_fourth_tut), (gpointer)data);
}
void cb_fourth_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Hit:\n\n->A hit is when you request the dealer to give you a card\n\n->you can ask for as many cards as you like\n\n->but remember that if your sum goes above 21 you lose\n\n->press \"Hit\" once and try this\n\n->click next to continue\n\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_fifth_tut), (gpointer)data);
}
void cb_fifth_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Stand:\n\n->A stand is when you tell the dealer that you want no more cards\n\n->the dealer then reveals his cards\n\n->whoever has a higher sum wins\n\n->start a new deal press the \"stand\" button and try this\n\n->The result will then be displayed here\n\n->click next to continue\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_sixth_tut), (gpointer)c);
}
void cb_sixth_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Double:\n\n->you can double your bet, but you must hit only once then stand\n\n->Place a new bet then deal\n\n->press \"Double\" and try this\n\n->Note that the result will be displayed here only\n\n->click next to continue\n\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_seventh_tut), (gpointer)c);
}
void cb_seventh_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Surrender:\n\n->If you think that odds in your favour are not good, you can forfeit\n\n->However, only 50\% of your bet amount will be returned\n\n->bet some money, start a new deal  and press \"Surrender\" to try this");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_eight_tut), (gpointer)data);
}
void cb_eight_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_label_set_text(c->result, "Split:\n\n->If you have two cards of same value then you can play two different deals\n\n->you automatically bet the same amount on one more deal\n\n->Press Split and then play both deals as two normal deals\n\n->note however that if you split then you cannot Surrender nor can you double.\n\n->splitting once more is also not allowed\n\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_nine_tut), (gpointer)data);
}
void cb_nine_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_button_set_label(c->tut, "End Turorial");
	gtk_label_set_text(c->result, "End of Tutorial\n\nClick End Tutorial to continue\n\n");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_ten_tut), (gpointer)c);
}
void cb_ten_tut(GtkWidget *widget, gpointer data) {
	config *c;
	c = (config *)data;
	gtk_button_set_label(c->tut, "Tutorial Mode");
	gtk_label_set_label(c->result, " ");
	g_signal_connect(c->tut, "clicked", G_CALLBACK(cb_first_tut), (gpointer)c);
}

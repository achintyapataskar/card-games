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
#include "bet.h"
#include "config.h"
int main(int argc, char *argv[]) {
	/*this is the main function, it nitialises the player and also gets pointers to elements of GUI from game.ui*/
	gtk_init(&argc, &argv);
	GtkWindow *window;
	GtkGrid *grid, *grid1, *grid2;
	GtkBuilder *builder;
	GtkLabel *bamt, *mamt;
	GtkButton *bdeal, *bhit;
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "game.ui", NULL);
	window = (GtkWindow *)gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	grid = (GtkGrid *)gtk_builder_get_object(builder, "grid");
	grid2 = (GtkGrid *)gtk_builder_get_object(builder, "grid2");
	grid1 = (GtkGrid *)gtk_builder_get_object(builder, "grid1");
	bamt = (GtkLabel *)gtk_builder_get_object(builder, "bamt");
	mamt = (GtkLabel *)gtk_builder_get_object(builder, "mamt");
	/*initialise characters and shoe then calls configure to configure all buttons*/
	shoe s;
	initshoe(&s, 8);
	shoeshuffle(&s);
	card x;
	config c;
	player p;
	dealer d;
	initplayer(&p);
	initdealer(&d);
	configure(builder, &c, &p, &d, &s);
	gtk_widget_show_all((GtkWidget *)window);
	gtk_main();
	return 0;
}

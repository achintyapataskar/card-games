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
#include "playercb.h"
#include "tut.h"

/* The GtkBuilder is a component initialised in the main window, it is used here to access all GUI components
 * the config data structure can now be used to access GUI copmonents and also other components, like player, dealer etc...
 * the g_signal_connect function is used to configure all buttons to callback functions*/
void configure(GtkBuilder  *builder, config *con, player *p, dealer *d, shoe *s) {
	con->p = p;
	con->d = d;
	con->s = s;
	con->window = (GtkWindow *)gtk_builder_get_object(builder, "window");
	con->grid1 = (GtkGrid *)gtk_builder_get_object(builder, "grid1");
	con->grid2 = (GtkGrid *)gtk_builder_get_object(builder, "grid2");
	con->grid4 = (GtkGrid *)gtk_builder_get_object(builder, "grid4");
	con->deal = (GtkButton *)gtk_builder_get_object(builder, "deal");
	con->hit = (GtkButton *)gtk_builder_get_object(builder, "hit");
	con->stand = (GtkButton *)gtk_builder_get_object(builder, "stand");
	con->doubledown = (GtkButton *)gtk_builder_get_object(builder, "doubledown");
	con->split = (GtkButton *)gtk_builder_get_object(builder, "split");
	con->surrender = (GtkButton *)gtk_builder_get_object(builder, "surrender");
	con->b50 = (GtkButton *)gtk_builder_get_object(builder, "b50");
	con->b100 = (GtkButton *)gtk_builder_get_object(builder, "b100");
	con->b500 = (GtkButton *)gtk_builder_get_object(builder, "b500");
	con->bamt = (GtkLabel *)gtk_builder_get_object(builder, "bamt");
	con->mamt = (GtkLabel *)gtk_builder_get_object(builder, "mamt");
	con->tut = (GtkButton *)gtk_builder_get_object(builder, "tut");
	con->result = (GtkLabel *)gtk_builder_get_object(builder, "result");
	g_signal_connect(con->deal, "clicked", G_CALLBACK(cb_deal), (gpointer)con);
	g_signal_connect(con->hit, "clicked", G_CALLBACK(cb_hit), (gpointer)con);
	g_signal_connect(con->stand, "clicked", G_CALLBACK(cb_stand), (gpointer)con);
	g_signal_connect(con->doubledown, "clicked", G_CALLBACK(cb_doubledown), (gpointer)con);
	g_signal_connect(con->surrender, "clicked", G_CALLBACK(cb_surrender), (gpointer)con);
	g_signal_connect(con->split, "clicked", G_CALLBACK(cb_split), (gpointer)con);
	g_signal_connect(con->b50, "clicked", G_CALLBACK(cb_b50), (gpointer)con);
	g_signal_connect(con->b100, "clicked", G_CALLBACK(cb_b100), (gpointer)con);
	g_signal_connect(con->b500, "clicked", G_CALLBACK(cb_b500), (gpointer)con);
	g_signal_connect(con->tut, "clicked", G_CALLBACK(cb_first_tut), (gpointer)con);
}

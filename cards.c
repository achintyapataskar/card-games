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
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "cards.h"
/*all .png images are stored in a file called cards_png
 *they are coded as <suite><rank>.png*/
void initdeck(deck *d) {
	int i = 0;
	int k;
	char str[32], x;
		while(i < 13) {
			x = 'c';
			d->arr[i].rank = i + 1;
			d->arr[i].suite = x;
			sprintf(str, "cards_png/%c%d.png", x, i + 1);
			d->arr[i].image = gtk_image_new_from_file(str);
			i++;
		}
		while(i < 26) {
			x = 'd';
			k = i % 13;
			d->arr[i].rank = k + 1;
			d->arr[i].suite = x;
			sprintf(str, "cards_png/%c%d.png", x, k + 1);
			d->arr[i].image = gtk_image_new_from_file(str);
			i++;
		}
		while(i < 39) {
			x = 'h';
			k = i % 13;
			d->arr[i].rank = k + 1;
			d->arr[i].suite = x;
			sprintf(str, "cards_png/%c%d.png", x, k + 1);
			d->arr[i].image = gtk_image_new_from_file(str);
			i++;
		}
		while(i < 52) {
			x = 's';
			k = i % 13;
			d->arr[i].suite = x;
			d->arr[i].rank = k + 1;
			sprintf(str, "cards_png/%c%d.png", x, k + 1);
			d->arr[i].image = gtk_image_new_from_file(str);
			i++;
		}
	d->index = 0;
	return;
}
/*shuffles the deck by swapping cards in two different indices*/
void shuffle(deck *d) {
	int i, j, k;
	i = 0;
	card x;
	while(i < 50)  {
		j = rand() % 52;
		k = rand() % 52;
		x = d->arr[j];
		d->arr[j] = d->arr[k];
		d->arr[k] = x;
		i++;
	}
	return;
}
/*takes a pointer to GtkWidget and GtkGrid, also int x and y for position in grid and card c for an image*/
void dispcard(GtkWidget *window, GtkGrid *grid, int x, int y, card c) {
	gtk_grid_attach(grid, c.image, x, y, 1, 1);
	gtk_widget_show_all(window);
	return;
}
/*returns a card after sequentially drawing from the deck*/
card drawcard(deck *d) {
	card x;
	x = d->arr[(d->index)];
	d->index++;
	return x;
}

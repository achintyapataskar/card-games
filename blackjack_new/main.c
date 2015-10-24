#include <gtk/gtk.h>
#include "blackjack.h"
int main(int argc, char *argv[]) {
	card *shoe;
	hand *players;
	gtk_init(&argc, &argv);
	
	shoe = initshoe(52);
	//players = initplayers(1);
	
	GtkBuilder *builder;
	GObject *window;
	GtkGrid *grid;
	GtkWidget *grid1, *grid2;

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "buildfile.ui", NULL);

	grid = (GtkGrid *)gtk_builder_get_object(builder, "grid");

	grid1 = gtk_grid_new();
	grid2 = gtk_grid_new();

	window = gtk_builder_get_object(builder, "window");
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all((GtkWidget *) window);
	
	gtk_main();
	return 0;
}

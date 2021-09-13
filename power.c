/*
power.c
Gtk-3 GUI for "shutdown", "restart", "cancel"
*/

#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

char* glade_xml = "\
<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<!-- Generated with glade 3.22.2 -->\n\
<interface>\n\
<requires lib=\"gtk+\" version=\"3.20\"/>\n\
<object class=\"GtkWindow\" id=\"window1\">\n\
<property name=\"width_request\">210</property>\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"has_focus\">True</property>\n\
<property name=\"border_width\">8</property>\n\
<property name=\"title\" translatable=\"yes\">Power</property>\n\
<property name=\"resizable\">False</property>\n\
<property name=\"modal\">True</property>\n\
<property name=\"window_position\">center</property>\n\
<property name=\"skip_taskbar_hint\">True</property>\n\
<property name=\"decorated\">False</property>\n\
<signal name=\"destroy\" handler=\"on_window1_destroy\" swapped=\"no\"/>\n\
<child type=\"titlebar\">\n\
<placeholder/>\n\
</child>\n\
<child>\n\
<object class=\"GtkBox\">\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">False</property>\n\
<property name=\"margin_left\">3</property>\n\
<property name=\"margin_right\">3</property>\n\
<property name=\"margin_top\">3</property>\n\
<property name=\"margin_bottom\">3</property>\n\
<property name=\"orientation\">vertical</property>\n\
<property name=\"spacing\">3</property>\n\
<property name=\"homogeneous\">True</property>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_shutdown\">\n\
<property name=\"label\" translatable=\"yes\">Shutdown</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_shutdown_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">True</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">0</property>\n\
</packing>\n\
</child>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_restart\">\n\
<property name=\"label\" translatable=\"yes\">Reboot</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_restart_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">True</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">1</property>\n\
</packing>\n\
</child>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_suspend\">\n\
<property name=\"label\" translatable=\"yes\">Suspend</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_suspend_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">False</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">2</property>\n\
</packing>\n\
</child>\n\
<child>\n\
<object class=\"GtkButton\" id=\"btn_close\">\n\
<property name=\"label\">gtk-cancel</property>\n\
<property name=\"visible\">True</property>\n\
<property name=\"can_focus\">True</property>\n\
<property name=\"receives_default\">True</property>\n\
<property name=\"use_stock\">True</property>\n\
<property name=\"always_show_image\">True</property>\n\
<signal name=\"clicked\" handler=\"on_btn_close_clicked\" swapped=\"no\"/>\n\
</object>\n\
<packing>\n\
<property name=\"expand\">True</property>\n\
<property name=\"fill\">True</property>\n\
<property name=\"position\">3</property>\n\
</packing>\n\
</child>\n\
</object>\n\
</child>\n\
</object>\n\
</interface>\n\
\0";

// builder = gtk_builder_new_from_string (glade_xml, -1);

// called when window is closed
void on_window1_destroy() {
    gtk_main_quit();
}

void on_btn_close_clicked() {
    on_window1_destroy();
}

void on_btn_shutdown_clicked() {
    system("shutdown now");
}

void on_btn_restart_clicked() {
    system("reboot");
}

void on_btn_suspend_clicked() {
    system("systemctl suspend");
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    // builder = gtk_builder_new();
    // gtk_builder_add_from_file (builder, "power.glade", NULL);
    builder = gtk_builder_new_from_string (glade_xml, -1);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

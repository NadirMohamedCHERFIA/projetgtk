#ifndef __DASHBOARD_H__
#define __DASHBOARD_H__
#include <gtk/gtk.h>
#include "widgets.h"
#include "dimensions.h"
#include "dbconnect.h"
#include "string.h"
#include "userStruct.h"

void handleBackDashboard(GtkWidget *butt,gpointer data);

void create_dashboard(GtkWidget *butt, gpointer data);
#endif
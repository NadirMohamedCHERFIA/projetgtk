#ifndef __DASHBOARD_H__
#define __DASHBOARD_H__
#include <gtk/gtk.h>
#include "widgets.h"
#include "dimensions.h"
#include "dbconnect.h"
#include "string.h"
#include "userStruct.h"
#include "incomeAddWindow.h"
#include "depenseAddWindow.h"
#include "incomeDetailsWindow.h"
#include "depenseDetailsWindow.h"
void handleBackDashboard(GtkWidget *butt,gpointer data);

void create_dashboard(gpointer data);
#endif
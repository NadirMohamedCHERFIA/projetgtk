#include "dimensions.h"
// #define MAINWINDOWHEIGHT 800
// #define MAINWINDOWWIDTH 1200
#define MAINWINDOWBORDERWIDTH 30
gint getScreenWidth(){
    GdkScreen *screen = gdk_screen_get_default();
    return gdk_screen_get_width(screen);

}
gint getScreenHeight(){
    GdkScreen *screen = gdk_screen_get_default();
    return gdk_screen_get_height(screen);
}

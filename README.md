# projetgtk
## Run
gcc `pkg-config --cflags gtk+-3.0` -o main *.c `mysql_config --cflags --libs` `pkg-config --libs gtk+-3.0`

## mysql
Make sure to modify the dbconnectioninfo.h file with your database information.


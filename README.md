#Gestion de depenses project
##run 
gcc `pkg-config --cflags gtk+-3.0` -o main *.c `mysql_config --cflags --libs` `pkg-config --libs gtk+-3.0`
#sql
Make sure to change the information in the dbconnectioninfo.h to your database informations
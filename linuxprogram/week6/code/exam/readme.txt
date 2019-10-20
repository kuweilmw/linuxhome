remotestatic.c
//is staticlib main.c

gcc -o remotestatic remotestatic.c ../staticlib/libmytest.a -I../staticlib

//link remote to main file to running

remotedynmic.c
//is dtnamic abase.c


gcc -o remotedynamic remotedynamic.c ../dynamiclib/libdylib.so -I../dynamiclib

//link remote to main file to running

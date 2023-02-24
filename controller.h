#ifndef __CONTROLLER__
#define __CONTROLLER__

void app(char f1[], char f2[], char f3[]);
void error_arg();
void help(char **argv);
void with_out_file(int count, char **argv);
void without_out_file(char **argv);

#endif
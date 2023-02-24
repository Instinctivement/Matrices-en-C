#ifndef __FILES__
#define __FILES__

char* read_file(const char* filename);
int write_file(const char* filename, const char* content);
int copy_file(const char* source_filename, const char* destination_filename);

void file_test();

#endif
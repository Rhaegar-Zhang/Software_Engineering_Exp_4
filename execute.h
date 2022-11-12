#ifndef EXECUTE_H
#define EXECUTE_H

#include <cstdlib>
#include <unistd.h>
#include <string>
#include <dirent.h>
#include <cstring>

class Execute{
public:
    void exec_program(std::string par_path, std::string file_name, int test_num);
};

#endif
#ifndef EXECUTE_H
#define EXECUTE_H

#include <cstdlib>
#include <unistd.h>
#include <string>
#include <dirent.h>
#include <cstring>

//Class to execute every proram to be judged and store their execute result in corresponding folder.
class Execute{
public:
    //Function to execute program with name file_name in path par_path for test_num times.
    void exec_program(std::string par_path, std::string file_name, int test_num);
};

#endif
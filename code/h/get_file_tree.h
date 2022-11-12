#ifndef GET_FILE_TREE
#define GET_FILE_TREE

#include <cstdio>
#include <unistd.h>
#include <dirent.h>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

class FileFolder{
public:
    std::string curr_dir;
    int stdin_index;
    std::vector<std::string> singal_branch;
};

class GetFileTree{
private:
    std::vector<FileFolder*>* file_tree;
    FileFolder* gen_singal_branch(char* basepath);
public:
    GetFileTree();
    ~GetFileTree();
    void gen_file_tree(char* basepath);
    std::vector<FileFolder*>* get_file_tree();
};

#endif
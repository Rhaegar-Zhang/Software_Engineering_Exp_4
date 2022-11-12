#ifndef GET_FILE_TREE
#define GET_FILE_TREE

#include <cstdio>
#include <unistd.h>
#include <dirent.h>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

class FileTreeBranch{
public:
    std::string curr_dir;
    int stdin_index;
    std::vector<std::string> singal_branch;
};

class GetFileTree{
private:
    std::vector<FileTreeBranch*>* file_tree;
public:
    GetFileTree();
    ~GetFileTree();
    void gen_file_tree(char* basepath);
    FileTreeBranch* gen_singal_branch(char* basepath);
    std::vector<FileTreeBranch*>* get_file_tree();
};

#endif
#ifndef GET_FILE_TREE
#define GET_FILE_TREE

#include <cstdio>
#include <unistd.h>
#include <dirent.h>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

//Class represents a folder and all the files in it.
class FileFolder{
public:
    //Record the path of this folder
    std::string curr_dir;
    //Record the index of stdin_format.txt in singal_branch.
    int stdin_index;
    //Record all files in this folder.
    std::vector<std::string> singal_branch;
};

//Class to get all the folders contain the programs need to be judged.
class GetFileTree{
private:
    //Record all the folders contain the programs need to be judged.
    std::vector<FileFolder*>* file_tree;
    //Read all the files in the folder whose path is same as the parameter basepath.
    FileFolder* gen_singal_branch(char* basepath);
public:
    GetFileTree();
    ~GetFileTree();
    //Get all the folders containing the programs to be judged from the input folder whose path is basepath
    void gen_file_tree(char* basepath);
    //Return all the folders contain programs to be judged.
    std::vector<FileFolder*>* get_file_tree();
};

#endif
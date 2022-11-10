#include "get_file_tree.h"

GetFileTree::GetFileTree(){
    file_tree = new std::vector<FileTreeBranch*>();
}

GetFileTree::~GetFileTree(){
    delete file_tree;
}

FileTreeBranch* GetFileTree::gen_singal_branch(char* basepath){
    DIR *dir;
    struct dirent *ptr;
    FileTreeBranch* p = new FileTreeBranch;
    if((dir = opendir(basepath)) == NULL)
        exit(1);
    int i = 0;
    p->curr_dir = std::string(basepath);
    while((ptr = readdir(dir)) != NULL){
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        else if(ptr->d_type == 8){
            std::string abs_path = std::string(basepath) + std::string(ptr->d_name);
            p->singal_branch.push_back(abs_path);
            if(abs_path.find(".txt") != std::string::npos){
                p->stdin_index = i;
            }
            i++;
        }
    }
    return p;
}

void GetFileTree::gen_file_tree(char* basepath){
    DIR *dir;
    struct dirent *ptr;
    char base[1000];
    if((dir = opendir(basepath)) == NULL)
        exit(1);
    while((ptr = readdir(dir)) != NULL){
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;
        else if(ptr->d_type == 8){
            FileTreeBranch* p = gen_singal_branch(basepath);
            file_tree->push_back(p);
            return;
        }
        else if(ptr->d_type == 4){
            memset(base, '\0', sizeof(base));
            strcpy(base, basepath);
            strcat(base, "/");
            strcat(base, ptr->d_name);
            gen_file_tree(base);
        }
    }
}

std::vector<FileTreeBranch*>* GetFileTree::get_file_tree(){
    return this->file_tree;
}

#include "../h/execute.h"
#include "../h/get_file_tree.h"
#include "../h/input.h"
#include "../h/judge.h"

int main(){
    char* base_path = "../../input";
    GetFileTree* getfile = new GetFileTree();
    Execute *exec = new Execute();
    InputGen *input_gen = new InputGen();
    Judge *judge = new Judge();
    getfile->gen_file_tree(base_path);
    std::vector<FileFolder*>* file_dirs = getfile->get_file_tree();
    for(int i = 0; i < file_dirs->size(); ++i){
        std::vector<std::string> file_folder = (*file_dirs)[i]->singal_branch;
        int stdin_index = (*file_dirs)[i]->stdin_index;
        std::string curr_dir = (*file_dirs)[i]->curr_dir;
        std::string mkdir_cmd = "mkdir " + curr_dir + "exec_res";
        system(mkdir_cmd.c_str());
        input_gen->gen_input(5, curr_dir + file_folder[stdin_index], curr_dir);
        for(int j = 0; j < file_folder.size(); ++j){
            if(file_folder[j].find(".cpp") != std::string::npos)
                exec->exec_program(curr_dir, file_folder[j], 5);
        }
        if(i == 0){
            system("mkdir ../../output");
            std::ofstream f1("../../output/equal.csv");
            std::ofstream f2("../../output/inequal.csv");
            f1 << "file1,file2\n";
            f2 << "file1,file2\n";
            f1.close();
            f2.close();
        }
        judge->judge(curr_dir, file_folder);
    }
    return 0;
}
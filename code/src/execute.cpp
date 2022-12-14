#include "../h/execute.h"

void Execute::exec_program(std::string par_path, std::string file_name, int test_num){
    std::string compile_command = "g++ " + par_path + file_name + " -o " + par_path + file_name.substr(0, file_name.find('.'));
    std::string output_file = par_path + "exec_res/" + file_name.substr(0, file_name.find('.')) + ".txt";
    std::string testcase_file = par_path + "testcases/testcase";
    system(compile_command.c_str());
    std::string del_cmd = "rm " + par_path + file_name.substr(0, file_name.find('.'));
    for(int i = 0; i < test_num; ++i){
        std::string cur_test_file = testcase_file + std::to_string(i) + ".txt";
        std::string exec_cmd = par_path + file_name.substr(0, file_name.find('.')) + " <" + cur_test_file + " >>" + output_file;
        system(exec_cmd.c_str());
    }
    system(del_cmd.c_str());
}
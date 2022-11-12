#include "../h/judge.h"

void Judge::judge(std::string cur_dir, std::vector<std::string>& file_list){
    std::string equal_file = "../../output/equal.csv";
    std::string inequal_file = "../../output/inequal.csv";
    std::ofstream equal_fout(equal_file, std::ios::app);
    std::ofstream inequal_fout(inequal_file, std::ios::app);
    for(auto i = file_list.begin(); i != file_list.end(); ++i)
        if((*i).find(".txt") != std::string::npos)
            file_list.erase(i);
    for(int i = 0; i < file_list.size(); ++i){
        std::string file1 = cur_dir + "exec_res/" + file_list[i].substr(0, file_list[i].find('.')) + ".txt";
        for(int j = i + 1; j < file_list.size(); ++j){
            std::string file2 = cur_dir + "exec_res/" + file_list[j].substr(0, file_list[j].find('.')) + ".txt";
            if(is_equal(file1, file2))
                equal_fout << file1 << ',' << file2 << '\n';
            else
                inequal_fout << file1 << ',' << file2 << '\n';
        }
    }
    std::string del_input_cmd = "rm -r " + cur_dir + "testcases";
    std::string del_exec_res = "rm -r " + cur_dir + "exec_res";
    system(del_input_cmd.c_str());
    system(del_exec_res.c_str());
}

bool Judge::is_equal(std::string file1, std::string file2){
    std::ifstream file1in, file2in;
    file1in.open(file1);
    file2in.open(file2);
    std::string file1out, file2out;
    while(!file1in.eof()){
        std::string s;
        getline(file1in, s);
        file1out += s;
    }
    while(!file2in.eof()){
        std::string s;
        getline(file2in, s);
        file2out += s;
    }
    file1in.close();
    file2in.close();
    return file1out == file2out;
}
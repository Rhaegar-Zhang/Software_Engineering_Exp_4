#ifndef JUDGE_H
#define JUDGE_H

#include <string>
#include <fstream>
#include <vector>

class Judge{
public:
    void judge(std::string cur_dir, std::vector<std::string>& file_list);
private:
    bool is_equal(std::string file1, std::string file2);
};

#endif
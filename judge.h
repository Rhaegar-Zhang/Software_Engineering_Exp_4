#include <string>
#include <fstream>
#include <vector>

class Judge{
    void judge(std::string cur_dir, std::vector<std::string> file_list);
    bool is_equal(std::string file1, std::string file2);
};
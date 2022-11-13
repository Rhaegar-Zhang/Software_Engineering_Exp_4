#ifndef JUDGE_H
#define JUDGE_H

#include <string>
#include <fstream>
#include <vector>

//Class to judge whether programs are equal or not and store the result in equal.csv if the tow programs equals to each
//other otherwise store the result in inequal.csv.
class Judge{
public:
    //Function to divide n programs in the folder cur_dir into C(n,2) groups and judge whether the two programs in the same
    //group are equal to each other. The function will store the judge result in equal.csv and inequal.csv depending on the
    //equivalence  between the programs. 
    void judge(std::string cur_dir, std::vector<std::string>& file_list);
private:
    //Function to judge whether two programs are equal.
    bool is_equal(std::string file1, std::string file2);
};

#endif
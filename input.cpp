#include "input.h"

IntInput::IntInput(int min_value, int max_value){
    this->min_value = min_value;
    this->max_value = max_value;
}

void IntInput::gen_input(){
    random_input = (rand() % (max_value - min_value + 1)) + min_value;
}

int IntInput::get_random_input(){
    return random_input;
}

StringInput::StringInput(int min_len, int max_len){
    this->min_length = min_len;
    this->max_length = max_len;
    random_input = NULL;
}

StringInput::~StringInput(){
    delete []random_input;
    random_input = NULL;
}

void StringInput::gen_input(){
    int random_len = (rand() % (max_length - min_length + 1)) + min_length;
    random_input = new char[random_len];
    for(int i = 0; i < random_len; ++i)
        random_input[i] = rand() % 2 ? 'a' + rand() % 26 : 'A' + rand() % 26;
}

char* StringInput::get_random_input(){
    return random_input;
}

void InputGen::read_stdin_file(std::string stdin_path){
    std::ifstream fin(stdin_path);
    if(!fin)
        return;
    while(!fin.eof()){
        std::string s;
        if(!getline(fin, s)) break;
        
    }
}
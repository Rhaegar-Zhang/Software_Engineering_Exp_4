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

std::vector<InputType*> InputGen::read_stdin_file(std::string stdin_path){
    std::ifstream fin(stdin_path);
    std::vector<InputType*> random_input;
    if(!fin)
        return;
    while(!fin.eof()){
        std::string s;
        fin >> s;
        if(s.substr(0, s.find('(')) == "int"){
            int min_val = stoi(s.substr(s.find('(') + 1, s.find(',')));
            int max_val = stoi(s.substr(s.find(',') + 1, s.length() - 1));
            InputType *int_input = new InputType("int", min_val, max_val);
            random_input.push_back(int_input);

        }
        else if(s == "char"){
            InputType*char_input = new InputType("char", 1, 1);
            random_input.push_back(char_input);
        }
        else if(s.substr(0, s.find('(')) == "string"){
            int min_len = stoi(s.substr(s.find('(') + 1, s.find(',')));
            int max_len = stoi(s.substr(s.find(',') + 1, s.length() - 1));
            InputType *string_input = new InputType("string", min_len, max_len);
            random_input.push_back(string_input);
        }
    }
    fin.close();
    return random_input;
}

void ::InputGen::gen_input(int num, std::string stdin_path){
    std::vector<InputType*> random_input = read_stdin_file(stdin_path);
    for(int i = 0; i < num; ++i){
        std::vector<Input*> singal_input;
        for(int j = 0; j < random_input.size(); ++j){
            if(random_input[j]->get_type() == "int"){
                Input* int_type = new IntInput(random_input[j]->get_min_val(), random_input[j]->get_max_val());
                int_type->gen_input();
                singal_input.push_back(int_type);
            }
            else if(random_input[j]->get_type() == "char"){
                Input* char_type = new CharInput();
                char_type->gen_input();
                singal_input.push_back(char_type);
            }
            else if(random_input[j]->get_type() == "string"){
                Input* string_type = new StringInput(random_input[j]->get_min_val(), random_input[j]->get_max_val());
                string_type->gen_input();
                singal_input.push_back(string_type);
            }
        }
        program_input.push_back(singal_input);
    }
}
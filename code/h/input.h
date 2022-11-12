#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

class InputType{
    std::string type;
    int min_val, max_val;
public:
    InputType(std::string _type, int _min_val, int _max_val) : type(_type), min_val(_min_val), max_val(_max_val) {}
    std::string get_type() const {return type;}
    int get_min_val() const {return min_val;}
    int get_max_val() const {return max_val;}
};

//Base class of all possible inputs.
class Input{
public:
    virtual void gen_input() = 0;
    virtual ~Input() {}
};

//Class represents input with type of integer
class IntInput : public Input {
public:
    IntInput(int, int);
    void gen_input();
    int get_random_input();
private:
    int min_value, max_value;
    int random_input;
};

//Class represents input with type of string.
class StringInput : public Input {
public:
    StringInput(int, int);
    ~StringInput();
    void gen_input();
    char* get_random_input();
private:
    int min_length, max_length;
    char* random_input;
};

//Class represents input with type of char.
class CharInput : public StringInput {
public:
    CharInput() : StringInput(1, 1) {};
};

//Class to generate random inputs.
class InputGen{
private:
    //Read the stdin.txt file.
    std::vector<InputType*>* read_stdin_file(std::string);
public:
    void gen_input(int num, std::string stdin_path, std::string dir_path);
};

#endif
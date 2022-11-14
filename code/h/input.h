#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

//The class represents the input type.
//When read stdin from stdin_format.txt the class will be instantiated to corresponding object.
class InputType{
    //Variable std::string type in this class represents the type of stdin it can be int char or string.
    std::string type;
    //These two variables min_val and max_val represents the min value and max value when type is int 
    //or the min length and max length when the type is string.
    int min_val, max_val;
public:
    InputType(std::string _type, int _min_val, int _max_val) : type(_type), min_val(_min_val), max_val(_max_val) {}
    //Returns the type represented by the object.
    std::string get_type() const {return type;}
    int get_min_val() const {return min_val;}
    int get_max_val() const {return max_val;}
};

//Base class of all possible input type.
class Input{
protected:
    int min_val, max_val;
public:
    //Generate a random input with corresponding type
    virtual void gen_input() = 0;
    virtual ~Input() {}
};

//Class represents input is integer.
class IntInput : public Input {
public:
    IntInput(int, int);
    //Generate a random int input
    void gen_input();
    //Get the generated random input
    int get_random_input();
private:
    int random_input;
};

//Class represents input is string.
class StringInput : public Input {
public:
    StringInput(int, int);
    ~StringInput();
    //Generate a random string input
    void gen_input();
    //Get the generated random input
    char* get_random_input();
private:
    char* random_input;
};

//Class represents input is char.
//Char type can be considered as string type whose min length and max length are both 1.
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
    //Generate random inputs
    //Parameter num represents the number of inputs, stdin_path represents the path of the file stdin_format.txt,
    //dir_path represents the path containing stdin_format.txt
    void gen_input(int num, std::string stdin_path, std::string dir_path);
};

#endif
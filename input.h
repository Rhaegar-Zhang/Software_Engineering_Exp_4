#include <vector>
#include <fstream>
#include <string>

//Base class of all possible inputs.
class Input{
public:
    virtual void gen_input() = 0;
};

//Class represents input with type of integer
class IntInput : public Input {
public:
    void gen_input();
private:
    int min_value, max_value;
};

//Class represents input with type of string.
class StringInput : public Input {
public:
    void gen_input();
private:
    int min_length, max_length;
};

//Class represents input with type of char.
class CharInput : public StringInput {
public:
    void gen_input();
};

//Class to generate random inputs.
class InputGen{
private:
    //Store the input generated randomly.
    std::vector<std::vector<Input*> > program_input;
    //Read the stdin.txt file.
    void read_stdin_file();
public:
    void gen_input(int num, std::string stdin_path);
};
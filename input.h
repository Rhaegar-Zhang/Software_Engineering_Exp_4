#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

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
    //Store the input generated randomly.
    std::vector<std::vector<Input*> > program_input;
    //Read the stdin.txt file.
    void read_stdin_file(std::string);
public:
    void gen_input(int num, std::string stdin_path);
};
/*
Cristian Stransky  
CS4500 - Software Dev
Spring 2020
 */

#include <iostream>
#include <string.h>
#include <fstream>

void p(char s) { std::cout << s ; }
void p(char* s) { std::cout << s ; }
void p(const char* s) { std::cout << s ; }
void p(size_t s) { std::cout << s ; }
void pln() { std::cout << '\n' ; }
void pln(char s) { std::cout << s << "\n" ; }
void pln(char* s) { std::cout << s << "\n" ; }
void pln(const char* s) { std::cout << s << "\n" ; }
void pln(size_t s) { std::cout << s << "\n" ; }
void pln(bool s) { std::cout << s << "\n" ; }


bool is_same_string(const char* string1, const char* string2) {
    return strcmp(string1, string2) == 0;
}

char* get_concat_string(char* base_string, char* added_string) {
    char* temp_string = new char[1 + strlen(base_string) + strlen(added_string)];
    strcpy(temp_string, base_string);
    strcat(temp_string, added_string);
    return temp_string;
}

char* get_concat_string(char* base_string, const char* added_string) {
    char* temp_string = new char[1 + strlen(base_string) + strlen(added_string)];
    strcpy(temp_string, base_string);
    strcat(temp_string, added_string);
    return temp_string;
}

// This method is mainly unused, but I wanted to make to make it to understand 
// how to properly make a void function
void concat(char*& base_string, char* added_string) {
    char* temp_string = new char[1 + strlen(base_string) + strlen(added_string)];
    strcpy(temp_string, base_string);
    strcat(temp_string, added_string);
    base_string = temp_string;
}

char* get_concat_printable_string(char* printable_string, char* added_string) {
    if (!is_same_string(printable_string, "")) {
        printable_string = get_concat_string(printable_string, " ");
    }
    return get_concat_string(printable_string, added_string);
}

void print_output_string(size_t print_length, char* output_string) {
    // I do this to avoid array out of bounds errors
    if (print_length < 0 || print_length > strlen(output_string)) { 
        print_length = strlen(output_string); 
    } 
    for(size_t ii = 0; ii < print_length; ii++) {
        p(output_string[ii]);
    }
    pln();
}

void print_file(size_t print_length, char* file_name) {
    // TODO: Come back and correctly allocate this array based on the size of the file
    // For now, this is fine, especially since I actually shouldn't have done this much lol
    char* file_line_string = new char[100];
    char* file_output_string = (char*)"";
    std::ifstream in_file;

    in_file.open(file_name);
    if (in_file.is_open()) {
        while(!in_file.eof()) {
            in_file >> file_line_string;
            file_output_string = get_concat_string(file_output_string, file_line_string);
        }
        in_file.close();

        print_output_string(print_length, file_output_string);
    }
    else {
        pln("~ERROR: FILE NOT FOUND~");
    }
}

void print(size_t ms, char* s, char* c) {
    // Sorry, but I really need these or I'm going to go crazy
    size_t print_length = ms;
    char* file_name = s;
    char* printable_string = c;

    pln("=====================================");
    if (print_length < SIZE_MAX) { std::cout << "print_length: " << print_length << '\n'; }
    if (file_name) { std::cout << "file_name: \"" << file_name << "\"\n"; }
    std::cout << "printable_string: \"" << printable_string << "\"\n";
    pln("=====================================");

    // TODO: Use the code below for when we want to actually print out the arguments
    // NOTE: Warmup 1 does NOT execute the command, it simply prints the arguments of it
    // if (file_name) {
    //     std::cout << "Printing output from file \"" << file_name << "\":\n";
    //     print_file(print_length, file_name);
    // }
    // if (!is_same_string(printable_string, "")) {
    //     pln("Printing output:");
    //     print_output_string(print_length, printable_string);
    // }
}

bool is_valid_flag(const char* flag, int argh, char** argv, size_t ii, char* flag_string) {
    return !flag_string && is_same_string(argv[ii], flag) && ii + 1 < argh;
}

bool is_valid_flag(const char* flag, int argh, char** argv, size_t ii, size_t flag_size_t) {
    return flag_size_t == SIZE_MAX && is_same_string(argv[ii], flag) && ii + 1 < argh;
}

size_t get_print_length(const char* next_arg) {
    // A negative number will make print_length a ridiculous number, so I just make it 0 instead.
    // Example: "-i -1" --> print_length = 18446744073709551615
    char first_letter_of_next_arg = next_arg[0];
    if (first_letter_of_next_arg == '-') {
        next_arg = "0";
    }
    return atoi(next_arg);
}

int main(int argh, char** argv) {
    // Since this assignment really wants size_t instead of int, I'm stuck assuming an unassigned
    // size_t is at max size. Normally, I'd set this to -1.
    size_t print_length = SIZE_MAX; 
    char* file_name = nullptr;
    char* printable_string = const_cast<char*>(""); // (char*)""
    // I want to ignore first argument ("./a.out") as it's the command itself, so I start at 1
    for (size_t ii = 1; ii < argh; ii++) {
        // The argument right next to a flag is considered its value, so it's skipped with ii++
        // This means that "-i -f" and "-f -i" will be considered valid, but give strange output
        // NOTE: Will only use the first instance of a flag. "-i 5 -i 6" will make print_length = 5.
        if (is_valid_flag("-i", argh, argv, ii, print_length)) {
            print_length = get_print_length(argv[ii + 1]);
            ii++;
        }
        else if (is_valid_flag("-f", argh, argv, ii, file_name)) {
            file_name = argv[ii + 1];
            ii++;
        } 
        else {
            char* temp_string = get_concat_printable_string(printable_string, argv[ii]);
            delete printable_string;
            printable_string = temp_string;
        }
    }
    print(print_length, file_name, printable_string);
}
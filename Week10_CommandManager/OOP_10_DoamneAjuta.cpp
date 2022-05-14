#define _CRT_SECURE_NO_WARNINGS
// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <functional>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <conio.h>


using std::function;
using std::map;
using std::string;
using std::vector;
using std::ofstream;

bool is_vowel(char x)
{
    return(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U');
}

class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/rzaharia/0e155df56a3a81d5383f00d838c97a99
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    string tmp;
    vector<string> args;

    while (true) {
        printf("Enter command: ");
        std::getline(std::cin, tmp);
        if (tmp == "stop") {
            return;
        }

        args.clear();
        auto ptr = strtok(&tmp[0], " ");
        while (ptr) {
            args.push_back(ptr);
            ptr = strtok(nullptr, " ");
        }

        if (args.empty()) {
            // empty command, doing nothing
            continue;
        }

        auto it = commands.find(args[0]);
        if (it == commands.end()) {
            printf("no command with that name!\n");
            continue;
        }

        // remove the command name
        args.erase(args.begin());

        it->second(args);
    }
}

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;
    unsigned number_of_calls = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    // auto count = ...;
    // manager.add("count", count);
    auto count = [](vector<string> args) { printf("counted %d args\n", args.size()); };
    manager.add("count", count);


    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    // auto append = ...;
    // manager.add("append", append);
    auto append = [&number_of_errors](vector<string>args) {
        if (args.size() == 0)
        {
            number_of_errors++;
            return;
        }
        string filename = args[0];
        std::fstream file_out;
        file_out.open(filename, std::ios_base::app | std::ios_base::in);
        if (!file_out.is_open())
        {
            number_of_errors++;
            return;
        }
        for (int it = 1; it < args.size(); it++)
        {
            file_out << args[it] << " ";
        }

    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    // auto times = ...;
    // manager.add("times", times);
    auto times = [counter = number_of_calls](vector<string>args)mutable {
        counter++;
        printf("called %d times\n", counter);
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    // auto copy = ...;
    // manager.add("copy", copy);
    auto copy = [&number_of_errors](vector<string>args) {
        if (args.size() < 2)
        {
            number_of_errors++;
            return;
        }
        /*string in_file = args[0];
        string out_file = args[1];
        std::ifstream in(in_file, std::ios::binary);
        std::ofstream myOutput;
        char buffer[1024];
        myOutput.open(out_file, std::ios::binary);
        while (in.read(buffer, sizeof(buffer)))
        {
            myOutput.write(buffer, in.gcount());
        }
        myOutput.write(buffer, in.gcount());
        myOutput.close();
        in.close();*/

        // -------------------------------------------

        /*const char* in_file = args[0].c_str();
        const char* out_file = args[1].c_str();
        int* buf = nullptr;
        FILE* pr, * pw;
        pr = fopen(in_file, "rb");
        pw = fopen(out_file, "wb");
        while (!feof(pr))
        {
            fread(buf, 1, 1, pr);
            fwrite(buf, 1, 1, pw);
        }
        fclose(pr);
        fclose(pw);*/
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    // auto sort_size = ...;
    // manager.add("sort_size", sort_size);
    auto sort_size = [](vector<string>args) {
        std::sort(args.begin(), args.end(), [](const string& str1, const string& str2) {return str1.size() < str2.size(); });
        std::for_each(args.begin(), args.end(), [](const string& str)->void {std::cout << str << " "; });
        printf("\n");
    };
    manager.add("sort_size", sort_size);

    // add one more command of anything you'd like:
    // Multiple strings as arguments
    // Prints the number of vowels found in the strings

    auto count_vowels = [](vector<string>args) {
        int nbVowels = NULL;
        for (auto it : args)
        {
            nbVowels += std::count_if(it.begin(), it.end(), is_vowel);
        }
        printf("Found %d vowels.\n", nbVowels);
    };
    manager.add("count_vowels", count_vowels);

    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
}
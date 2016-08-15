#include <string>
#include "options.h"
#include "patterns.h"

int main(int argc, char** argv){
    Options options(argc, argv);

    Patterns<std::string> p;
    std::cin >> p;
    p.find_patterns(options.min, options.max);
    std::cout << p;
}

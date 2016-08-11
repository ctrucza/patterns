#include <string>
#include "options.h"
#include "predictor.h"

int main(int argc, char** argv){
    Options options(argc, argv);

    Predictor<std::string> p;
    p.read(std::cin);

    p.find_patterns(options.min, options.max);

    p.dump_patterns();
}

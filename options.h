#include <iostream>

class Options{
public:
    size_t min = 2;
    size_t max = 5;
    Options(int argc, char** argv){
        for(int i = 1; i < argc; ++i){
            if (argv[i][0] == '-'){
                if (argv[i][1] == 'm'){
                    min = (size_t)atoi(argv[++i]);
                }
                else if (argv[i][1] == 'M'){
                    max = (size_t)atoi(argv[++i]);
                }
            }
        }

        std::cerr << "options:" << std::endl;
        std::cerr << "min pattern length: " << min << std::endl;
        std::cerr << "max pattern length: " << max << std::endl;
    }
};
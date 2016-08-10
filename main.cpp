#include "predictor.h"
int main(){
    Predictor<int> p;
    p.add(42);
    p.add(43);
    p.add(42);
    p.add(43);

    p.find_patterns();

    p.dump_patterns();
}

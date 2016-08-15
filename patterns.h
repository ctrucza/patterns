#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <istream>
#include <ostream>

template <typename T>
class Patterns {
private:
    typedef std::vector<T> Sequence;
    Sequence history;
    std::map< Sequence, int> patterns;

    void add(T signal){
        history.push_back(signal);
        std::cerr << "added " << signal << " (" << history.size() << ")" << std::endl;
    }

    void find_patterns_of_length(size_t length){
        auto begin = history.begin();
        auto last_begin = history.end()-(long)(length)+1;
        while (begin != last_begin){
            auto end = begin + long(length);
            patterns[Sequence(begin, end)]++;
            begin++;
        }
    }

    std::ostream& write(std::ostream& os) const{
        for(auto i = patterns.begin(); i != patterns.end(); ++i){
            os << i->second << "\t" << i->first.size() << "\t";
            std::copy(i->first.begin(), i->first.end(), std::ostream_iterator<T>(os, " ")); 
            os << std::endl;
        }
        return os;
    }

    template <typename U> 
    friend std::ostream& operator<<(std::ostream& os, const Patterns<U>& p);
public:
    void read(std::istream& s){
        T n;
        while(s >> n){
            add(n);
        }
    }

    void find_patterns(size_t min, size_t max){
        for(size_t length = min; length <= max; length++){
            std::cerr << "finding patterns of length " << length << std::endl;
            find_patterns_of_length(length);
            std::cerr << "total patterns so far: " << patterns.size() << std::endl;
        }
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Patterns<T>& p){
    return p.write(os);
}
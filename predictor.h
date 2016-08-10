
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

template <typename T>
class Predictor {
private:
    std::vector<T> history;
    std::map< std::vector<T>, int> patterns;

    void check(size_t start, size_t matching_start, size_t length){
        for(size_t i = 0; i < length; ++i){
            if (history[start+i] != history[matching_start+i])
                return;
        }

        auto pattern = std::vector<T>(history.begin()+(long)start, history.begin()+long(start+length));
        patterns[pattern]++;
    }

    void find_matches_of(size_t start, size_t length){
        for(size_t matching_start = start+length; matching_start < history.size(); matching_start++ )
        {
            patterns[std::vector<T>(history.begin()+(long)matching_start, history.begin()+(long)(matching_start+length))]++;
        }
    }

    void find_patterns_of_length(size_t length){
        for(size_t start = 0; start < history.size()-length+1; ++start){
            patterns[std::vector<T>(history.begin()+(long)start, history.begin()+(long)(start+length))]++;
        }
    }

    void dump_pattern(const std::vector<T>& pattern){
        std::copy(pattern.begin(), pattern.end(), std::ostream_iterator<T>(std::cout, " ")); 
    }
public:
    void add(T signal){
        history.push_back(signal);
        std::cerr << "added " << signal << " (" << history.size() << ")" << std::endl;
    }

    void find_patterns(){
        for(size_t length = 2; length < history.size(); length++){
            std::cerr << "finding patterns of length " << length << std::endl;
            find_patterns_of_length(length);
            std::cerr << "total patterns so far: " << patterns.size() << std::endl;
        }
    }

    void dump_patterns(){
        for(auto i = patterns.begin(); i != patterns.end(); ++i){
            std::cout << i->second << "\t" << i->first.size() << "\t";
            dump_pattern(i->first);
            std::cout << std::endl;
        }
    }
};

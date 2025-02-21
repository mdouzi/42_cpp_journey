#include "PmergeMe.hpp"
#include <ctime> 

void printVector(const vecVec& sequence) {
    for (vecVec::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        for (std::vector<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            std::cout << *it2 << ", ";
        }
    }
}

void printDeque(const deqDeque& sequence) {
    for (deqDeque::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
        for (std::deque<int>::const_iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            std::cout << *it2 << ", ";
        }
    }
}


int main(int argc , char **argv) {
    if(argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [number1] [number2] ... [numberN]" << std::endl;
        return 1;
    }

    try {

        deqDeque one;
        deqDeque beforeOne;
        vecVec two;

        one = getDigitsDeq(argc, argv);
        two = getDigits(argv, argc);

        std::cout << "Before (vector) : ";
        printVector(two);
        std::cout<<std::endl;
        clock_t begin_time_two = clock();
        two = mergeInsertion(two);
        clock_t end_time_two = clock();
        std::cout << "After: ";
        printVector(two);
        std::cout<<std::endl;
        std::cout<<std::endl;
        std::cout << "Before (deque) : ";
        printDeque(one);
        std::cout<<std::endl;
         clock_t begin_time_one = clock();
        one = mergeInsertionDeq(one);
        clock_t end_time_one = clock();
        std::cout << "After: ";
        printDeque(one);
        std::cout<<std::endl;
        std::cout<<std::endl;

        std::cout << "Time to process a range of " << argc - 1<< " elements with std::vector :" << (float)(end_time_one - begin_time_one) * 1000000 / CLOCKS_PER_SEC << "us " <<std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  :" << (float)(end_time_two - begin_time_two) * 1000000 / CLOCKS_PER_SEC << "us " <<std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

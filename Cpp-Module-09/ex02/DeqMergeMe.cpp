#include "PmergeMe.hpp"


void pairDeque(deqDeque& digits, deqDeque& rest) 
{
    deqDeque tmp;
    for (deqDeque::iterator it = digits.begin(); it != digits.end(); it += 2) 
    {
        if (it + 1 != digits.end()) 
        { 
            if ((*it) > *(it + 1)) { 
                std::deque<int> tmpVec = *it;
                *it = *(it + 1);
                *(it + 1) = tmpVec;
            }
            std::deque<int> oneDeque;
            for (std::deque<int>::iterator one = it->begin(); one != it->end(); one++) {
                oneDeque.push_back(*one);
            }
            for (std::deque<int>::iterator two = (it + 1)->begin(); two != (it + 1)->end(); two++) {
                oneDeque.push_back(*two);
            }
            tmp.push_back(oneDeque);
            oneDeque.clear();
        } else { // If there's no next vector, just push the current one
            rest.push_back(*it);
        }
    } 
    digits = tmp;
    tmp.clear();
}

void unpairDeque(deqDeque& digits)
{
    deqDeque newOne;
    size_t size = digits[0].size() / 2;

    for (size_t i = 0; i < digits.size(); ++i)
    {
        std::deque<int> deq1, deq2;

        for (size_t j = 0; j < size; ++j)
        {
            deq1.push_back(digits[i][j]);
            deq2.push_back(digits[i][j + size]);
        }

        newOne.push_back(deq1);
        newOne.push_back(deq2);
    }

    digits = newOne;
    newOne.clear();
}


void createChainsDeq(deqDeque &digits, deqDeque &main, deqDeque &pend, deqDeque &remain)
{
    int index = 0;
    deqDeque::iterator it = digits.begin();
    while (it != digits.end())
    {
        if (index % 2 != 0)
            main.push_back(*it);
        else
            pend.push_back(*it);
        index++;
        it++;
    }
    deqDeque::iterator it2 = remain.begin();
    while(it2 != remain.end())
    {
        pend.push_back(*it2);
        it2++;
    }
}

deqDeque getDigitsDeq(int argc, char **argv)
{
    deqDeque digits;
   if(argc > 1)
   {
    std::deque<int> tmp;
    int i = 1;
    while(argv[i])
    {
        std::deque<int> tmp;
        char *endPtr;
        long num = std::strtol(argv[i], &endPtr, 10);
        if(*endPtr != '\0' || num < INT_MIN || num > INT_MAX)
            throw std::invalid_argument("Invalid argument => " + std::string(argv[i]));
        tmp.push_back(std::atoi(argv[i]));
        digits.push_back(tmp);
        tmp.clear();
        i++;
    }
   }
   return digits;
}

bool CompareDeq(const std::deque<int>& d1, const std::deque<int>& d2)
{
    return (d1.back() <= d2.back());
}

// Function to insert deques from Paind into main deque in sorted order
void insertPaindInMainDeq(deqDeque& main, deqDeque& Paind)
{
    for (deqDeque::const_iterator it = Paind.begin(); it != Paind.end(); ++it)
    {
        deqDeque::iterator pos = std::lower_bound(main.begin(), main.end(), *it, CompareDeq);
        main.insert(pos, *it);
    }
}

deqDeque mergeInsertionDeq(deqDeque &digits)
{
    deqDeque pend, main, remain;
    if(digits.size() == 1)
    {
        return digits;
    }
    if(digits.size() % 2 != 0)
    {
        remain.push_back(digits.back());
        digits.pop_back();
    }
    pairDeque(digits, remain);
    mergeInsertionDeq(digits);
    unpairDeque(digits);
    createChainsDeq(digits, main, pend, remain);
    insertPaindInMainDeq(main, pend);
    digits = main;
    main.clear();
    return digits;
}



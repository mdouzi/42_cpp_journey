#include "PmergeMe.hpp"

void pairVector(vecVec &digits, vecVec &rest) {
    vecVec tmp;
    for (vecVec::iterator it = digits.begin(); it != digits.end(); it += 2) 
    {
        if (it + 1 != digits.end()) 
        { 
            if ((*it) > *(it + 1)) {
                std::vector<int> tmpVec = *it;
                *it = *(it + 1);
                *(it + 1) = tmpVec;
            }
            std::vector<int> oneVec;
            for (std::vector<int>::iterator one = it->begin(); one != it->end(); one++) {
                oneVec.push_back(*one);
            }
            for (std::vector<int>::iterator two = (it + 1)->begin(); two != (it + 1)->end(); two++) {
                oneVec.push_back(*two);
            }
            tmp.push_back(oneVec);
            oneVec.clear();
        } else { // If there's no next vector, just push the current one
            rest.push_back(*it);
        }
    } 
    digits = tmp;
    tmp.clear();
}

void unpairVector(vecVec& digits)
{
    vecVec newOne;
    size_t size = digits[0].size() / 2;

    for (size_t i = 0; i < digits.size(); ++i)
    {
        std::vector<int> vec1, vec2;

        for (size_t j = 0; j < size; ++j)
        {
            vec1.push_back(digits[i][j]);
            vec2.push_back(digits[i][j + size]);
        }

        newOne.push_back(vec1);
        newOne.push_back(vec2);
    }

    digits = newOne;
    newOne.clear();
}

    
void createChains(vecVec &digits, vecVec &main, vecVec &pend, vecVec &remain)
{
    int index = 0;
    vecVec::iterator it = digits.begin();
    while (it != digits.end())
    {
        if (index % 2 != 0)
            main.push_back(*it);
        else
            pend.push_back(*it);
        index++;
        it++;
    }
    
    vecVec::iterator re = remain.begin();
    while(re != remain.end())
    {
        pend.push_back(*re);
        re++;
    }
}

vecVec getDigits(char **argv, int argc)
{
    vecVec digits;
    for(int i = 1; i < argc; i++)
    {
        std::vector<int> vec_int;
        char *endPtr;
        long num = std::strtol(argv[i], &endPtr, 10);
        if(*endPtr != '\0' || num < INT_MIN || num > INT_MAX)
            throw std::invalid_argument("Invalid argument => " + std::string(argv[i]));
        vec_int.push_back(static_cast<int>(num));
        digits.push_back(vec_int);
        vec_int.clear();
    }
    return digits;
}

bool Compare(const std::vector<int> &a, const std::vector<int> &b)
{
    return a.back() <= b.back();
}

void InsertPaindInMain(vecVec &main, vecVec &Paind)
{

    for (vecVec::const_iterator it = Paind.begin(); it != Paind.end(); ++it)
    {
        // Find the insertion point using lower_bound
        vecVec::iterator insertionPoint = std::lower_bound(main.begin(), main.end(), *it, Compare);

        // Insert the vector at the insertion point
        main.insert(insertionPoint, *it);
    }
}


vecVec mergeInsertion(vecVec &digits)
{
    vecVec pend;
    vecVec mainChain;
    vecVec remain;

    if (digits.size() == 1)
        return digits; 
    if (digits.size() % 2 != 0)
    {
        remain.push_back(digits.back());
        digits.pop_back();
    }
    pairVector(digits, remain); 
    mergeInsertion(digits);
    unpairVector(digits);
    createChains(digits, mainChain, pend, remain);
    InsertPaindInMain(mainChain, pend);
    digits = mainChain;
    mainChain.clear();
    return digits;
}



#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <climits>
#include <deque>
#include <algorithm>

typedef std::vector<std::vector<int> > vecVec;
typedef std::deque<std::deque<int> > deqDeque;


// deque 
void pairDeque(deqDeque& digits, deqDeque& rest);
void unpairDeque(deqDeque& digits);
void createChainsDeq(deqDeque &digits, deqDeque &main, deqDeque &pend, deqDeque &remain);
deqDeque getDigitsDeq(int argc, char **argv);
void insertPaindInMainDeq(deqDeque &main, deqDeque &Paind);
deqDeque mergeInsertionDeq(deqDeque &digits);


// vector 
void pairVector(vecVec &digits, vecVec &rest);
void unpairVector(vecVec& digits);
void createChains(vecVec &digits, vecVec &main, vecVec &pend, vecVec &remain);
vecVec getDigits(char **argv, int argc);
void InsertPaindInMain(vecVec &main, vecVec &Paind);
vecVec mergeInsertion(vecVec &digits);


#endif
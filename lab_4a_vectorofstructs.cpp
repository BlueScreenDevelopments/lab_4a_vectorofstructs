#include<iostream>
#include<iomanip>
#include <vector>
#include <random>

using namespace std;

/*
Brandon Julao
COMSC-210-5470
09.07.25
Vector of Structs.
*/

//Define Structs.
struct Color {
    int r{};
    int g{};
    int b{};
};

//Generate random integer
int randoomInRange (mt19937& rng, int lo, int hi){
    uniform_int_distribution<int> dist(lo, hi);
    return dist(rng);
}

//Generate random color

Color randomColor(mt19937& rng)
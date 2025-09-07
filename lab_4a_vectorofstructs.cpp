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
int randomInRange (mt19937& rng, int lo, int hi){
    uniform_int_distribution<int> dist(lo, hi);
    return dist(rng);
}

//Generate random color
Color randomColor(mt19937& rng){
    uniform_int_distribution<int> byte(0,255);
    return Color{ byte(rng), byte(rng), byte(rng)};
}

int main(){
    random_device rd;
    mt19937 rng(rd());


    //Empty Vector
    vector<Color> colors;

    //Generate random number between 25/50
    int n = randomInRange(rng, 25, 50);
    colors.reserve(n);


    //Fill the table with Random Colors
    for (int i = 0; i < n; ++i){
        colors.push_back(randomColor(rng));
    }

    //Formatted Table
    const int wIndex = 5;
    const int wCOl = 6;


    

}
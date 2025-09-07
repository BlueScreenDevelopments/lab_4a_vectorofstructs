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
    Color c;
    c.r = byte(rng);
    c.g = byte(rng);
    c.b = byte(rng);
    return c;    
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
    const int wCol = 6;

   cout << left
         << setw(wIndex) << "Color #"   // index column
         << right
         << setw(wCol) << "R Value"
         << setw(wCol) << "G Value"
         << setw(wCol) << "B Value"
         << "\n";

    // Print separator line
    cout << setfill('-')
         << setw(wIndex + 3 * wCol) << ""
         << setfill(' ') << "\n";

    // Print each row
    for (size_t i = 0; i < colors.size(); ++i) {
        const auto& c = colors[i];
        cout << left  << setw(wIndex) << i
             << right << setw(wCol)   << c.r
             << setw(wCol)            << c.g
             << setw(wCol)            << c.b
             << "\n";
    }

    return 0;
}
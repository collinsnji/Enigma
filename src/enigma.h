#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <cstdlib>
#include <map>
#include <array>
#include <stdexcept>
#include <random>
#include <vector>

class Enigma {
    private:
    // Plugboard
        const std::map<char, char> PlugBoard {
            {'A', 'Z'}, {'B', 'P'},
            {'C', 'H'}, {'D', 'N'},
            {'E', 'M'}, {'F', 'S'},
            {'G', 'W'}, {'H', 'C'},
            {'I', 'I'}, {'J', 'Y'},
            {'K', 'T'}, {'L', 'Q'},
            {'M', 'E'}, {'N', 'D'},
            {'O', 'O'}, {'P', 'B'},
            {'Q', 'L'}, {'R', 'R'},
            {'S', 'F'}, {'T', 'K'},
            {'U', 'X'}, {'V', 'V'},
            {'W', 'G'}, {'X', 'U'},
            {'Y', 'J'}, {'Z', 'A'}
        };
  public:
    int index;
    char Signal(char letter);
    char Rotor(char input_signal);
    std::map<char, char> Wheel();
};

char Enigma::Signal(char letter){
    if(Enigma::PlugBoard.find(letter) == Enigma::PlugBoard.end()){
        throw std::invalid_argument("Signal passed is invalid");
    }
    return Enigma::PlugBoard.at(letter);
}

std::map<char, char> Enigma::Wheel() {
    int key = 65;
    std::map <char, char> wheel_map;
    std::vector<int> random_index;
    std::random_device random_d;
    std::mt19937 eng(random_d());
    std::uniform_int_distribution<> dist(0, 25);

    while(random_index.size() < 26){
        int unique_rand_n = dist(eng);
        bool push = true;
        for(auto &i: random_index){
            if(unique_rand_n == i){
                unique_rand_n = dist(eng);
                push = false;
            }
        }
        if(push) random_index.push_back(unique_rand_n);
    }
    for(auto &i: random_index){
        char val = static_cast<char>(i+65);
        wheel_map.emplace(static_cast<char>(key), val);
        key++;
    }
    random_index.clear(); random_index.shrink_to_fit(); 
    return wheel_map;
}

char Enigma::Rotor(char input_signal){
    return Enigma::Wheel().at(input_signal);
}

#endif // ENIGMA_H

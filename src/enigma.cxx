#include "enigma.h"
#include <iostream>

int main(void){
    Enigma *EnigmaMachine = new Enigma();
    
    char right = EnigmaMachine->Rotor(EnigmaMachine->Signal('A'));
    char middle = EnigmaMachine->Rotor(right);
    char left = EnigmaMachine->Rotor(middle);

    std::cout <<"Input Signal: A -> Emits: " << EnigmaMachine->Signal('A') << std::endl <<
                "Right: " << right << std::endl <<
                "Middle: " << middle << std::endl << 
                "Left: " << left << std::endl;
    return EXIT_SUCCESS;
}
#include "transponder.hpp"
#include "amplifier.hpp"
#include <iostream>
#include <memory>

int main (){
    std::vector<std::unique_ptr<ncu::Card>> cards;
    cards.push_back(std::make_unique<ncu::Transponder>(1));
    cards.push_back(std::make_unique<ncu::Amplifier>(2, 20.0));
    
    for (const auto& card : cards){
        std::cout<<card->getDescription()<<"\n";
    }
    return 0;
}
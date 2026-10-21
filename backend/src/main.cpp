#include "transponder.hpp"
#include "amplifier.hpp"
#include <iostream>
#include <memory>
#include "shelf.hpp"

int main (){
    ncu::Shelf shelf;
    shelf.insert(1, std::make_unique<ncu::Transponder>(1));
    shelf.insert(2, std::make_unique<ncu::Amplifier>(2));
    shelf.insert(2, std::make_unique<ncu::Transponder>(2));
    std::cout<<shelf.getCardBySlot(1)->getDescription()<<"\n";
    std::cout<<shelf.getCardBySlot(2)->getDescription()<<"\n";
    return 0;
}
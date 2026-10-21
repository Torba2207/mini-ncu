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
    for(std::size_t i=1; i<=shelf.kSlots;i++){
        if(const ncu::Card* card = std::as_const(shelf).getCardBySlot(i)){
            std::cout<< card->getDescription()<<"\n";
        }
        else{
            std::cout<<"Slot "+std::to_string(i)+" is empty"<<"\n";
        }
        
    }
    return 0;
}
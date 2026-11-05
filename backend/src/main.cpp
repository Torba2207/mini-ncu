#include "transponder.hpp"
#include "amplifier.hpp"
#include <memory>
#include "shelf.hpp"



int main (){
    ncu::Shelf shelf;
    shelf.insert(1, std::make_unique<ncu::Transponder>(1));
    shelf.insert(2, std::make_unique<ncu::Amplifier>(2));
    shelf.insert(3, std::make_unique<ncu::Transponder>(3));
    shelf.printShelf();
    std::unique_ptr<ncu::Card> amplifier = shelf.remove(2);
    shelf.insert(4,std::move(amplifier));
    shelf.printShelf();
    return 0;
}
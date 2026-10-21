#include "port.hpp"
#include "card.hpp"
#include "transponder.hpp"
#include <cstdio>

int main (){
    ncu::Transponder transponder(1);
    printf("%s\n", transponder.getDescription().c_str());
    return 0;
}
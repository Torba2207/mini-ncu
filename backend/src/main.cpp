#include "port.hpp"
#include "card.hpp"
int main (){
    ncu::Port port1{.name="1-1-C1", .adminState=ncu::AdminState::Up, .rxPowerDbm=-3.5};
    return 0;
}
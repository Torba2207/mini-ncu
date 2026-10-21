#pragma once
#include "card.hpp"
#include <format>
namespace ncu{
    class Transponder: public Card {
        
        public:
            explicit Transponder(std::size_t slotId)
            :Card(slotId, {Port{.name="1-"+std::to_string(slotId)+"-C1"}, 
            Port{.name="1-"+std::to_string(slotId)+"-N1"}}) {}
            std::string_view getType() const override {
                return "transponder";
            }
            std::string getDescription() const override {
                return "Transponder card in slot " 
                + std::to_string(getSlotId())
                +" with " + std::to_string(getPorts().size()) 
                + " ports. Temperature: " + std::format("{:.1f}",getTemperature()) + "°C";
            }
    };
}
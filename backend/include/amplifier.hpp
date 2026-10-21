#pragma once
#include "card.hpp"
#include <format>
namespace ncu{
    class Amplifier: public Card{
        private:
            double gainDb_;
        public:
            
            explicit Amplifier(std::size_t slotId, double gain=20.0)
            : Card(slotId, {Port{.name="1-"+std::to_string(slotId)+"-L1"}}), 
            gainDb_(gain){}


            double getGainDb() const{return gainDb_;}

            std::string_view getType() const override{return "amplifier";}
            std::string getDescription() const override{
                return "Amplifier card in slot " 
                + std::to_string(getSlotId())
                +" with " + std::to_string(getPorts().size()) 
                + " ports. Temperature: " + std::format("{:.1f}",getTemperature()) + "°C"
                + " and amplification " + std::format("{:.1f}",getGainDb()) +" dB";
            }

    };
}
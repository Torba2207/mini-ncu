#pragma once
#include <utility>
#include <cstddef>
#include <string>
#include <string_view>
#include <span>
#include <vector>
#include "port.hpp"
namespace ncu{
    class Card{
    private:
        std::size_t slotId_;
        double temperature_;
        std::vector<Port> ports_;
    protected:
        Card(std::size_t slotId, std::vector<Port> ports):slotId_(slotId), temperature_(25.0),ports_(std::move(ports)){}
    public:
        virtual std::string_view getType() const=0;
        virtual std::string getDescription() const=0;
        virtual ~Card()=default;
        std::span<const Port> getPorts() const {
            return ports_;
        } 
        std::span<Port> getPorts() {
            return ports_;
        } 
        std::size_t getSlotId() const {
            return slotId_;
        }
        double getTemperature() const {
            return temperature_;
        }     
    };
}
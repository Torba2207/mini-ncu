#pragma once
#include "card.hpp"
#include <array>
#include <memory>
#include <algorithm>
#include <iostream>
namespace ncu{
    enum class [[nodiscard]] ShelfActionResult {
        Ok, InvalidSlot, NullCard, SlotOccupied
    };
    class Shelf{
        public:
            static constexpr std::size_t kSlots = 8; 
            std::size_t getAvailableSlots() const{
                return static_cast<std::size_t>(std::ranges::count(cards_, nullptr));
            }

            ShelfActionResult insert(std::size_t slot, std::unique_ptr<Card> card){
                if(slot<1 || slot>kSlots) return ShelfActionResult::InvalidSlot;
                if(!card)return ShelfActionResult::NullCard;
                if(cards_[slot-1]) return ShelfActionResult::SlotOccupied;
                cards_[slot-1] = std::move(card);
                cards_[slot-1]->setSlotId(slot);
                return ShelfActionResult::Ok;
            }
            std::unique_ptr<Card> remove(std::size_t slot){
                if(slot<1||slot>kSlots) return nullptr;
                return std::move(cards_[slot-1]);
            }

            Card* getCardBySlot(std::size_t slot) {
                if(slot<1||slot>kSlots) return nullptr;
                return cards_[slot-1].get();
            }

            const Card* getCardBySlot(std::size_t slot) const {
                if(slot<1||slot>kSlots) return nullptr;
                return cards_[slot-1].get();
            }
            Port* getPortByName(std::string_view name){
                for (const auto& card : cards_){
                    if(!card) continue;
                    for(auto& port : card->getPorts()){
                        if(port.name==name) return &port;
                    }
                }
                return nullptr;
            }
            const Port* getPortByName(std::string_view name) const{
                for (const auto& card : cards_){
                    if(!card) continue;
                    for(const auto& port : card->getPorts()){
                        if(port.name==name) return &port;
                    }
                }
                return nullptr;
            }

            void printShelf() const{
                for(std::size_t i=1; i<=kSlots;i++){
                    if(const ncu::Card* card = getCardBySlot(i)){
                        std::cout<< card->getDescription()<<"\n";
                    }
                    else{
                        std::cout<<"Slot "+std::to_string(i)+" is empty"<<"\n";
                    }
                    
                }
            }

            
        private:
            std::array<std::unique_ptr<Card>,kSlots> cards_;
        

            
    };
}
#pragma once
#include <string>

namespace ncu{

    enum class AdminState {
        Up,
        Down
    };


    struct Port{
        std::string name;
        AdminState adminState = AdminState::Down;
        double rxPowerDbm = 0.0;
        
    };

} // namespace ncu
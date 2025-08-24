#pragma once

    enum class SoundID { DAMAGE, SALTAR, DEAD };
struct Soundevent
{
public:
    SoundID id;
    
    bool operator==(const Soundevent& other) const {
        return id == other.id;
    }
};

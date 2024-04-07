#include "PlasticCup.hpp"
#include "Plastic.hpp"
#include "Cup.hpp"
#include "Usable.hpp"
#include <iostream>

using namespace std;

bool PlasticCup::is_usable()
{
    return Plastic::is_usable() && current_microplastics < maximum_microplastics;
}

void PlasticCup::fill(int volume, enum WaterType type)
{
    if (!is_usable())
    {
        return;
    }

    Cup::fill(volume, type);

    use();

    int urai = shred_microplastics(get_water_volume(), capacity);

    current_microplastics += urai;
}

void PlasticCup::drink(int volume)
{
    if (!is_usable())
    {
        return;
    }

    Cup::drink(volume);

    use();

    if (current_microplastics - volume <= 0)
    {
        current_microplastics = 0;
    }
    else
    {
        current_microplastics -= volume;
    }
}

void PlasticCup::drop(int height)
{
    int urai = shred_microplastics(get_water_volume() * height, capacity);

    current_microplastics += urai;
}
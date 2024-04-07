#include <iostream>
#include "GlassCup.hpp"

using namespace std;

bool GlassCup::is_usable()
{
    return Glass::is_usable();
}

void GlassCup::fill(int volume, enum WaterType type)
{
    if (!is_usable())
    {
        return;
    }

    Cup::fill(volume, type);
}

void GlassCup::drink(int volume)
{
    if (!is_usable())
    {
        return;
    }

    Cup::drink(volume);
}

void GlassCup::drop(int height)
{
    int force;
    int currVolume = get_water_volume();
    if (currVolume == 0)
    {
        force = height;
    }
    else
    {
        force = height * currVolume;
    }

    Glass::apply_force(force);
}

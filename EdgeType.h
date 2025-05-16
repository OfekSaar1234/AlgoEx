#pragma once
#include <iostream>

enum class EdgeType
{
    Green,      // Fill small jug
    Red,        // Fill large jug
    Orange,     // Empty large jug
    LightBlue,  // Empty small jug
    Blue,       // Transfer from small jug to large jug
    Purple      // Transfer from large jug to small jug
};
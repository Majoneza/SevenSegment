#include <SevenSegment.hpp>

namespace SevSeg
{
    // use namespace within a namespace to avoid name collisions
    using namespace SevenSegment;

    // Frame definitions
    constexpr auto topFrame = Top | TopRight;
    constexpr auto bottomFrame = Bottom | BottomLeft;
    constexpr auto zeroFrame = None; // or 0

    // Create animation: topFrame -> 100 ms delay -> bottomFrame -> 200 ms delay -> zeroFrame
    constexpr Animation<topFrame, 100, bottomFrame, 200, zeroFrame> sampleAnimation;

    // Create animation: topFrame -> 100 ms delay -> bottomFrame -> 200 ms delay -> zeroFrame
    //                   -> 300 ms delay ->
    //                   topFrame -> 100 ms delay -> bottomFrame -> 200 ms delay -> zeroFrame
    constexpr auto loopedAnimation = loopAnimation<1, 300>(sampleAnimation);
}

// Initialize display by specifying pins
using MyDisplay = SevSeg::Display<2, 3, 4, 5, 6, 7, 8, 9>;

void setup()
{
    // Display animation variable
    MyDisplay::displayAnimation(SevSeg::sampleAnimation);

    // ...

    // Display animation variable
    MyDisplay::displayAnimation(SevSeg::loopedAnimation);    
}

void loop()
{
}

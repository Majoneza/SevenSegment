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
    constexpr AnimationLoop_t<1, 300, topFrame, 100, bottomFrame, 200, zeroFrame> loopedAnimation;
    // Same as above except you loop an already defined animation (previously you looped frames)
    constexpr auto loopedAnimation2 = loopAnimation<1, 300>(sampleAnimation);

    // Load animation
    constexpr Animation<
        TopLeft, 100,
        Top, 100,
        TopRight | Middle, 100,
        BottomRight, 100,
        Bottom, 100,
        BottomLeft | Middle, 100,
        TopLeft>
        loadAnimation;
}

// Initialize display by specifying pins
using MyDisplay = SevSeg::Display<2, 3, 4, 5, 6, 7, 8, 9>;
// or
constexpr SevSeg::Display<5, 6, 7, 8, 11, 12, 13, 14> display;

void setup()
{
    // Display character (not all characters supported, check definition)
    MyDisplay::displayChar('A');
    // or
    display.displayChar('A');

    // Display a number (0 - 9 supported), you can use displayChar for numbers too (0 -> '0', 1 -> '1', ...)
    MyDisplay::displayDigit(5);
    // or
    display.displayDigit(5);
}

void loop()
{
    // Display animation by specifying frames
    MyDisplay::displayAnimation<SevSeg::topFrame, 100, SevSeg::bottomFrame, 200, SevSeg::zeroFrame>();
    // or
    display.displayAnimation<SevSeg::topFrame, 100, SevSeg::bottomFrame, 200, SevSeg::zeroFrame>();

    // Display animation variable
    MyDisplay::displayAnimation(SevSeg::sampleAnimation);
    // or
    display.displayAnimation(SevSeg::sampleAnimation);

    // Display animation variable
    MyDisplay::displayAnimation(SevSeg::loopedAnimation);
    // or
    display.displayAnimation(SevSeg::loopedAnimation);

    // Display animation variable
    MyDisplay::displayAnimation(SevSeg::loopedAnimation2);
    // or
    display.displayAnimation(SevSeg::loopedAnimation2);

    // Display animation variable
    MyDisplay::displayAnimation(SevSeg::loadAnimation);
    // or
    display.displayAnimation(SevSeg::loadAnimation);
}

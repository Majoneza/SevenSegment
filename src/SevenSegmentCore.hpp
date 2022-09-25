#pragma once

#include <Arduino.h>

namespace SevenSegment
{
    using Pin = uint8_t;
    using State = uint8_t;

    /**
     * @brief Functions for specified operation (change them based on platform/framework)
     * 
     */
    const auto writePinFunction = digitalWrite;
    const auto delayFunction = delay;
    
    /**
     * @brief Display pin states (change them based on platform/framework)
     * 
     */
    constexpr State HIGH_S = HIGH;
    constexpr State LOW_S = LOW;

    /**
     * @brief Display segments
     * 
     */
    constexpr uint32_t Top = (1 << 8);
    constexpr uint32_t TopLeft = (1 << 7);
    constexpr uint32_t TopRight = (1 << 6);
    constexpr uint32_t Middle = (1 << 5);
    constexpr uint32_t BottomLeft = (1 << 4);
    constexpr uint32_t BottomRight = (1 << 3);
    constexpr uint32_t Bottom = (1 << 2);
    constexpr uint32_t Dot = (1 << 1);
    constexpr uint32_t None = 0;
}

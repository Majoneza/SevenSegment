#pragma once

#include <stdint.h>

namespace SevenSegment
{
    /**
     * @brief Type shared between frames and timeouts
     * 
     */
    using Segment = uint32_t;

    /**
     * @brief Display segments
     * 
     */
    constexpr Segment Top = (1 << 8);
    constexpr Segment TopLeft = (1 << 7);
    constexpr Segment TopRight = (1 << 6);
    constexpr Segment Middle = (1 << 5);
    constexpr Segment BottomLeft = (1 << 4);
    constexpr Segment BottomRight = (1 << 3);
    constexpr Segment Bottom = (1 << 2);
    constexpr Segment Dot = (1 << 1);
    constexpr Segment None = 0;
}

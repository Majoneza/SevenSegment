#pragma once

#include "SevenSegmentSegments.hpp"
#include "SevenSegmentAnimation.hpp"

namespace SevenSegment
{
    using Pin = uint8_t;

    /**
     * @brief Class representing SevenSegment display
     * 
     * @tparam topPin Top pin location
     * @tparam topLeftPin Top left pin location
     * @tparam topRightPin Top right pin location
     * @tparam middlePin Middle pin location
     * @tparam bottomLeftPin Bottom left pin location
     * @tparam bottomRightPin Bottom right pin location
     * @tparam bottomPin Bottom pin location
     * @tparam dotPin Dot pin location
     */
    template <Pin topPin,
              Pin topLeftPin,
              Pin topRightPin,
              Pin middlePin,
              Pin bottomLeftPin,
              Pin bottomRightPin,
              Pin bottomPin,
              Pin dotPin>
    class Display
    {
    protected:
        using State = uint8_t;

        /**
         * @brief Functions for specified operation (change them based on platform/framework)
         * 
         */
        static constexpr auto writePinFunction = digitalWrite;
        static constexpr auto delayFunction = delay;
        
        /**
         * @brief Display pin states (change them based on platform/framework)
         * 
         */
        static constexpr State HIGH_S = HIGH;
        static constexpr State LOW_S = LOW;

        template <State topPinVal,
                  State topLeftPinVal,
                  State topRightPinVal,
                  State middlePinVal,
                  State bottomLeftPinVal,
                  State bottomRightPinVal,
                  State bottomPinVal,
                  State dotPinVal>
        static void activatePins()
        {
            writePinFunction(topPin, topPinVal);
            writePinFunction(topLeftPin, topLeftPinVal);
            writePinFunction(topRightPin, topRightPinVal);
            writePinFunction(middlePin, middlePinVal);
            writePinFunction(bottomLeftPin, bottomLeftPinVal);
            writePinFunction(bottomRightPin, bottomRightPinVal);
            writePinFunction(bottomPin, bottomPinVal);
            writePinFunction(dotPin, dotPinVal);
        }

        template <Segment val, Segment... v>
        static void animationFrame()
        {
            activatePins<
                (val & Top) ? HIGH_S : LOW_S,
                (val & TopLeft) ? HIGH_S : LOW_S,
                (val & TopRight) ? HIGH_S : LOW_S,
                (val & Middle) ? HIGH_S : LOW_S,
                (val & BottomLeft) ? HIGH_S : LOW_S,
                (val & BottomRight) ? HIGH_S : LOW_S,
                (val & Bottom) ? HIGH_S : LOW_S,
                (val & Dot) ? HIGH_S : LOW_S>();
            if constexpr (sizeof...(v) > 0)
                animationDelay<v...>();
        }

        template <Segment val, Segment... v>
        static void animationDelay()
        {
            if constexpr (val != 0)
                delayFunction(val);
            if constexpr (sizeof...(v) > 0)
                animationFrame<v...>();
        }

    public:
        /**
         * @brief Create instance of Display
         * 
         */
        constexpr Display() = default;

        /**
         * @brief Display specified character
         * 
         * @param c Character to display
         */
        static void __attribute__((noinline)) displayChar(char c)
        {
            switch (c)
            {
            case '-':
                activatePins<LOW_S, LOW_S, LOW_S, HIGH_S, LOW_S, LOW_S, LOW_S, LOW_S>();
                break;
            case '0':
                activatePins<HIGH_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case '2':
                activatePins<HIGH_S, LOW_S, HIGH_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, LOW_S>();
                break;
            case '3':
                activatePins<HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case '4':
                activatePins<LOW_S, HIGH_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, LOW_S, LOW_S>();
                break;
            case '5':
                activatePins<HIGH_S, HIGH_S, LOW_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case '6':
                activatePins<HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case '7':
                activatePins<HIGH_S, LOW_S, HIGH_S, LOW_S, LOW_S, HIGH_S, LOW_S, LOW_S>();
                break;
            case '8':
                activatePins<HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case '9':
                activatePins<HIGH_S, HIGH_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case 'A':
            case 'a':
                activatePins<HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, LOW_S, LOW_S>();
                break;
            case 'C':
            case 'c':
                activatePins<HIGH_S, HIGH_S, LOW_S, LOW_S, HIGH_S, LOW_S, HIGH_S, LOW_S>();
                break;
            case 'E':
            case 'e':
                activatePins<HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, LOW_S>();
                break;
            case 'F':
            case 'f':
                activatePins<HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S, LOW_S, LOW_S>();
                break;
            case 'H':
            case 'h':
                activatePins<LOW_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, LOW_S, LOW_S>();
                break;
            case 'I':
            case 'i':
                activatePins<LOW_S, LOW_S, HIGH_S, LOW_S, LOW_S, HIGH_S, LOW_S, LOW_S>();
                break;
            case 'J':
            case 'j':
                activatePins<LOW_S, LOW_S, HIGH_S, LOW_S, LOW_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case 'L':
            case 'l':
                activatePins<LOW_S, HIGH_S, LOW_S, LOW_S, HIGH_S, LOW_S, HIGH_S, LOW_S>();
                break;
            case 'O':
            case 'o':
                activatePins<HIGH_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case 'P':
            case 'p':
                activatePins<HIGH_S, HIGH_S, HIGH_S, HIGH_S, HIGH_S, LOW_S, LOW_S, LOW_S>();
                break;
            case 'S':
            case 's':
                activatePins<HIGH_S, HIGH_S, LOW_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case 'U':
            case 'u':
                activatePins<LOW_S, HIGH_S, HIGH_S, LOW_S, HIGH_S, HIGH_S, HIGH_S, LOW_S>();
                break;
            case '_':
                activatePins<LOW_S, LOW_S, LOW_S, LOW_S, LOW_S, LOW_S, HIGH_S, LOW_S>();
                break;
            default:
                activatePins<LOW_S, LOW_S, LOW_S, LOW_S, LOW_S, LOW_S, LOW_S, LOW_S>();
                break;
            }
        }

        /**
         * @brief Display specified digit
         * 
         * @param d Digit to display
         */
        static void displayDigit(uint8_t d)
        {
            displayChar('0' + d);
        }

        /**
         * @brief Display animation by frames
         * 
         * @tparam v Frames to display
         */
        template <Segment... v>
        static void displayAnimation()
        {
            animationFrame<v...>();
        }

        /**
         * @brief Display specified animation
         * 
         * @tparam v Frames to display
         * @param animation Animation to display
         */
        template <Segment... v>
        static void displayAnimation(Animation<v...> animation)
        {
            (void)animation;
            displayAnimation<v...>();
        }
    };
}

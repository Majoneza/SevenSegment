#include <SevenSegment.hpp>

constexpr SevenSegment::Display<5, 6, 7, 8, 11, 12, 13, 14> display;

void setup()
{
}

void loop()
{
    for (uint8_t i = 0; i < 10; i++)
    {
        display.displayDigit(i);

        delay(100);
    }
}

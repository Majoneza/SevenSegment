#pragma once

#include "SevenSegmentCore.hpp"

namespace SevenSegment
{
    /**
     * @brief Class representing SevenSegment animation
     * 
     * @tparam v Animation frames
     */
    template <uint32_t... v>
    class Animation
    {
    public:
        /**
         * @brief Create instance of Animation
         * 
         */
        constexpr Animation() = default;
    };

    template <size_t p, uint32_t ms, uint32_t... v>
    struct AnimationLoop
    {
        using type = typename AnimationLoop<p - 1, ms, v..., ms, v...>::type;
    };

    template <uint32_t ms, uint32_t... v>
    struct AnimationLoop<0, ms, v...>
    {
        using type = Animation<v...>;
    };

    /**
     * @brief Looped animation (2^p times)
     * 
     * @tparam p Power of 2 times to loop animation frames
     * @tparam ms Time to wait between loops (in miliseconds)
     * @tparam v Frames to loop
     */
    template <size_t p, uint32_t ms, uint32_t... v>
    using AnimationLoop_t = typename AnimationLoop<p, ms, v...>::type;

    /**
     * @brief Loop specified animation (2^p times)
     * 
     * @tparam p Power of 2 times to loop animation
     * @tparam ms Time to wait between loops (in miliseconds)
     * @tparam v Frames to loop
     * @param animation Animation to loop
     * @return Looped Animation
     */
    template <size_t p, uint32_t ms, uint32_t... v>
    constexpr AnimationLoop_t<p, ms, v...> loopAnimation(Animation<v...> animation)
    {
        (void)animation;
        return AnimationLoop_t<p, ms, v...>{};
    }
}

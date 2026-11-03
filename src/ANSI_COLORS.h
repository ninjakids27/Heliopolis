#pragma once

#include <iostream>
#include <string>
#include <string>

namespace ansi {

    // Text Attributes
    namespace style {
        inline constexpr std::string reset         = "\033[0m";
        inline constexpr std::string bold          = "\033[1m";
        inline constexpr std::string dim           = "\033[2m";
        inline constexpr std::string italic        = "\033[3m";
        inline constexpr std::string underline     = "\033[4m";
        inline constexpr std::string blink         = "\033[5m";
        inline constexpr std::string reverse       = "\033[7m";
        inline constexpr std::string hidden        = "\033[8m";
        inline constexpr std::string strikethrough = "\033[9m";
    }

    // Standard Foreground Colors
    namespace fg {
        inline constexpr std::string black   = "\033[30m";
        inline constexpr std::string red     = "\033[31m";
        inline constexpr std::string green   = "\033[32m";
        inline constexpr std::string yellow  = "\033[33m";
        inline constexpr std::string blue    = "\033[34m";
        inline constexpr std::string magenta = "\033[35m";
        inline constexpr std::string cyan    = "\033[36m";
        inline constexpr std::string white   = "\033[37m";

        // Bright / High-Intensity
        inline constexpr std::string bright_black   = "\033[90m";
        inline constexpr std::string bright_red     = "\033[91m";
        inline constexpr std::string bright_green   = "\033[92m";
        inline constexpr std::string bright_yellow  = "\033[93m";
        inline constexpr std::string bright_blue    = "\033[94m";
        inline constexpr std::string bright_magenta = "\033[95m";
        inline constexpr std::string bright_cyan    = "\033[96m";
        inline constexpr std::string bright_white   = "\033[97m";
    }

    // Standard Background Colors
    namespace bg {
        inline constexpr std::string black   = "\033[40m";
        inline constexpr std::string red     = "\033[41m";
        inline constexpr std::string green   = "\033[42m";
        inline constexpr std::string yellow  = "\033[43m";
        inline constexpr std::string blue    = "\033[44m";
        inline constexpr std::string magenta = "\033[45m";
        inline constexpr std::string cyan    = "\033[46m";
        inline constexpr std::string white   = "\033[47m";

        // Bright / High-Intensity
        inline constexpr std::string bright_black   = "\033[100m";
        inline constexpr std::string bright_red     = "\033[101m";
        inline constexpr std::string bright_green   = "\033[102m";
        inline constexpr std::string bright_yellow  = "\033[103m";
        inline constexpr std::string bright_blue    = "\033[104m";
        inline constexpr std::string bright_magenta = "\033[105m";
        inline constexpr std::string bright_cyan    = "\033[106m";
        inline constexpr std::string bright_white   = "\033[107m";
    }


    // Convenience Wrappers
    namespace formats {
        inline std::string error( const std::string&  msg) {
            return style::bold + style::underline+fg::bright_red+msg+style::reset;
        }
    }


} // namespace ansi

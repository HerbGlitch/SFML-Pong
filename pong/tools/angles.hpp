#include <math.h>
#include <SFML/Graphics.hpp>

namespace herbglitch {
    namespace tools {
        inline float sec(float radian){
            return (sin(radian) == 0.0f)? 0.0f : 1.0f / sin(radian);
        }

        inline float csc(float radian){
            return (cos(radian) == 0.0f)? 0.0f : 1.0 / cos(radian);
        }

        inline float degreeToRadians(float degree){
            return degree * (M_PI/180.0f);
        }

        inline float radianToDegrees(float radian){
            return radian * (180.0f/M_PI);
        }
    }
}
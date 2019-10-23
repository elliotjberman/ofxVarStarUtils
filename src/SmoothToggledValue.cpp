//
//  SmoothToggledValue.cpp
//  20191017
//
//  Created by Elliot Berman on 10/23/19.
//

#include "SmoothToggledValue.hpp"
#include "cmath"
#include "sstream"

SmoothToggledValue::SmoothToggledValue(float min,
                                       float max,
                                       float currentValue,
                                       float slope,
                                       float speed,
                                       bool  on)
                                       :
                                       d_min(min),
                                       d_max(max),
                                       d_currentValue(currentValue),
                                       d_slope(slope),
                                       d_speed(speed),
                                       d_on(on)
{
    if (d_currentValue < min || d_currentValue > max) {
        d_currentValue = d_on ? d_max : d_min;
    }
}

void SmoothToggledValue::update() {
    if (d_on && d_currentValue < d_max) {
        d_currentValue += std::pow(d_max - d_currentValue, d_slope) * d_speed;
    }
    else if (!d_on && d_currentValue > d_min) {
        d_currentValue -= std::pow(d_currentValue - d_min, d_slope) * d_speed;
    }
}

float SmoothToggledValue::value() const {
    return d_currentValue;
}

void SmoothToggledValue::toggle() {
    d_on = !d_on;
}

const std::string SmoothToggledValue::log() const {
    std::ostringstream stream;
    stream
    << "min: "           << d_min           << std::endl
    << "max: "           << d_max           << std::endl
    << "currentValue: "  << d_currentValue  << std::endl
    << "slope: "         << d_slope         << std::endl
    << "speed: "         << d_speed         << std::endl
    << "on: "            << d_on            << std::endl;
    return stream.str();
};

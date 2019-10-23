//
//  AnimatedValue.cpp
//  20191017
//
//  Created by Elliot Berman on 10/22/19.
//

#include "AnimatedValue.hpp"
#include "sstream"

AnimatedValue::AnimatedValue(float startingValue, float rate) :
d_startingValue(startingValue),
d_currentValue(startingValue),
d_rate(rate) {}

void AnimatedValue::update() {
    if (d_currentValue > d_startingValue) {
        d_currentValue /= (1.0 + d_rate);
    }
}

void AnimatedValue::setValue(float newVal) {
    d_currentValue = newVal;
}

float AnimatedValue::value() const {
    return d_currentValue;
}

void AnimatedValue::bump(float extra) {
    setValue(value() + extra);
}

const std::string AnimatedValue::log() const {
    std::ostringstream stream;
    stream << "startingValue: " << d_startingValue << std::endl
           << "currentValue: "  << d_currentValue  << std::endl
           << "rate: "          << d_rate          << std::endl;
    return stream.str();
};


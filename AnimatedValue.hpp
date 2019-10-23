//
//  AnimatedValue.hpp
//  20191017
//
//  Created by Elliot Berman on 10/22/19.
//

#ifndef AnimatedValue_hpp
#define AnimatedValue_hpp

#include "string"

class AnimatedValue {

private:
    float d_startingValue;
    float d_currentValue;
    float d_rate;
    
public:
    AnimatedValue(float startingValue=0.0, float rate=0.1);
    void update();
    void setValue(float newVal);
    float value() const;
    void bump(float extra);
    const std::string log() const;
    
};

#endif /* AnimatedValue_hpp */

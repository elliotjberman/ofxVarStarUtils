//
//  SmoothToggledValue.hpp
//  20191017
//
//  Created by Elliot Berman on 10/23/19.
//

#ifndef SmoothToggledValue_hpp
#define SmoothToggledValue_hpp

#include "string"

class SmoothToggledValue {
private:
    float d_currentValue;
    float d_min;
    float d_max;
    float d_slope;
    float d_speed;
    bool  d_on;
    
public:
    SmoothToggledValue(float min,
                       float max,
                       float currentValue = 0.0,
                       float slope        = 1.5,
                       float speed        = 1.0/100,
                       bool  on           = true);
    
    void update();
    void toggle();
    float value() const;
    const std::string log() const;
    
};

#endif /* SmoothToggledValue_hpp */

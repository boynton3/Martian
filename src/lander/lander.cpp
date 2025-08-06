#include "lander.h"
#include <cmath>
#include <iostream>



/********************************************
 * Lander - setup
 ********************************************/
// Constructor: initializes lander state with starting altitude and fuel.
Lander::Lander(double position, double fuel) {
    m_position = position;
    m_fuel = fuel;
    m_velocity = 0.0;
}

/** applyThrust Member Function: applies thrust to the lander.
* \param thrust: Thrust power as a fraction (0.0 = no thrust, 1.0 = max thrust).
* If fuel is insufficient, thrust will be proportionally limited.
*/    
void Lander::applyThrust(double thrust) {
    //don't apply thrust if lander has landed, crashed, or out of fuel
    if (landed || crashed || m_fuel <= 0.0) {
        return;
    }

    //calculate fuel for thrust amount 
    double fuelUsed = fuelBurnRate * thrust;
    double deceleration = maxThrust * thrust;

    //if no fuel - cannot apply thrust. Maybe add an error message here
    if (m_fuel <= 0.0) {
        return;
    }
    //burn the fuel available 
    if (m_fuel < fuelUsed) {
        thrust = m_fuel / fuelBurnRate;
        fuelUsed = m_fuel;
    }

    //apply upwards acceleration to reduce velocity
    m_velocity -= deceleration;
    //consume fuel
    m_fuel -= fuelUsed;
}

/** update Member Function: updates the velocity of the lander.
* @param dt Time step in seconds.
* Applies gravity and updates velocity and altitude accordingly.
* Detects landing or crashing conditions    
*/    
void Lander::update(double dt) {
    if (landed|| crashed) {
        return;
    }

    m_velocity += gravity * dt;
    m_position -= m_velocity * dt;

    //if altitude is 0, then landed
    if (m_position <= 0) {
        m_position = 0.0;
        landed = true;
    

        //crash condition
        if (m_velocity > 5.0) {
            crashed = true;
        }
        //reset velocity after contact
        m_velocity = 0.0;
    }

}

// Get current altitude in meters.
double Lander::getPosition() const {
    return m_position;

}
// Get current velocity in m/s (positive means falling).
double Lander::getVelocity() const {
    return m_velocity;

}

// Get remaining fuel units
double Lander::getFuel() const {
    return m_fuel;

} 


        
// Check if the lander has landed (altitude == 0).
bool Lander::hasLanded() const {
    // has landed returns true as long as the altitude is 0
    // and hasCrashed is false
    return landed;

}
// Check if the lander has crashed (landed too fast)
bool Lander::hasCrashed() const {
    return crashed;

}


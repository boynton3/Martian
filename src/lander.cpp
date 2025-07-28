#include lander.h
#include <iostream>




// Constructor: initializes lander state with starting altitude and fuel.
Lander::Lander(double altitude, double fuel) {
    m_altitude = altitude;
    m_fuel = fuel;
    m_velocity = 0.0;
}

/** applyThrust Member Function: applies thrust to the lander.
* \param amount: Thrust power as a fraction (0.0 = no thrust, 1.0 = max thrust).
* If fuel is insufficient, thrust will be proportionally limited.
*/    
void Lander::applyThrust(double amount) {

}

/** update Member Function: updates the velocity of the lander.
* @param dt Time step in seconds.
* Applies gravity and updates velocity and altitude accordingly.
* Detects landing or crashing conditions    
*/    
void Lander::update(double dt) {

}

// Get current altitude in meters.
double Lander::getAltitude() const {
    return altitude;

}
// Get current velocity in m/s (positive means falling).
double Lander::getVelocity() const {
    return velocity;

}

// Get remaining fuel units
double Lander::getFuel() const {
    return fuel;

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


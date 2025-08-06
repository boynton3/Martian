#pragma once


/**
Lander Class: 
defines and tracks altitude, velocity, and fuel
*/

class Lander {
    public:
    /** Constructor for a new Lander Object
    * \param position: starting height in meters above surface.
    * \param fuel: intial fuel supply available for descent.
    */
    Lander(double position, double fuel);

    /** applyThrust Member Function: applies thrust to the lander.
    * \param thrust: Thrust power as a fraction (0.0 = no thrust, 1.0 = max thrust).
    * If fuel is insufficient, thrust will be proportionally limited.
    */    
    void applyThrust(double thrust);

    /** update Member Function: updates the velocity of the lander.
    * @param dt Time step in seconds.
    * Applies gravity and updates velocity and altitude accordingly.
    * Detects landing or crashing conditions    
    */    
    void update(double dt);

    double getPosition() const;        // Get current altitude in meters.
    double getVelocity() const;        // Get current velocity in m/s (positive means falling).
    double getFuel() const;            // Get remaining fuel units
    bool hasLanded() const;            // Check if the lander has landed (altitude == 0).
    bool hasCrashed() const;           // Check if the lander has crashed (landed too fast)

    private:
    // Current altitude, velocity, and remaining fuel 
    double m_position;
    double m_velocity;
    double m_fuel;


    const double gravity = 3.71;        // Mars gravity (m/s²)
    const double maxThrust = 10.0;      // Max acceleration from thrust in m/s²
    const double fuelBurnRate = 0.5;    // Fuel units per second at full thrust

    bool landed = false;                // True if lander has touched down.
    bool crashed = false;               // True if lander landed with unsafe velocity.

};
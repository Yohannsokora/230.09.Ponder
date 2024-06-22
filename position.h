/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *      Amelia Tuttle
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>

class TestPosition;
class Acceleration;
class Velocity;
class TestGround;
class TestHowitzer;
class TestProjectile;


/*********************************************
 * Position
 * A single position on the field in Meters  
 *********************************************/
class Position
{
public:
   friend ::TestPosition;
   friend ::TestGround;
   friend ::TestHowitzer;
   friend ::TestProjectile;

   
   // constructors
   Position()            : x(0.0), y(0.0)  {}
    Position(double x, double y) : x(x), y(y) {}
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);

   // getters
    double getMetersX() const { return x; }
    double getMetersY() const { return y; }

    double getPixelsX() const 
    {
        return x * metersFromPixels;
    }

    double getPixelsY() const 
    {
        return y * metersFromPixels;
   }
   static double getZoom() { return metersFromPixels; }

   // setters
   void setZoom(double z) {}
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)       { x = xMeters;  }
   void setMetersY(double yMeters)       { y = yMeters; }
   void setPixelsX(double xPixels)       { x = xPixels / metersFromPixels; }
   void setPixelsY(double yPixels)       { y = yPixels / metersFromPixels; }
   void add(const Acceleration& a, const Velocity& v, double t);

   // add methods
    double addMetersX(double xMeters) { x += xMeters; return x; }
    double addMetersY(double yMeters) { y += yMeters; return y; }
    double addPixelsX(double xPixels) { return addMetersX(xPixels / metersFromPixels); }
    double addPixelsY(double yPixels) { return addMetersY(yPixels / metersFromPixels); }

    void reverse() { x = -x; y = -y; }


private:
   double x;                 // horizontal position
   double y;                 // vertical position
   static double metersFromPixels;
};

// Initialize static member variable
double Position::metersFromPixels = 1.0;

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};



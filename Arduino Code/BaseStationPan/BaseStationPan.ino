#include <math.h>

void setup() {
  Serial.begin(9600);
}

double roverLongitude = -110.792203; //Rover coordinates will be updated every loop cycle.
double roverLatitude = 38.406545;
const double baseLongitude = -110.792196; //Once base station is set and coords identified, they will remain constant.
const double baseLatitude = 38.406345;

double thetaInQuadrant; // Theta of 0 is NORTH, increases clockwise around circle - describes actual position of rover relative to base station. It is in RADIANS - note that 0 radians here refers to north, which is not conventional
double roverAngle;
double angleCorrection = 0; //Arctan always returns an angle in the first quadrant, so use this to correct this if x or y are negative
double difference = 0; //Difference between the current heading and actual rover position
double currentHeading = 0; //currentHeading will be calculated using rover position data and base station position data

double x; //x-position of rover relative to base station
double y; //y-position of rover relative to base station

void loop()
{ 
  //Get rover coordinates from GPS/ubiquity
  
  //Convert coordinates to cartesian using gpsToCartesian()
  
  gpsToCartesian();
  
  roverAngle = getAngle(x,y); //Find angle from base station to rover
  
  difference = roverAngle - currentHeading; //Difference between angle of rover (describes actual GPS position) and the current heading of the base station based on magnetometer
  
  Serial.println();
  Serial.print("angle:"); Serial.println(roverAngle);
  Serial.print("currentHeading:"); Serial.println(currentHeading);
  Serial.print("difference:"); Serial.println(difference);
  Serial.println();
  
  Serial.print("Turned "); //To be replaced by actual motor-controlling code, for now just prints to serial monitor - is supposed to account for small changes in theta and rotate the base station accordingly and in the correct direction
  if (difference >= 0 && difference < M_PI)
  {
    Serial.print(difference); Serial.println(" radians (clockwise)");
  }
  else if (difference < 0 && difference > -M_PI)
  {
    Serial.print(difference); Serial.println(" radians (counterclockwise)");
  }
  else if (difference >= M_PI) //If difference greater than pi (180 degrees), assume we crossed from the northwest quadrant to the northeast, and take the shortest rotational path to go across the axis
  {
    Serial.print(-(M_PI/2-thetaInQuadrant)+currentHeading); Serial.println(" radians (counterclockwise)");
  }
  else if (difference <= -M_PI) //Same deal as above but if rotating the other way
  {
    Serial.print(((2*M_PI-currentHeading)+thetaInQuadrant)); Serial.println(" radians (clockwise)");
  }
  
  //Turn base station in direction of rover
  currentHeading = roverAngle; // Use for testing - in real code must make this control the motor
  
  //x--; //For debugging - increment x-position
  
  delay(5);
}

void gpsToCartesian()
{
  double longitudeDifference = roverLongitude - baseLongitude; //Difference in longitude from rover to base
  double latitudeDifference = roverLatitude - baseLatitude; //Difference in latitude
  
  //Using coordinate system with the base station at the origin:
  x = 87.17*longitudeDifference*1000; //87.17 km per longitude line near the Mars Desert Research Station
  y = 111.2*latitudeDifference*1000; //111.2 km per latitude line anywhere in the world
  
  Serial.println(x); Serial.println(y);
}

double getAngle(double px, double py)
{
  if (px == 0 || py == 0) //Check if positions equal zero- to handle "edge cases" where points are on the axes and prevent divide by zero in the arctan calculation
  {
    angleCorrection = 0;
    if (px == 0)
    {
      if (py >= 0)
      {
        thetaInQuadrant = 0; //Theta of 0 is NORTH - X-coord is 0 and Y is POSITIVE
      }
      else if (py < 0)
      {
        thetaInQuadrant = M_PI; //Theta of pi is SOUTH - X-coord 0, Y is NEGATIVE
      }
    }
    else if (py == 0)
    {
      if (px >= 0)
      {
        thetaInQuadrant = M_PI/2; //Theta of pi/2 is EAST - X-coord POSITIVE, Y is 0
      }
      else if (px < 0)
      {
        thetaInQuadrant = 3*M_PI/2; //Theta of 3pi/2 is WEST - X-coord NEGATIVE, Y is 0
      }
    }
  }
  else
  {
    if (px > 0 && py > 0) //If both x and y are positive, rover is in the NORTHEAST quadrant
    {
      angleCorrection = 0; //Do not add anything to arctan output
      thetaInQuadrant = atan2(abs(px),abs(py));
    }
    else if (px > 0 && py < 0) //SOUTHEAST quadrant
    {
      angleCorrection = M_PI/2; //Arctan angle + pi
      thetaInQuadrant = atan2(abs(py),abs(px));
    }
    else if (px < 0 && py < 0) //SOUTHWEST quadrant
    {
      angleCorrection = M_PI;
      thetaInQuadrant = atan2(abs(px),abs(py));
    }
    else if (px < 0 && py > 0) //NORTHWEST quadrant
    {
      angleCorrection = 3*M_PI/2;
      thetaInQuadrant = atan2(abs(py),abs(px));
    }
    return thetaInQuadrant + angleCorrection; //Take arctan of absolute value of x and y, plus the pi/2, pi, or 3pi/2 correction to get the correct quadrant of the rover
  }
}

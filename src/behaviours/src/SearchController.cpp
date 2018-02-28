#include "SearchController.h"
#include <angles/angles.h>

SearchController::SearchController() {
  rng = new random_numbers::RandomNumberGenerator();
  currentLocation.x = 0;
  currentLocation.y = 0;
  currentLocation.theta = 0;

  centerLocation.x = 0;
  centerLocation.y = 0;
  centerLocation.theta = 0;
  result.PIDMode = FAST_PID;

  result.fingerAngle = M_PI/2;
  result.wristAngle = M_PI/4;
}

void SearchController::Reset() {
  result.reset = false;
}

/**
 * This code implements a basic random walk search.
 */
Result SearchController::DoWork() {



if(roverName=="achilles"){
    result.type = waypoint;

    Point  searchLocation;

    // setting int waypoint
    searchLocation.theta = currentLocation.theta;
    searchLocation.x = -5;
    searchLocation.y = 5;

    result.wpts.waypoints.clear();
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);

    
    searchLocation.x = -5;
    searchLocation.y = 4;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    
    searchLocation.x = -4;
    searchLocation.y = 4;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    
    searchLocation.x = -4;
    searchLocation.y = 5;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
} else if ( roverName == "ajax"){
    result.type = waypoint;

    Point  searchLocation;

    // setting int waypoint
    searchLocation.theta = currentLocation.theta;
    searchLocation.x = 5;
    searchLocation.y = 5;

    result.wpts.waypoints.clear();
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);

    
    searchLocation.x = 5;
    searchLocation.y = 4;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    
    searchLocation.x = 4;
    searchLocation.y = 4;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    
    searchLocation.x = 4;
    searchLocation.y = 5;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
} else if ( roverName == "aeneas"){
    result.type = waypoint;

    Point  searchLocation;

    // setting int waypoint
    searchLocation.theta = currentLocation.theta;
    searchLocation.x = -2;
    searchLocation.y = -5;

    result.wpts.waypoints.clear();
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);

    
    searchLocation.x = 2;
    searchLocation.y = -5;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    
    searchLocation.x = 2;
    searchLocation.y = -4;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    
    searchLocation.x = -2;
    searchLocation.y = -4;
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
}

/*
  if (!result.wpts.waypoints.empty()) {
    if (hypot(result.wpts.waypoints[0].x-currentLocation.x, result.wpts.waypoints[0].y-currentLocation.y) < 0.15) {
      attemptCount = 0;
    }
  }

  if (attemptCount > 0 && attemptCount < 5) {
    attemptCount++;
    if (succesfullPickup) {
      succesfullPickup = false;
      attemptCount = 1;
    }
    return result;
  }
  else if (attemptCount >= 5 || attemptCount == 0) 
  {
    attemptCount = 1;


    result.type = waypoint;
    Point  searchLocation;

    //select new position 50 cm from current location
    if (first_waypoint)
    {
      first_waypoint = false;
      searchLocation.theta = currentLocation.theta + M_PI;
      searchLocation.x = currentLocation.x + (0.5 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (0.5 * sin(searchLocation.theta));
    }
    else
    {
      //select new heading from Gaussian distribution around current heading
      searchLocation.theta = rng->gaussian(currentLocation.theta, 0.785398); //45 degrees in radians
      searchLocation.x = currentLocation.x + (0.5 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (0.5 * sin(searchLocation.theta));
    }

    result.wpts.waypoints.clear();
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);

    */
    
    return result;
  

}

void SearchController::SetCenterLocation(Point centerLocation) {
  
  float diffX = this->centerLocation.x - centerLocation.x;
  float diffY = this->centerLocation.y - centerLocation.y;
  this->centerLocation = centerLocation;
  
  if (!result.wpts.waypoints.empty())
  {
  result.wpts.waypoints.back().x -= diffX;
  result.wpts.waypoints.back().y -= diffY;
  }
  
}

void SearchController::SetRoverName(string name){
  roverName = name;
  cout << roverName << endl;
}

void SearchController::SetCurrentLocation(Point currentLocation) {
  this->currentLocation = currentLocation;
}

void SearchController::ProcessData() {
}

bool SearchController::ShouldInterrupt(){
  ProcessData();

  return false;
}

bool SearchController::HasWork() {
  return true;
}

void SearchController::SetSuccesfullPickup() {
  succesfullPickup = true;
}



//#include<string>
//#include <cstdlib>// no need for this as is in header
#include "Circle.h"
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

Circle::Circle(){
  //if you have regular constructor you must
  //define default constructor
  //C++ will not auto create for you
  x=0;
  y=0;
  radius=1;
  count++;
}
Circle::Circle(int xcoord,int ycoord, int r){
      x=xcoord;
      y=ycoord;
      radius=r;  
      count++;
   }
int Circle::getX(){
      return x;
   }
   int Circle::getY(){
      return y;
   }
   
   int Circle::getRadius(){
      return radius;
   }
   int Circle::getCount(){
     return count;
   }
  void Circle::setX(int xcoord){
       x=xcoord;
  }
  void Circle::setY(int xcoord){
       x=xcoord;
  }
  void Circle::setRadius(int r){
       radius=r;
  }
  double Circle::getArea(){
    return M_PI*pow(radius,2);
  }
  double Circle::getCircumference(){
    return M_PI*radius/2;
  }
  double Circle::getDistance(Circle other){
       return sqrt(pow(x-other.getX(),2)+pow((y-other.getY()),2));
  }
  bool Circle::intersects(Circle other){
    return (this->getDistance(other)<=radius);
  }
  void Circle::resize(double scale){
    radius = scale*radius;
  }
  Circle Circle::resize(int scale){
    Circle c(x,y,radius*scale);
    return c;
  }
  string Circle::toString(){
    return "(" +to_string(x)+","+to_string(y)+"):"+to_string(radius);
  }
  // *****note the change to this parameter
  //  make suitable changes where need to other instance methods
  bool Circle::greaterThan(shared_ptr<Circle> other){
    return radius>other->getRadius();
  }
Circle::~Circle(){
  //std::cout<<"Inside Destructor "<<endl;
  //if you have dynamically allocated memory
  //you must release/delete it here

}

int Circle::count=0;

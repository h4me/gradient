#include <iostream>
#include <vector>


struct Point {
    size_t x;
    size_t y;
    Point(size_t x, size_t y) : x{x}, y{y} {}
};


double cost_function(const std::vector<Point>& v, double m=0.0, double b=0.0)
{
                 double cost = 0.0;
                 double n = static_cast<double>(v.size()); 
                 for( auto& point : v )
                 {
                        double x = static_cast<double>(point.x);  
                        double y = static_cast<double>(point.y);  
                       
                        double b = static_cast<double>(b);    
                        cost += (y - (m*x + b)) * (y - (m*x + b));        
                 } 

                 return cost / n ;                  
}

double derM( const std::vector<Point>& v, double m=0.0, double b=0.0)
{
                 double cost = 0.0;
                 double n = static_cast<double>(v.size()); 
                 for( auto& point : v )
                 {
                        double x = static_cast<double>(point.x);  
                        double y = static_cast<double>(point.y);  
                       
                        double b = static_cast<double>(b);    
                        cost += -x*(y - (m*x + b));        
                 } 

                 return static_cast<double>(2)*(cost / n);    
}


double derB( const std::vector<Point>& v, double m=0.0, double b=0.0)
{
                 double cost = 0.0;
                 double n = static_cast<double>(v.size()); 
                 for( auto& point : v )
                 {
                        double x = static_cast<double>(point.x);  
                        double y = static_cast<double>(point.y);  
                       
                        double b = static_cast<double>(b);    
                        cost += -(y - (m*x + b));        
                 } 

                 return static_cast<double>(2)*(cost / n);    
}

void gradient(const std::vector<Point>& v)
{

      // y = mx + b
      double slope_m_curr = 0;
      double intercept_b_curr = 0;    
      size_t iteration = 19000;
      double lrn = 0.0001;

     double m_curr = 0.0;
     double b_curr = 0.0;
    
     while(iteration--)
     {
         double cost = cost_function(v,m_curr,b_curr);      
         m_curr -= lrn * derM(v,m_curr,b_curr);
         b_curr -= lrn * derB(v,m_curr,b_curr);          
         
         std::cout << "Cost " << cost  << " m_curr="<< m_curr << " b_curr="<< b_curr << std::endl; 
     } 
   


}


int main(int argc, char **argv) {

// http://fooplot.com/#W3sidHlwZSI6MCwiZXEiOiIxLjM5eC0zLjE1IiwiY29sb3IiOiIjMDAwMDAwIn0seyJ0eXBlIjozLCJlcSI6W1siMiIsIjMiXSxbIjQiLCIzIl0sWyI1IiwiMSJdLFsiOSIsIjE3Il1dLCJjb2xvciI6IiMwMDAwMDAifSx7InR5cGUiOjEwMDAsIndpbmRvdyI6WyItMzYuNTkxNzQ2OTcyMzg1MTQ1IiwiMzYuNTkxNzQ2OTcyMzg1MTQ1IiwiLTIyLjUxNzk5ODEzNjg1MjQwNSIsIjIyLjUxNzk5ODEzNjg1MjQwNSJdfV0-
 std::vector<Point> v = { {2,3}, {4,3}, { 5,1} , { 9, 17} };


// std::vector<Point> v = { {1,1}, {2,2}, { 3,3} , { 4, 4} };
// http://fooplot.com/#W3sidHlwZSI6MCwiZXEiOiJ4KzAuMyIsImNvbG9yIjoiIzAwMDAwMCJ9LHsidHlwZSI6MywiZXEiOltbIjEiLCIxIl0sWyIyIiwiMiJdLFsiMyIsIjMiXSxbIjQiLCI0Il1dLCJjb2xvciI6IiMwMDAwMDAifSx7InR5cGUiOjEwMDAsIndpbmRvdyI6WyItOS41OTIzMDY5MTgzMjg5NDQiLCI5LjU5MjMwNjkxODMyODk0NCIsIi01LjkwMjk1ODEwMzU4NzA0NSIsIjUuOTAyOTU4MTAzNTg3MDQ1Il19XQ--



gradient(v);

    return 0;
}
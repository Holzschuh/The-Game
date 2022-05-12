/// Nome: Rafael Holzschuh de Araujo
/// Matrícula: 201311194

#ifndef POINT_H
#define POINT_H

class Point
{
   public:
      float x, y, z, h;

/// CONSTRUTORES
      Point();
      Point(float, float);
      virtual ~Point();


/// MÉTODOS

      Point operator + (const float&);
      Point operator + (const Point&);
      Point operator - ();
      Point operator - (const Point&);
      Point operator * (const float&);
      float operator * (const Point&);
      Point operator ^ (const float&);
      Point midPoint(Point p);
      float angleWithVector(Point v);
      float vectorSize();
      float distance(Point p);
      void normalize();
      void print();
      void setPoint(float x, float y);
      Point floatToPoint(float x, float y);

   protected:
   private:

};

#endif // POINT_H

/// Nome: Rafael Holzschuh de Araujo
/// Matrícula: 201311194

#ifndef MATRIX2D_H
#define MATRIX2D_H

#define IDENTITY "identity"
#define RANDOM "random"
#define ROTATE "rotate"
#define TRANSLATE "translate"
#define SCALE "scale"

#include "Point.h"
#include "math.h"

using namespace std;

class Matrix2d{
    public:
        float elem[3][3];

        Matrix2d(char*);
        Matrix2d();
        virtual ~Matrix2d();

        void toRotate(float angle);
        void toTranslate(Point destiny);
        void toScale(float xMultiplier, float yMultiplier);
        Matrix2d operator * (const Matrix2d& matrix);
        Point operator * (const Point& point);
        void print();
        Matrix2d transposed();


    protected:
    private:
};

#endif // MATRIX_H

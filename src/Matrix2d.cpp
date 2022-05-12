#include "Matrix2d.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Matrix2d::Matrix2d(){}
Matrix2d::~Matrix2d(){}
Matrix2d::Matrix2d(char* s){
    int i,j;
    if(!strcmp(s, "random")){
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                elem[i][j] = rand()%10;
            }
        }
    }
    else if(!strcmp(s, "identity")){
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(i==j){
                    elem[i][j] = 1;
                }
                else{
                    elem[i][j] = 0;
                }
            }
        }
    }
}

void Matrix2d::print(){

    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cout << elem[i][j] << " ";
        }
        cout << endl;
    }
}
void Matrix2d::toRotate(float ang){
    elem[0][0] = cos(ang);
    elem[0][1] = -sin(ang);
    elem[1][0] = sin(ang);
    elem[1][1] = cos(ang);
}
void Matrix2d::toTranslate(Point jump){
    elem[0][2] = jump.x;
    elem[1][2] = jump.y;
}
void Matrix2d::toScale(float x, float y){
    elem[0][0] = x;
    elem[1][1] = y;
}
Matrix2d Matrix2d::transposed(){
    int i,j;
    Matrix2d mT;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            mT.elem[j][i] = elem[i][j];
        }
    }
    return mT;
}
Matrix2d Matrix2d::operator * (const Matrix2d& m){
    int i,j,k;
    Matrix2d ans;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            ans.elem[i][j] = 0;
            for(k=0; k<3; k++){
                ans.elem[i][j] += elem[i][k] * m.elem[k][j];
            }
        }
    }
    return ans;
}
Point Matrix2d::operator * (const Point& p){
    int i,j,k;
    Point ans;
    float vPoint[3];
    float vAns[3];

    vPoint[0] = p.x; vAns[0] = 0;
    vPoint[1] = p.y; vAns[1] = 0;
    vPoint[2] = p.h; vAns[2] = 0;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            vAns[i] += elem[i][j] * vPoint[j];
        }
    }
    ans.x = vAns[0];
    ans.y = vAns[1];
    ans.h = vAns[2];

    return ans;
}


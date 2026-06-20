#pragma once
#include <Arduino.h>
struct Question 
{
    int a;         
    int b;         
    char op;       
    int answer;    
};

class QuestionGen 
{
private:
    int minVal;    
    int maxVal;    
public:
    
    // ИСПРАВЛЕНО: значения по умолчанию, чтобы работал вызов "QuestionGen generator;" в main.cpp
    QuestionGen(int min = 2, int max = 10);
    Question next();
};
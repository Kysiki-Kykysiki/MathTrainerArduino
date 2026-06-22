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
    
   
    QuestionGen(int min = 2, int max = 10);
    Question next();
};
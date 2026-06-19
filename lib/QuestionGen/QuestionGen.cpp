#include <QuestionGen.h>

QuestionGen::QuestionGen(int min, int max) 
{
    minVal = min;
    maxVal = max;
}
Question QuestionGen::next() 
{
    Question q;

    q.a = random(minVal,maxVal);
    q.b = random(minVal,maxVal);

    int opType = random(0,3);

    switch (opType)
    {
    case 0:
        q.op = "+"
        q.answer = q.a + q.b;
        break;
    case 1:
        q.op = "-"
        q.answer = q.a - q.b;
        break;
    case 2:
        q.op = "*"
        q.answer = q.a * q.b;
        break;
         
    }

    return q;
}
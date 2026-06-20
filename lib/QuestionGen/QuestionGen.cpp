#include <QuestionGen.h>

QuestionGen::QuestionGen(int min, int max)
{
    minVal = min;
    maxVal = max;
}
Question QuestionGen::next()
{
    Question q;

    q.a = random(minVal,maxVal + 1);
    q.b = random(minVal,maxVal + 1);

    int opType = random(0,3);

    switch (opType)
    {
    case 0:
        q.op = '+';
        q.answer = q.a + q.b;
        break;
    case 1:
        if(q.a < q.b){
            int t = q.a; 
            q.a = q.b; 
            q.b = t;
        }
        q.op = '-';
        q.answer = q.a - q.b;
        break;
    case 2:
        q.op = '*';
        q.answer = q.a * q.b;
        break;
    default:
        q.op = '+';
        q.answer = q.a + q.b;
        break;
    }
    return q;
}
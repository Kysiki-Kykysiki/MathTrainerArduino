# Отчёт об ошибках MathTrainerV1.0

---
## Как искали ошибки?

1. Компилятор C++
2. Поиск ошибок с помощью Serial Monitor

---

**Критичность ошибки/приоритет решения**
🟥 -> 🟧 -> 🟨 -> 🟩

### Найденные ошибки

|#|Тип|Путь|Причина|
|--|--|--|--|
|1|🟥|/src/main.cpp | Ошибка в названии вызываемой функции|
|2|🟥|/lib/QuestionGen/QuestionGen.cpp | *Ошибка в инициаоизации конструктора по умолчанию*|
|3|🟥|/lib/QuestionGen/QuestionGen.cpp | char/строка + пропущенные ;|
|4|🟥|/lib/Display/Display.h | Пропущена ; после создания класса|
|5|🟧|/lib/QuestionGen/QuestionGen.cpp | *Отрицательный результат вычитания*|
|6|🟨|/lib/QuestionGen/QuestionGen.cpp | *random не включает верхнюю границу*|
|7|🟩|/lib/QuestionGen/QuestionGen.cpp | *Отсутствие default в конструкции switch*|

*Курсив* - ошибка логики/стиля.


1. Ошибка в названии вызываемой функции.
```C++
58 askNewQuestion(); -> newQuestion();
```

2. *Ошибка в инициаоизации конструктора по умолчанию*

**QuestionGen.cpp**
```C++
4 QuestionGen(int min, int max) -> QuestionGen(int min=2, int max=10)
```

3. char/строка + пропущенные ;

**QuestionGen.cpp**
```C++
//БЫЛО
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


//СТАЛО
    case 0:
        q.op = '+';
        q.answer = q.a + q.b;
        break;
    case 1:
        q.op = '-';
        q.answer = q.a - q.b;
        break;
    case 2:
        q.op = '*';
        q.answer = q.a * q.b;
        break;
```

4. Пропущена ; после создания класса

**Display.h**
```C++
21 } -> };
```

5. *Отрицательный результат вычитания*
**Причина:** При ```a < b``` ответ отрицательный, но ```InputHandler``` принимает значения от ```0-9``` - знак "минус" ввести нельзя, следовательно пример становится нерешаемым.
**Решение:** При вычитании меняем местами a и b, если ```a < b```.

```C++
case 1:
    if(q.a < q.b){
        int t = q.a; 
        q.a = q.b; 
        q.b = t;
    }
    q.op = '-';
    q.answer = q.a - q.b;
    break;
```
6. *random не включает верхнюю границу*

**Причина:** ```random(minVal,maxVal)``` получает значения в диапазоне ```[minVal, maxVal)```.
**Решение:** ```random(minVal,maxVal + 1)```

```C++
//БЫЛО
q.a = random(minVal,maxVal);
q.b = random(minVal,maxVal);

//СТАЛО
q.a = random(minVal,maxVal + 1);
q.b = random(minVal,maxVal + 1);
```

7. *Отсутствие default в конструкции switch* 

**Решение:** Добавлена ветка ```default``` с ```q.op = '+'```.

```C++
//БЫЛО
case 2:
    q.op = '*';
    q.answer = q.a * q.b;
    break;
}

//СТАЛО
case 2:
    q.op = '*';
    q.answer = q.a * q.b;
    break;
default:
    q.op = '+';
    q.answer = q.a + q.b;
    break;
}
```
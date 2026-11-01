# Лабораторная работа: Строки, векторы и словари

## Автор

ФИО: Сабитов И.И.  
Вариант: 28

## Цель

Освоение работы со строками, векторами и словарями.

## Описание

Программа последовательно выполняет четыре задания:

1. Ищет позицию первого вхождения подстроки в строке.
    
2. Дублирует исходный вектор (добавляет его копию в конец).
    
3. Вычисляет сумму всех значений в словаре.
    
4. Находит клиентов, у которых есть более одного различного адреса доставки, и выводит их имена по алфавиту.
    

## Используемые средства

- <string> - хранение и посимвольная обработка текста, getline(), find(), length();
    
- <vector> - последовательность чисел, push_back(), size(), обход по индексу;
    
- <map> - словарь «ключ - значение», operator[], find(), обход пар first/second;
    
- vector<map<string, string>> - список записей с именованными полями в части D.

## Исходные данные

Для проверки работы программы введите следующие данные последовательно для каждой из четырех частей:

Часть А (строка и подстрока):  
```
Cat a12 dog Cat  
Cat
```
Часть B (количество элементов и сами элементы):  
```
7  
-2 0 3 3 -1 4 0
```
Часть C (количество пар, затем сами пары ключ-значение):  
```
4  
beta 2  
alpha 5  
beta 3  
gamma -1
```
Часть D (количество записей, затем имена и адреса):  
```
4  
Anna  
Lenina 1  
Bob  
Mira 2  
Anna  
Mira 3  
Bob  
Mira 2
```

## Ожидаемые результаты

Программа выводит результаты для каждой из четырех частей.

Пример вывода программы:  
```
Enter the main string: Cat a12 dog Cat  
Enter the substring: Cat  
Answer: 1

Enter the number of elements: 7  
Enter element 1: -2 0 3 3 -1 4 0  
Vector user: -2 0 3 3 -1 4 0  
Answer: -2 0 3 3 -1 4 0 -2 0 3 3 -1 4 0

Enter the number of dictionary elements: 4  
Enter key: beta 2  
Enter value: Enter key: alpha 5  
Enter value: Enter key: beta 3  
Enter value: Enter key: gamma -1  
Enter value:  
Answer: 7

Enter number of records: 4  
customer = Anna  
address = Lenina 1  
customer = Bob  
address = Mira 2  
customer = Anna  
address = Mira 3  
customer = Bob  
address = Mira 2

Answer:  
Anna
```
## Сборка и запуск

В Visual Studio проект открывается через файл решения (.sln), сборка и запуск осуществляются по Ctrl+F5 (Запуск без отладки).
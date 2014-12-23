int MaxSize;
int size;
int writeindex;
int readindex;
string* Arr;
public:
queue(int MaxSize); //Конструктор
~queue(); //Деструктор
bool putstr (string str);
bool getstr (string* container);
friend istream& operator >>(istream& in, queue& q); //Ввод из std::istream
friend ostream& operator <<(ostream& out, queue& q); //Вывод в std::ostream
int queuesize();
};

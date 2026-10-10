#ifndef RED_H
#define RED_H
class Red {
    public:
    int* data;
    int n;
    int pop;

    Red(int n);
    Red(const Red& drugi);
    ~Red();
    void push(int x);
    int front();
    bool is_full();
    void remove();
    int get_popunjenost();
    bool is_empty();


};

#endif
#ifndef ORDER_H
#define ORDER_H
enum OrderConsts {
    ORDER_SIZE = 10,
    MARK_SIZE = 15,
    ORDERPHONE_SIZE = 12,
    DATE_SIZE = 11,
};
class Order {
private:
    int number{};
    int carnumber{};
    char* mark = new char[MARK_SIZE] {};
    long long int phone{};
    char* date = new char[DATE_SIZE] {};
    char* back_date = new char[DATE_SIZE] {};
public:
    Order();
    void SetNumber(int number1);
    void SetCarnumber(int carnumber1);
    void SetMark(const char* mark1);
    void SetPhone(const long long int phone1);
    void SetDate(const char* date1);
    void SetBackDate(const char* back_date1);
    int GetNumber();
    int GetCarnumber();
    char* GetMark();
    long long int GetPhone();
    char* GetDate();
    char* GetBackDate();
    void print();
    ~Order();
};
#endif


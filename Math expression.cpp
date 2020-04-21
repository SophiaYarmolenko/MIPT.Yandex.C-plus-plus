#include <iostream>
#include <deque>

//with brackets
/*
enum class QueryType {
    Add,
    Minus,
    Mul,
    Division
};

struct Query
{
    QueryType type;
    std::string value;
};

std::istream& operator >> (std::istream& is, Query& q)
{
    std::string typeStr;
    is >> typeStr;
    if (typeStr == "+") {
        q.type = QueryType::Add;
        is >> q.value;
    } else if (typeStr == "-") {
        q.type = QueryType::Minus;
        is >> q.value;
    } else if (typeStr == "*") {
        q.type = QueryType::Mul;
        is >> q.value;
    } else if (typeStr == "/") {
        q.type = QueryType::Division;
        is >> q.value;
    }

    return is;
}

int main() {
    int x;
    std::cin >> x;

    int n;
    std::cin >> n;
    Query q;

    std::deque<std::string> d;
    d.push_back(std::to_string(x));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> q;
        switch (q.type) {
            case QueryType::Add:
                d.push_front("(");
                d.push_back(")");
                d.push_back("+");
                d.push_back(q.value);
                break;
            case QueryType::Minus:
                d.push_front("(");
                d.push_back(")");
                d.push_back("-");
                d.push_back(q.value);
                break;
            case QueryType::Mul:
                d.push_front("(");
                d.push_back(")");
                d.push_back("*");
                d.push_back(q.value);
                break;
            case QueryType::Division:
                d.push_front("(");
                d.push_back(")");
                d.push_back("/");
                d.push_back(q.value);
                break;
        }
    }

    for (auto& item : d) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            std::cout << " " << item << " ";
        } else {
            std::cout << item;
        }
    }

    return 0;
}*/

//without brackets 
enum class QueryType
{
    Add,
    Minus,
    Mul,
    Division
};

struct Query
{
    QueryType type;
    std::string value;
};

std::istream& operator >> (std::istream& is, Query& q)
{
    std::string typeStr;
    is >> typeStr;
    if (typeStr == "+") {
        q.type = QueryType::Add;
        is >> q.value;
    } else if (typeStr == "-") {
        q.type = QueryType::Minus;
        is >> q.value;
    } else if (typeStr == "*") {
        q.type = QueryType::Mul;
        is >> q.value;
    } else if (typeStr == "/") {
        q.type = QueryType::Division;
        is >> q.value;
    }

    return is;
}

int main() {
    int x;
    std::cin >> x;

    int n;
    std::cin >> n;
    Query q;

    std::deque<std::string> d;
    d.push_back(std::to_string(x));
    std::string previous = "*";

    for (int i = 0; i < n; ++i)
    {
        std::cin >> q;
        switch (q.type) {
            case QueryType::Add:
                d.push_back("+");
                d.push_back(q.value);
                previous = "+";
                break;
            case QueryType::Minus:
                d.push_back("-");
                d.push_back(q.value);
                previous = "-";
                break;
            case QueryType::Mul:
                if(previous == "-"||previous == "+")
                {
                    d.push_front("(");
                    d.push_back(")");
                }
                d.push_back("*");
                d.push_back(q.value);
                previous = "*";
                break;
            case QueryType::Division:
                if(previous == "-"||previous == "+")
                {
                    d.push_front("(");
                    d.push_back(")");
                }
                d.push_back("/");
                d.push_back(q.value);
                previous = "/";
                break;
        }
    }

    for (auto& item : d) {
        if (item == "+" || item == "-" || item == "*" || item == "/") {
            std::cout << " " << item << " ";
        } else {
            std::cout << item;
        }
    }

    return 0;
}
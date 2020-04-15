//
// Created by Sophia on 15.04.2020.
//

#pragma once
#include <algorithm>
#include "phone_number.h"
#include <stdexcept>
#include <sstream>
/* Принимает строку в формате +XXX-YYY-ZZZZZZ
       Часть от '+' до первого '-' - это код страны.
       Часть между первым и вторым символами '-' - код города
       Всё, что идёт после второго символа '-' - местный номер.
       Код страны, код города и местный номер не должны быть пустыми.
       Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

       Примеры:
       * +7-495-111-22-33
       * +7-495-1112233
       * +323-22-460002
       * +1-2-coursera-cpp
       * 1-2-333 - некорректный номер - не начинается на '+'
       * +7-1233 - некорректный номер - есть только код страны и города
    */
PhoneNumber::PhoneNumber(const string &international_number)
{

    istringstream is(international_number);

    char sign = is.get();
    getline(is, country_code_, '-');
    getline(is, city_code_, '-');
    getline(is, local_number_);

    if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
        throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
    }

}
string PhoneNumber::GetCountryCode() const
{
    return this->country_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return this->local_number_;
}

string PhoneNumber::GetCityCode() const
{
    return this->city_code_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return ('+'+this->country_code_+'-'+this->city_code_+'-'+this->local_number_);
}

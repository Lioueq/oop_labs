#include <map>
#include "../include/lab1.h"

std::map <int, std::string> unit_map = {
    {0, "sıfır"},
    {1, "bir"},
    {2, "iki"},
    {3, "üç"},
    {4, "dört"},
    {5, "beş"},
    {6, "altı"},
    {7, "yedi"},
    {8, "sekiz"},
    {9, "dokuz"}
};

std::map <int, std::string> ten_map = {
    {1, "on"},
    {2, "yirmi"},
    {3, "otuz"},
    {4, "kırk"},
    {5, "elli"},
    {6, "altmış"},
    {7, "yetmiş"},
    {8, "seksen"},
    {9, "doksan"}
};

std::string converse(int n) {
    int ten = n / 10;
    int unit = n % 10;
    if (n > 0) {
        std::string ans1 = ten ? ten_map[ten] : "";
        std::string ans2 = unit ? unit_map[unit] : "";
        return std::size(ans1) ? ans1 + " " + ans2 : ans2;
    }
    return unit_map[n];
}